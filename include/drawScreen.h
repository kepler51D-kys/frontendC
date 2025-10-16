#ifndef DRAWSCREEN_H
#define DRAWSCREEN_H
#include <SDL3/SDL_render.h>
#include "data.h"
#include "renderer.h"

extern const vec2 windowMinSize;

void DrawChannelPanel(session *info, vec2 screenSize, SDL_Renderer* renderer);
void DrawTextPanel(vec2 screenSize, SDL_Renderer* renderer);
void DrawMessagePanel(vec2 screenSize, SDL_Renderer* renderer);
void DrawSettingsPanel(vec2 screenSize, SDL_Renderer* renderer);
void DrawAdditionPanel(vec2 screenSize, SDL_Renderer* renderer);
#endif