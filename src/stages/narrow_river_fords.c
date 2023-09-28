
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

IMPL_STAGE(NARROW_RIVER_FORDS, narrow_river_fords, ((const SceneTile**[]) {
    (const SceneTile*[]) { MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MWTR, MWTR },
    (const SceneTile*[]) { MMDW, MMDW, MFST, MMDW, MMDW, MMDW, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MWTR, MWTR },
    (const SceneTile*[]) { MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MWTR, MWTR, MWTR },
    (const SceneTile*[]) { MFST, MMDW, MMDW, MMDW, MFST, MMDW, MMDW, MWTR, MWTR, MWTR, MFST, MFST, MFST, MFST, MFST, MFST, MWTR, MWTR, MWTR, MFST },
    (const SceneTile*[]) { MFST, MMDW, MMDW, MFST, MFST, MWTR, FORD, MWTR, MFST, MWTR, MWTR, MWTR, MFST, MWTR, MWTR, MWTR, MWTR, MWTR, MFST, MFST },
    (const SceneTile*[]) { MFST, MMDW, MMDW, MFST, MWTR, MWTR, MMDW, MMDW, MMDW, MMDW, MMDW, MWTR, MWTR, MWTR, MFST, MFST, MWTR, MFST, MFST, MFST },
    (const SceneTile*[]) { MFST, MMDW, MFST, MFST, MWTR, MMDW, MMDW, MFST, MFST, MFST, MMDW, MMDW, MFST, MFST, MFST, MFST, MWTR, MFST, MFST, MFST },
    (const SceneTile*[]) { MFST, MMDW, MFST, MFST, MWTR, MMDW, MMDW, MFST, MFST, MFST, MFST, MMDW, MFST, MFST, MFST, MFST, MWTR, MFST, MFST, MFST },
    (const SceneTile*[]) { MFST, MMDW, MFST, MFST, MWTR, MMDW, MMDW, MFST, MFST, MFST, MFST, MMDW, MFST, MFST, MFST, MWTR, MWTR, MFST, MFST, MFST },
    (const SceneTile*[]) { MFST, MMDW, MMDW, MWTR, MWTR, MMDW, MMDW, MMDW, MFST, MFST, MFST, MMDW, MFST, MFST, MFST, MWTR, MFST, MFST, MFST, MFST },
    (const SceneTile*[]) { MFST, MMDW, MMDW, MWTR, MFST, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MFST, MFST, MWTR, MWTR, MFST, MFST, MFST, MFST },
    (const SceneTile*[]) { MFST, MMDW, MMDW, MWTR, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MFST, MFST, MWTR, MWTR, MFST, MFST, MFST, MFST, MFST },
    (const SceneTile*[]) { MFST, MMDW, MMDW, MWTR, MFST, MMDW, MMDW, MFST, MFST, MWTR, FORD, MWTR, MWTR, MWTR, MFST, MFST, MFST, MFST, MFST, MFST },
    (const SceneTile*[]) { MFST, MMDW, MMDW, MWTR, MFST, MFST, MMDW, MWTR, MWTR, MWTR, MMDW, MMDW, MFST, MFST, MFST, MMDW, MMDW, MMDW, MFST, MFST },
    (const SceneTile*[]) { MFST, MMDW, MMDW, MWTR, MWTR, MWTR, MWTR, MWTR, MFST, MFST, MMDW, MMDW, MFST, MMDW, MMDW, MMDW, MFST, MMDW, MMDW, MMDW },
    (const SceneTile*[]) { MFST, MMDW, MWTR, MWTR, MWTR, MFST, MFST, MFST, MFST, MFST, MMDW, MMDW, MMDW, MMDW, MFST, MFST, MFST, MMDW, MMDW, MMDW },
    (const SceneTile*[]) { MFST, MWTR, MWTR, MWTR, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MMDW, MMDW, MMDW, MFST, MFST, MMDW, MMDW, MMDW, MFST },
    (const SceneTile*[]) { MFST, MWTR, MWTR, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MFST, MFST },
    (const SceneTile*[]) { MWTR, MWTR, MWTR, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MMDW, MMDW, MMDW, MMDW, MFST, MFST, MFST },
    (const SceneTile*[]) { MWTR, MWTR, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST }
}), 20, 20, FOG_ENABLED, COMMANDER_OBREG, {
    scene_focus_on_tile(&self, 1, 2);

    stage_summon_troops(&self, 1, 2, &ENTITY_ARCHER, 10);
    stage_summon_troops(&self, 2, 2, &ENTITY_KNIGHT, 20);
    stage_summon_troops(&self, 1, 3, &ENTITY_KNIGHT, 20);
    stage_summon_troops(&self, 2, 3, &ENTITY_SCOUT, 3);

    stage_summon_troops(&self, 5, 8, &ENTITY_GOBLIN, 20);
    stage_summon_troops(&self, 6, 9, &ENTITY_SPEAR_GOBLIN, 10);
    stage_summon_troops(&self, 5, 10, &ENTITY_GOBLIN, 20);
    stage_summon_troops(&self, 7, 10, &ENTITY_GOBLIN, 20);
    stage_summon_troops(&self, 6, 11, &ENTITY_SPEAR_GOBLIN, 10);
    stage_summon_troops(&self, 5, 12, &ENTITY_GOBLIN, 20);

    stage_summon_troops(&self, 11, 6, &ENTITY_GOBLIN, 10);

    stage_summon_troops(&self, 14, 17, &ENTITY_SPEAR_GOBLIN, 10);
    stage_summon_troops(&self, 15, 17, &ENTITY_CYCLOPS, 2);
    stage_summon_troops(&self, 16, 17, &ENTITY_SPEAR_GOBLIN, 10);
    stage_summon_troops(&self, 14, 18, &ENTITY_GOBLIN, 20);
    stage_summon_troops(&self, 15, 18, &ENTITY_GOBLIN, 20);
    stage_summon_troops(&self, 16, 18, &ENTITY_GOBLIN, 20);

}, "Narrow River Fords",
    "On your way through the enchanted forest you encounter a river.\n"
    "Although there is are fords to cross it, not many of your troops can do so\n"
    "at the same time."
);