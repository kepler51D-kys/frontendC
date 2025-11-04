#include "GPUManager.h"
#include <SDL3/SDL_gpu.h>
#include <SDL3/SDL_hints.h>
#include "stdio.h"

bool gpuInit(SDL_GPUDevice **device, SDL_Window *window) {
    *device = SDL_CreateGPUDevice(SDL_GPU_SHADERFORMAT_SPIRV, true, "vulkan");
    if (device == NULL) {
        printf("gpu device init failed\n");
        return false;
    }
    bool success = SDL_ClaimWindowForGPUDevice(*device, window);
    return success;
}