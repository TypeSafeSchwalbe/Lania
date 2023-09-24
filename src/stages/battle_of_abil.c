
#include "stages.h"
#include "content/nature.h"
#include "content/humans.h"
#include "content/goblins.h"
#include "../engine/sequences.h"


#define FRST &SCENE_TILE_FOREST
#define DFST &SCENE_TILE_DENSE_FOREST
#define VHUT &SCENE_TILE_VILLAGE_HUT
#define VFLD &SCENE_TILE_VILLAGE_FIELD
#define VPLR &SCENE_TILE_VILLAGE_PATH_LR
#define VPTB &SCENE_TILE_VILLAGE_PATH_TB
#define VPTL &SCENE_TILE_VILLAGE_PATH_TL
#define VPTR &SCENE_TILE_VILLAGE_PATH_TR
#define VPBL &SCENE_TILE_VILLAGE_PATH_BL
#define VP3L &SCENE_TILE_VILLAGE_PATH_3L

IMPL_STAGE(BATTLE_OF_ABIL, battle_of_abil, ((const SceneTile**[]) {
    (const SceneTile*[]) { DFST, DFST, DFST, DFST, DFST, DFST, DFST },
    (const SceneTile*[]) { DFST, VPTB, VFLD, VFLD, VHUT, VPTB, DFST },
    (const SceneTile*[]) { DFST, VPTB, VHUT, VFLD, VFLD, VPTB, DFST },
    (const SceneTile*[]) { DFST, VPTR, VPLR, VPBL, FRST, VP3L, VPLR },
    (const SceneTile*[]) { DFST, FRST, VFLD, VPTB, FRST, VPTB, DFST },
    (const SceneTile*[]) { DFST, VHUT, VFLD, VPTR, VPLR, VPTL, DFST },
    (const SceneTile*[]) { DFST, DFST, DFST, DFST, DFST, DFST, DFST }
}), 7, 7, FOG_DISABLED, COMMANDER_AGREG, {
    scene_focus_on_tile(&self, 1, 3);
    stage_summon_troops(&self, 1, 3, &ENTITY_FARMER, 10);
    stage_summon_troops(&self, 6, 3, &ENTITY_GOBLIN, 10);
}, "The Battle of Abil",
    "You are a farmer living in Abil, a village at the border to the land of the goblins.\n"
    "The village is being attacked by the goblins during their invasion of the human realm.\n"
    "The farmers of Abil want to defend their homes no matter what, and you were chosen to be their leader.\n"
    "Lead them to victory in their battle against the goblins.\n\n"
    "Select a tile using [Up], [Down], [Left] and [Right].\n"
    "Pressing [Enter] on a tile will allow you to select one of a few possible actions."
);