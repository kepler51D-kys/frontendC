#include <stdio.h>
// #include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

#include "../include/sockets.h"

int StartConnection(char* address, char* port) {
    int sock = 0;
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_STREAM; // TCP

    if (getaddrinfo(address, port, &hints, &res) != 0) {
        perror("getaddrinfo failed");
        return -1;
    }

    if ((sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) < 0) {
        perror("Socket creation error");
        freeaddrinfo(res);
        return -1;
    }

    if (connect(sock, res->ai_addr, res->ai_addrlen) < 0) {
        perror("Connection failed");
        freeaddrinfo(res);
        return -1;
    }

    freeaddrinfo(res);
    return sock;
}

void communicate(int sock) {
    char buffer[BUFFER_SIZE] = {0};
    char message[BUFFER_SIZE];
    
    while (1) {
        printf("Enter message to send: ");
        fgets(message, BUFFER_SIZE, stdin);
        
        send(sock, message, strlen(message), 0);
        printf("Message sent\n");

        memset(buffer, 0, BUFFER_SIZE);
        read(sock, buffer, BUFFER_SIZE);
        printf("Message from server: %s\n", buffer);
    }

    close(sock);
}