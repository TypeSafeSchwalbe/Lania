
#include "stages.h"
#include "content/nature.h"
#include "content/humans.h"
#include "content/goblins.h"
#include "content/elves.h"
#include "../engine/sequences.h"


#define MFST &SCENE_TILE_MAGICAL_FOREST
#define MMDW &SCENE_TILE_MAGICAL_MEADOW
#define MWTR &SCENE_TILE_MAGICAL_WATER
#define EVHT &SCENE_TILE_ELVEN_VILLAGE_HUT

IMPL_STAGE(ELVEN_VILLAGE, elven_village, ((const SceneTile**[]) {
    (const SceneTile*[]) { MFST, MFST, MFST, MWTR, MFST, MFST, MFST, MFST, MFST, MFST, MFST },
    (const SceneTile*[]) { MFST, MFST, MFST, MWTR, EVHT, MMDW, MMDW, EVHT, MFST, MFST, MFST },
    (const SceneTile*[]) { MMDW, MMDW, MFST, MWTR, MWTR, MMDW, MMDW, MMDW, MMDW, MFST, MFST },
    (const SceneTile*[]) { MMDW, MMDW, MMDW, MFST, MWTR, MFST, MMDW, MMDW, MMDW, MMDW, MFST },
    (const SceneTile*[]) { MFST, MMDW, MMDW, EVHT, MWTR, EVHT, MMDW, MMDW, MMDW, MMDW, MFST },
    (const SceneTile*[]) { MFST, MFST, MMDW, MMDW, MWTR, MFST, MMDW, MMDW, MWTR, MMDW, MFST },
    (const SceneTile*[]) { MFST, MFST, MMDW, MMDW, MWTR, MMDW, MMDW, MWTR, MWTR, MMDW, MMDW },
    (const SceneTile*[]) { MFST, MFST, MFST, MMDW, MMDW, MMDW, EVHT, MWTR, MFST, MMDW, MMDW },
    (const SceneTile*[]) { MFST, MFST, MFST, MFST, MMDW, MMDW, MFST, MWTR, EVHT, MFST, MFST },
    (const SceneTile*[]) { MFST, MFST, MFST, EVHT, MMDW, EVHT, MFST, MWTR, MFST, MFST, MFST },
    (const SceneTile*[]) { MFST, MFST, MFST, MFST, MFST, MFST, MFST, MWTR, MFST, MFST, MFST }
}), 11, 11, FOG_DISABLED, COMMANDER_OBREG, {
    scene_focus_on_tile(&self, 1, 3);

    stage_summon_troops(&self, 1, 3, &ENTITY_SCOUT, 6);
    stage_summon_troops(&self, 2, 4, &ENTITY_SCOUT, 6);
    stage_summon_troops(&self, 4, 8, &ENTITY_KNIGHT, 20);
    stage_summon_troops(&self, 5, 8, &ENTITY_KNIGHT, 20);

    stage_summon_troops(&self, 7, 4, &ENTITY_SPEAR_GOBLIN, 6);
    stage_summon_troops(&self, 5, 1, &ENTITY_GOBLIN, 5);
    stage_summon_troops(&self, 6, 1, &ENTITY_GOBLIN, 5);
    
    stage_summon_troops(&self, 9, 4, &ENTITY_SPEAR_GOBLIN, 6);
    stage_summon_troops(&self, 10, 6, &ENTITY_GOBLIN, 5);
    stage_summon_troops(&self, 9, 7, &ENTITY_GOBLIN, 5);
}, "Elven Village <!Rework planned!>",
    "Continue the counter-invasion of the goblin realm by\n"
    "taking control of the elven village in the west of the goblin realm."
);