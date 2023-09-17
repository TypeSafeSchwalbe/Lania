
#include "stages.h"
#include "content/nature.h"
#include "content/humans.h"
#include "content/goblins.h"
#include "../engine/sequences.h"
#include "../engine/console.h"


#define FRST &SCENE_TILE_FOREST
#define DFST &SCENE_TILE_DENSE_FOREST
#define MDOW &SCENE_TILE_MEADOW
#define VFLD &SCENE_TILE_VILLAGE_FIELD
#define VPLR &SCENE_TILE_VILLAGE_PATH_LR
#define VPTB &SCENE_TILE_VILLAGE_PATH_TB

IMPL_STAGE(THICK_THICKETS, thick_thickets, ((const SceneTile**[]) {
    (const SceneTile*[]) { MDOW, MDOW, MDOW, MDOW, MDOW, MDOW, MDOW, MDOW, MDOW },
    (const SceneTile*[]) { MDOW, MDOW, MDOW, MDOW, MDOW, MDOW, MDOW, MDOW, MDOW },
    (const SceneTile*[]) { MDOW, MDOW, MDOW, MDOW, MDOW, MDOW, VFLD, VFLD, VFLD },
    (const SceneTile*[]) { DFST, DFST, DFST, MDOW, MDOW, MDOW, VFLD, VFLD, VFLD },
    (const SceneTile*[]) { VFLD, VFLD, VFLD, MDOW, DFST, MDOW, VFLD, VFLD, VFLD },
    (const SceneTile*[]) { VFLD, VFLD, VFLD, MDOW, DFST, MDOW, DFST, DFST, DFST },
    (const SceneTile*[]) { VFLD, VFLD, VFLD, MDOW, DFST, MDOW, MDOW, MDOW, MDOW },
    (const SceneTile*[]) { MDOW, MDOW, MDOW, MDOW, DFST, MDOW, MDOW, MDOW, VPLR },
    (const SceneTile*[]) { VPLR, MDOW, MDOW, MDOW, DFST, MDOW, MDOW, MDOW, MDOW },
}), 9, 9, COMMANDER_AGREG, {
    scene_focus_on_tile(&self, 4, 4);
    stage_summon_troops(&self, 0, 8, &ENTITY_KNIGHT, 5);
    stage_summon_troops(&self, 8, 7, &ENTITY_KNIGHT, 5);
    stage_summon_troops(&self, 1, 0, &ENTITY_GOBLIN, 5);
    stage_summon_troops(&self, 3, 0, &ENTITY_GOBLIN, 5);
    stage_summon_troops(&self, 4, 0, &ENTITY_GOBLIN, 5);
    stage_summon_troops(&self, 5, 0, &ENTITY_GOBLIN, 5);
    stage_summon_troops(&self, 7, 0, &ENTITY_GOBLIN, 5);
}, "Thick Thickets",
    "The goblins were successfully pushed back to the border.\n"
    "You are assigned two groups of knights, coming from opposite direction.\n"
    "Use their combined force to break through their defenses and enter the disputed territory."
);
