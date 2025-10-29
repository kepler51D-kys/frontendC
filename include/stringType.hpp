#ifndef STRINGTYPE_H
#define STRINGTYPE_H
#include <sys/types.h>
#include <SDL3/SDL_stdinc.h>

typedef struct {
    char* string;
    Uint32 textLen;
    Uint32 maxLen;
} string;

typedef struct {
    char32_t* string;
    Uint32 textLen;
    Uint32 maxLen;
} ustring;

string string_init(Uint32 len, char* stringData);
string string_lazyInit(char* stringData);
string string_copy(string src);

ustring ustring_init(Uint32 len, char* stringData);
ustring ustring_lazyInit(char* stringData);
ustring ustring_copy(ustring src);

#endif