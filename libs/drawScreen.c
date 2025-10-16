#include "drawScreen.h"
#include "data.h"
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_stdinc.h>
#include <stdbool.h>
#include <stdio.h>
#include "renderer.h"
#include "serverManager.h"

const vec2 windowMinSize = Vec2(750, 500);

const Uint32 widthToCollapseAdditionPanel = 1000;
const Uint32 widthToCollapseChannelPanel = 800;

const SDL_Color channelPanelColour = {255,255,255,255};
const Uint32 channelPanelWidth = 300;
const Uint32 channelPanelSmallWidth = 60;

const SDL_Color textPanelColour = {255,255,255,255};
const Uint32 textPanelHeight = 100;

const SDL_Color settingsPanelColour = {255,255,255,255};
const Uint32 settingsPanelHeight = 40;

const SDL_Color messagePanelColour = {255,255,255,255};

const SDL_Color additionPanelColour = {255,255,255,255};
const Uint32 additionPanelWidth = 300;

const Uint32 serverDisplayBaseHeight = 60;


// draw channelPanel
void DrawChannelPanel(session *info, vec2 screenSize, SDL_Renderer* renderer) {
    Uint32 panelWidth = screenSize.x > widthToCollapseChannelPanel ? channelPanelWidth : channelPanelSmallWidth;
    SDL_FRect base = {
        0,
        0,
        panelWidth,
        screenSize.y
    };
    SDL_SetRenderDrawColor(renderer, channelPanelColour.r,channelPanelColour.g,channelPanelColour.b,channelPanelColour.a);
    SDL_RenderRect(renderer, &base);
    
    // printf("%d %d %d\n",info->channelPanelInfo.scroll, (int)serverDisplayBaseHeight*(int)info->serverLen, info->serverLen);
    if (info->channelPanelInfo.scroll-screenSize.y < -(int)serverDisplayBaseHeight*(int)info->serverLen) {
        info->channelPanelInfo.scroll = -(int)serverDisplayBaseHeight*(int)info->serverLen+screenSize.y;
    }
    else if (info->channelPanelInfo.scroll > 0) {
        info->channelPanelInfo.scroll = 0;
    }
    SDL_FRect serverDisplayBase = {
        0,info->channelPanelInfo.scroll,panelWidth,serverDisplayBaseHeight
    };
    for (; serverDisplayBase.y < screenSize.y; serverDisplayBase.y+=serverDisplayBaseHeight) {
        SDL_RenderLine(renderer, 0, serverDisplayBase.y, panelWidth, serverDisplayBase.y);
        serverDisplayBase.y = serverDisplayBase.y;
    }
    int i = 0;
    SDL_Texture *icon;
    for (int y = info->channelPanelInfo.scroll; y < screenSize.y && i < info->serverLen; y+=serverDisplayBaseHeight) {
        if (y+serverDisplayBaseHeight >= 0) {
            if (!info->servers[i].iconCache) {
                icon = getImg(renderer, info->servers[i].iconPath.string);
            }
            else {
                icon = info->servers[i].iconCache;
            }
            SDL_FRect iconRect = {0,i*serverDisplayBaseHeight+info->channelPanelInfo.scroll,serverDisplayBaseHeight,serverDisplayBaseHeight};
            SDL_RenderTexture(renderer, icon, NULL, &iconRect);
        }
        i++;
    }
}

// draw textPanel
void DrawTextPanel(vec2 screenSize, SDL_Renderer* renderer) {
    Uint32 width = screenSize.x > widthToCollapseChannelPanel ? channelPanelWidth : channelPanelSmallWidth;
    Uint32 end = screenSize.x > widthToCollapseAdditionPanel ? additionPanelWidth : 0;
    SDL_FRect base = {
        width,
        screenSize.y-textPanelHeight,
        screenSize.x < widthToCollapseAdditionPanel ? screenSize.x-width-end : screenSize.x-width-end,
        textPanelHeight
    };
    SDL_SetRenderDrawColor(renderer, textPanelColour.r,textPanelColour.g,textPanelColour.b,textPanelColour.a);
    SDL_RenderRect(renderer, &base);
}

// draw settings panel
void DrawSettingsPanel(vec2 screenSize, SDL_Renderer* renderer) {
    Uint32 width = screenSize.x > widthToCollapseChannelPanel ? channelPanelWidth : channelPanelSmallWidth;
    Uint32 end = screenSize.x > widthToCollapseAdditionPanel ? additionPanelWidth : 0;
    SDL_FRect base = {
        width,
        0,
        screenSize.x < widthToCollapseAdditionPanel ? screenSize.x-width-end : screenSize.x-width-end,
        settingsPanelHeight
    };
    SDL_SetRenderDrawColor(renderer, settingsPanelColour.r,settingsPanelColour.g,settingsPanelColour.b,settingsPanelColour.a);
    SDL_RenderRect(renderer, &base);
}

// draw messagePanel
void DrawMessagePanel(vec2 screenSize, SDL_Renderer* renderer) {
    float width = screenSize.x > widthToCollapseChannelPanel ? channelPanelWidth : channelPanelSmallWidth;
    Uint32 end = screenSize.x > widthToCollapseAdditionPanel ? additionPanelWidth : 0;
    SDL_FRect base = {
        width,
        settingsPanelHeight,
        screenSize.x < widthToCollapseAdditionPanel ? screenSize.x-width-end : screenSize.x-width-end,
        screenSize.y-settingsPanelHeight
    };
    SDL_SetRenderDrawColor(renderer, messagePanelColour.r,messagePanelColour.g,messagePanelColour.b,messagePanelColour.a);
    SDL_RenderRect(renderer, &base);
}

// draw addition panel
void DrawAdditionPanel(vec2 screenSize, SDL_Renderer* renderer) {
    if (screenSize.x > 1000) {
        SDL_FRect base = {
            screenSize.x-additionPanelWidth,
            0,
            additionPanelWidth,
            screenSize.y
        };
        SDL_SetRenderDrawColor(renderer, additionPanelColour.r,additionPanelColour.g,additionPanelColour.b,additionPanelColour.a);
        SDL_RenderRect(renderer, &base);
    }
}
