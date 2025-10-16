#include "drawScreen.h"
#include <SDL3/SDL_error.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_timer.h>
#include <SDL3/SDL_video.h>
#include <SDL3_image/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL_main.h>
#include "renderer.h"

SDL_AppResult SDL_AppInit(void **appstate, int argc, char **argv) {
    *appstate = malloc(sizeof(session));
    session* state = *appstate;
    state->servers = malloc(sizeof(server)*64);
    state->serverLen = readCache(state->servers);
    state->info = getKeyPassword();
    state->channelPanelInfo.scroll = 0;
    // printf("%ld\n",info.key);
    // printf("%s\n",info.password.string);

    if (allInit(&state->window,&state->renderer, &state->font, &state->device,"../assets/fonts/COMIC.TTF",Vec2(960,540))) {
        printf("failed SDL init\n");
        return SDL_APP_FAILURE;
    }
    SDL_SetWindowMinimumSize(state->window, windowMinSize.x, windowMinSize.y);
    // SDL_SetWindowResizable(state->window, true);
    // SDL_SetWindowFocusable(state->window, true);
    redraw(state);
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate) {
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
    session* state = (session*)appstate;
    switch (event->type) {
        case SDL_EVENT_MOUSE_WHEEL:
            state->channelPanelInfo.scroll += event->wheel.y*25;
            if (deltaTimeMS() > 1000/maxFPS) {
                redraw(state);
                time = SDL_GetTicks();
            }
            break;
        case SDL_EVENT_WINDOW_DESTROYED:
            return SDL_APP_FAILURE;
            break;
        case SDL_EVENT_KEY_DOWN:
            printf("%c\n",event->key.key);
            break;
        case SDL_EVENT_WINDOW_RESIZED:
            if (deltaTimeMS() > 1000/maxFPS) {
                time = SDL_GetTicks();
                redraw(state);
            }
            break;
        case SDL_EVENT_QUIT:
            return SDL_APP_FAILURE;
            break;
    }
    // SDL_Delay(1000/maxFPS);
    return SDL_APP_CONTINUE;
}
void SDL_AppQuit(void *appstate, SDL_AppResult result) {
    session* state = (session*)appstate;
    
    SDL_DestroyGPUDevice(state->device);
    SDL_DestroyRenderer(state->renderer);
    SDL_DestroyWindow(state->window);
    SDL_Quit();
}