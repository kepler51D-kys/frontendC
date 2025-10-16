#include "serverManager.h"
#include "stringType.h"
#include <stdio.h>
#include <string.h>

Uint32 getServers(server *servers) {
    Uint32 len = readCache(servers);
    return len;


    // utilise connection
    // send code 0 along with profile code and verification key
    // recieve channels and convert
}

char line[512];
Uint32 readCache(server *servers) {
    FILE *file = fopen("../assets/.programcache/servers","rb");
    Uint32 maxSize = 2;
    Uint32 size = 0;
    
    for (; fgets(line,512,file);) {
        server newServer;

        for (int i = 0; line[i] != '\0' && i < 512; i++) {
            if (line[i] == ':' || line[i] == '\n') {
                line[i] = '\0';
            }
        }
        // printf("%s\n",line+7);
        newServer.address = *line;
        Uint16 port = *(line+4);
        newServer.name = ustring_lazyInit(line+7);
        int channelCacheStart = strlen(line+7) + 8;
        string chanelCache = string_lazyInit(line+channelCacheStart);
        int iconPathStart = strlen(line+channelCacheStart)+channelCacheStart+1;

        newServer.iconPath = string_lazyInit(line+iconPathStart);
        newServer.iconCache = NULL;
        servers[size++] = newServer;
    }
    // printf("size %d\n",size);
    // printf("%s\n",servers[0].iconPath.string);
    return size;
}