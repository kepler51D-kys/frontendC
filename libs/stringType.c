#include "stringType.h"
#include <stdlib.h>
#include <string.h>
#include <uchar.h>

string string_copy(string src) {
    string ret;
    ret.maxLen = src.maxLen;
    ret.textLen = src.textLen;
    ret.string = malloc(ret.maxLen*sizeof(char));
    memcpy(ret.string, src.string, ret.textLen*sizeof(char));
    ret.string[ret.textLen] = '\0';
    return ret;
}

string string_init(Uint32 len, char* stringData) {
    string ret;
    ret.string = malloc(len*sizeof(char));
    memcpy(ret.string, stringData, len*sizeof(char));
    ret.maxLen = len;
    ret.textLen = len;
    return ret;
}
string string_lazyInit(char* stringData) {
    Uint32 len;
    for (len = 1; stringData[len] != '\0'; len++);
    string ret;
    ret.string = malloc(len*sizeof(char));
    memcpy(ret.string, stringData, len*sizeof(char));
    ret.maxLen = len;
    ret.textLen = len;
    return ret;
}

ustring ustring_copy(ustring src) {
    ustring ret;
    ret.maxLen = src.maxLen;
    ret.textLen = src.textLen;
    ret.string = malloc(ret.maxLen * sizeof(char32_t));
    memcpy(ret.string, src.string, ret.textLen*sizeof(char32_t));
    ret.string[ret.textLen] = '\0';
    return ret;
}

ustring ustring_init(Uint32 len, char* stringData) {
    ustring ret;
    ret.string = malloc(len*sizeof(char32_t));
    memcpy(ret.string, stringData, len*sizeof(char32_t));
    ret.maxLen = len;
    ret.textLen = len;
    return ret;
}
ustring ustring_lazyInit(char* stringData) {
    Uint32 len;
    for (len = 0; stringData[len] != '\0'; len++);
    ustring ret;
    ret.string = malloc(len*sizeof(char32_t));
    memcpy(ret.string, stringData, len*sizeof(char32_t));
    ret.maxLen = len;
    ret.textLen = len;
    return ret;
}