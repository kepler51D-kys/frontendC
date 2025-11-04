#ifndef CHANNELMANAGER_H
#define CHANNELMANAGER_H
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_stdinc.h>
#include "stringType.h"

typedef struct {
    string iconPath;
    ustring name;
    Uint32 address; //IPv4
    SDL_Texture *iconCache;
} server;

Uint32 getServers(server *servers);
Uint32 readCache(server *servers);
#endif