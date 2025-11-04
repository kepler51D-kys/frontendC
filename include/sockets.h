#ifndef socketsC
#define socketsC

#define BUFFER_SIZE 1024

int StartConnection(char* address, char* port);

void communicate(int sock);

#endif