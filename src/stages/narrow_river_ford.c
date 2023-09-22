
#include "stages.h"
#include "content/nature.h"
#include "content/humans.h"
#include "content/goblins.h"
#include "content/elves.h"
#include "../engine/sequences.h"


#define MFST &SCENE_TILE_MAGICAL_FOREST
#define MMDW &SCENE_TILE_MAGICAL_MEADOW
#define MWTR &SCENE_TILE_MAGICAL_WATER
#define FORD &SCENE_TILE_FORD

IMPL_STAGE(NARROW_RIVER_FORD, narrow_river_ford, ((const SceneTile**[]) {
    (const SceneTile*[]) { MFST, MFST, MFST, MFST, MFST, MWTR, MFST, MFST, MFST, MFST, MFST },
    (const SceneTile*[]) { MFST, MFST, MFST, MFST, MMDW, MWTR, MFST, MFST, MFST, MFST, MFST },
    (const SceneTile*[]) { MFST, MFST, MFST, MMDW, MMDW, MWTR, MMDW, MFST, MFST, MMDW, MMDW },
    (const SceneTile*[]) { MFST, MFST, MMDW, MMDW, MMDW, MWTR, MMDW, MMDW, MMDW, MMDW, MMDW },
    (const SceneTile*[]) { MFST, MFST, MMDW, MMDW, MMDW, MWTR, MMDW, MMDW, MMDW, MMDW, MFST },
    (const SceneTile*[]) { MFST, MMDW, MMDW, MMDW, MMDW, FORD, MMDW, MMDW, MMDW, MMDW, MFST },
    (const SceneTile*[]) { MFST, MMDW, MMDW, MMDW, MMDW, MWTR, MMDW, MMDW, MMDW, MFST, MFST },
    (const SceneTile*[]) { MMDW, MMDW, MMDW, MMDW, MMDW, MWTR, MMDW, MMDW, MMDW, MFST, MFST },
    (const SceneTile*[]) { MMDW, MMDW, MFST, MFST, MMDW, MWTR, MMDW, MMDW, MFST, MFST, MFST },
    (const SceneTile*[]) { MFST, MFST, MFST, MFST, MFST, MWTR, MMDW, MFST, MFST, MFST, MFST },
    (const SceneTile*[]) { MFST, MFST, MFST, MFST, MFST, MWTR, MFST, MFST, MFST, MFST, MFST }
}), 11, 11, COMMANDER_OBREG, {
    scene_focus_on_tile(&self, 1, 7);

    stage_summon_troops(&self, 2, 6, &ENTITY_DIGGER, 8);
    stage_summon_troops(&self, 1, 7, &ENTITY_KNIGHT, 15);

    stage_summon_troops(&self, 6, 2, &ENTITY_SPEAR_GOBLIN, 5);

    stage_summon_troops(&self, 6, 9, &ENTITY_SPEAR_GOBLIN, 5);

    stage_summon_troops(&self, 9, 3, &ENTITY_GOBLIN, 5);
    stage_summon_troops(&self, 8, 4, &ENTITY_GOBLIN, 5);
    stage_summon_troops(&self, 8, 6, &ENTITY_GOBLIN, 5);
}, "Narrow River Ford",
    "On your way through the enchanted forest you encounter a river.\n"
    "Although there is a ford to cross it, not many of your troops can do so\n"
    "at the same time."
);