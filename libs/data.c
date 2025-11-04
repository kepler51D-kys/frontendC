#include "data.h"


const SDL_Color black = {0,0,0,255};
const SDL_Color white = {255,255,255,255};
const SDL_Color green = {0,255,0,255};
const SDL_Color red = {255,0,0,255};
const SDL_Color blue = {0,0,255,255};
const SDL_Color pink = {183,43,206,255};
const SDL_Color purple = {255,0,255,255};


const SDL_Color transparent = {0,0,0,0};



const vec2 zero = {0,0};

vec2 vec2_add(vec2 a, vec2 b) {
    return Vec2(a.x + b.x, a.y + b.y);
}
vec2 vec2_sub(vec2 a, vec2 b) {
    return Vec2(a.x - b.x, a.y - b.y);
}
vec2 vec2_mult(vec2 a, float b) {
    return Vec2(a.x * b, a.y * b);
}
vec2 vec2_div(vec2 a, float b) {
    return Vec2(a.x / b, a.y / b);
}
vec2 vec2_looseMax(vec2 a, vec2 b) {
    return Vec2(a.x > b.x ? a.x : b.x,a.y > b.y ? a.y : b.y);
}
vec2 vec2_looseMin(vec2 a, vec2 b) {
    return Vec2(a.x < b.x ? a.x : b.x,a.y < b.y ? a.y : b.y);
}