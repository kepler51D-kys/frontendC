#ifndef PROFILEMANAGER_H
#define PROFILEMANAGER_H
#include <SDL3/SDL_stdinc.h>
#include "stringType.h"
#include <stdbool.h>

typedef struct {
    Uint64 key;
    string password;
} verification;

verification getKeyPassword();

bool verifyPasswordQuality(char* password);
#endif