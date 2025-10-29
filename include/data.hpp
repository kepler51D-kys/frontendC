#ifndef DATA_H
#define DATA_H

#include <SDL3/SDL_pixels.h>

typedef struct {
    float x;
    float y;
} vec2;

typedef struct {
    vec2 start;
    vec2 size;
} bounds;

#define Vec2(x,y) (vec2){x,y}
#define Bounds(start,size) (bounds){start,size}

extern const SDL_Color black;
extern const SDL_Color white;
extern const SDL_Color green;
extern const SDL_Color red;
extern const SDL_Color blue;
extern const SDL_Color pink;
extern const SDL_Color purple;

extern const SDL_Color transparent;

extern const vec2 zero;

#define colour(r,g,b) (SDL_Color){r,g,b,255}

vec2 vec2_add(vec2 a, vec2 b);
vec2 vec2_sub(vec2 a, vec2 b);
vec2 vec2_mult(vec2 a, float b);
vec2 vec2_div(vec2 a, float b);
vec2 vec2_looseMax(vec2 a, vec2 b);
vec2 vec2_looseMin(vec2 a, vec2 b);
#endif