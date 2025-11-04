#include "profileManager.h"
// #include "SDL_stdinc.h"
#include "stringType.h"
#include <stdio.h>

verification getKeyPassword() {
    verification ret;
    
    FILE *f = fopen("../assets/.programcache/profile", "rb");
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);

    // char *filestring = malloc(fsize + 1);
    char filestring[58];
    fread(filestring, fsize, 1, f);
    fclose(f);

    filestring[fsize] = '\0';
    
    char* keyArr = filestring;
    char* password = filestring+8;

    ret.password = string_lazyInit(password);
    ret.key = *(Uint64*)keyArr;

    // free(filestring);
    return ret;
}

bool verifyPasswordQuality(char* password) {
    int len;
    bool hasNumbers;
    bool hasCapitals;
    bool hasLower;
    bool hasSymbols;
    for (len = 0; password[len] != '\0'; len++) {
        hasLower |= password[len] >= 'a' && password[len] <= 'z';
        hasNumbers |= password[len] >= '0' && password[len] <= '9';
        hasCapitals |= password[len] >= 'A' && password[len] <= 'Z';
        
        hasSymbols |= password[len] >= ' ' && password[len] <= '/';
        hasSymbols |= password[len] >= ':' && password[len] <= '@';
        hasSymbols |= password[len] >= '[' && password[len] <= '`';
        hasSymbols |= password[len] >= '{' && password[len] <= '~';
    }
    return hasSymbols && hasNumbers && hasLower && hasCapitals && len > 10 && len <= 50;
}