#ifndef renderer_H
#define renderer_H

#include "SDL3/SDL_render.h"
#include "SDL3/SDL_video.h"
#include "data.h"
#include "panelInfo.h"
#include <SDL3/SDL_gpu.h>
#include <SDL3/SDL_stdinc.h>
#include <SDL3_ttf/SDL_ttf.h>

typedef struct {
    SDL_Window *window;
    SDL_Renderer *renderer;
    TTF_Font *font;
    Uint32 serverLen;
    channelPanelInfo channelPanelInfo;
} session;

extern Uint8 maxFPS;

extern Uint32 time;

int allInit(SDL_Window** window, SDL_Renderer** renderer, TTF_Font** font, SDL_GPUDevice** device, char* fontFile, vec2 windowSize);

SDL_Texture* getImg(SDL_Renderer* renderer, char* name);

Uint32 deltaTimeMS();

vec2 getScreenSize(SDL_Window* window);

void redraw(session* state);
#endif
