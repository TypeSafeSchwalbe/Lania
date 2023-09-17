
#pragma once


typedef struct SaveGame {
    unsigned long unlocked_stages;
} SaveGame;

SaveGame load_savegame();

void store_savegame(SaveGame* savegame);