#include "renderer.h"
#include "drawScreen.h"
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_gpu.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_video.h>
#include <SDL3_image/SDL_image.h>
#include <SDL3_ttf/SDL_ttf.h>
#include <stdbool.h>
#include <stdio.h>
#include "GPUManager.h"

Uint8 maxFPS = 60;

Uint32 time = 0;


int allInit(SDL_Window** window, SDL_Renderer** renderer, TTF_Font** font, SDL_GPUDevice** device, char* fontFile, vec2 windowSize) {
    if (!SDL_CreateWindowAndRenderer("client", windowSize.x, windowSize.y, SDL_WINDOW_RESIZABLE, window, renderer)) {
        SDL_Log("Couldn't create window and renderer: %s\n", SDL_GetError());
        return 1;
    }
    // if (!gpuInit(device, *window)) {
    //     printf("gpu init failed\n");
    //     printf("%s\n",SDL_GetError());
    //     SDL_Quit();
    //     return 1;
    // }
    
    if (!TTF_Init()) {
        printf("ttf init failed\n");
        SDL_Quit();
        SDL_DestroyGPUDevice(*device);
        return 1;
    }
    
    *font = TTF_OpenFont(fontFile, 24);
    if (*font == NULL) {
        *font = TTF_OpenFont("../assets/fonts/COMIC.TTF", 24);
        if (*font == NULL) {
            printf("failed font init\n");
            printf("%s\n", SDL_GetError());
            TTF_Quit();
            SDL_Quit();
            return 1;
        }
    }
    return 0;
}
SDL_Texture* getImg(SDL_Renderer* renderer, char* name) {
    SDL_Surface* surface = IMG_Load(name);
    if (!surface) {
        return NULL;
    }
    // return NULL;
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_DestroySurface(surface);
    if (!texture) {
        return NULL;
    }
    return texture;
}
void redraw(session* state) {
    SDL_SetRenderDrawColor(state->renderer, 100, 80, 100, 255);
    SDL_RenderClear(state->renderer);
    
    vec2 size = getScreenSize(state->window);
    DrawMessagePanel(size,state->renderer);
    DrawChannelPanel(state, size,state->renderer);
    DrawTextPanel(size,state->renderer);
    DrawSettingsPanel(size,state->renderer);
    DrawAdditionPanel(size, state->renderer);

    SDL_RenderPresent(state->renderer);
    SDL_Delay(1000/maxFPS);
}
Uint32 deltaTimeMS() {
    return SDL_GetTicks() - time;
}
vec2 getScreenSize(SDL_Window* window) {
    int x,y;
    SDL_GetWindowSize(window, &x, &y);
    return Vec2(x,y);
}