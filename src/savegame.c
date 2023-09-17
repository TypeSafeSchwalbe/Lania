
#include <stdio.h>

#include "savegame.h"


#define FILE_LOCATION "savegame"

#define freadd(T, fptr) *((T*) *fptr); *fptr += sizeof(T);

SaveGame load_savegame() {
    FILE* f = fopen(FILE_LOCATION, "rb");
    if(f == NULL) { return (SaveGame) {
        .unlocked_stages = 1
    }; }
    fseek(f, 0, SEEK_END);
    size_t fsize = ftell(f);
    fseek(f, 0, SEEK_SET);

    char fcontent[fsize];
    fread(fcontent, fsize, 1, f);
    fclose(f);

    char* fptr = fcontent;
    SaveGame loaded;
    loaded.unlocked_stages = freadd(unsigned long, &fptr);
    return loaded;
}

void fprintr(FILE* f, void* d, size_t s) {
    for(size_t o = 0; o < s; o += 1) {
        fprintf(f, "%c", ((char*) d)[o]);
    }
}

void store_savegame(SaveGame* savegame) {
    FILE* f = fopen(FILE_LOCATION, "wb");
    fprintr(f, &savegame->unlocked_stages, sizeof(unsigned long));
    fclose(f);
}