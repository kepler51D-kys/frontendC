#ifndef GPUMANAGER_H
#define GPUMANAGER_H
#include <SDL3/SDL_gpu.h>

bool gpuInit(SDL_GPUDevice **device, SDL_Window *window);
#endif