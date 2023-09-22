
#include "stages.h"
#include "content/nature.h"
#include "content/humans.h"
#include "content/goblins.h"
#include "../engine/sequences.h"


#define BDLD &SCENE_TILE_BADLANDS
#define GROD &SCENE_TILE_GOBLIN_ROAD

#define FRST &SCENE_TILE_FOREST
#define DFST &SCENE_TILE_DENSE_FOREST
#define MDOW &SCENE_TILE_MEADOW
#define WATR &SCENE_TILE_WATER

IMPL_STAGE(REMOTE_OASIS, remote_oasis, ((const SceneTile**[]) {
    (const SceneTile*[]) { BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, MDOW, FRST, FRST, WATR, WATR, WATR, FRST, MDOW, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, MDOW, FRST, FRST, WATR, WATR, FRST, FRST, FRST, MDOW, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, MDOW, FRST, MDOW, MDOW, WATR, MDOW, FRST, MDOW, MDOW, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, BDLD, BDLD, MDOW, FRST, FRST, MDOW, MDOW, MDOW, MDOW, MDOW, MDOW, MDOW, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, BDLD, BDLD, MDOW, FRST, GROD, GROD, GROD, GROD, GROD, GROD, GROD, MDOW, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, BDLD, BDLD, MDOW, FRST, GROD, MDOW, MDOW, MDOW, MDOW, MDOW, GROD, MDOW, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, BDLD, BDLD, MDOW, FRST, GROD, FRST, FRST, WATR, MDOW, MDOW, GROD, MDOW, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, BDLD, BDLD, MDOW, FRST, GROD, FRST, WATR, WATR, MDOW, MDOW, GROD, MDOW, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, BDLD, BDLD, FRST, FRST, GROD, FRST, WATR, WATR, WATR, MDOW, GROD, MDOW, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, BDLD, BDLD, FRST, FRST, GROD, MDOW, WATR, WATR, WATR, MDOW, GROD, MDOW, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, BDLD, BDLD, MDOW, FRST, GROD, MDOW, WATR, WATR, WATR, MDOW, GROD, MDOW, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD },
    (const SceneTile*[]) { GROD, GROD, GROD, GROD, GROD, GROD, GROD, GROD, MDOW, WATR, WATR, WATR, MDOW, GROD, MDOW, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, MDOW, MDOW, MDOW, WATR, WATR, WATR, MDOW, GROD, MDOW, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, MDOW, FRST, WATR, WATR, WATR, WATR, MDOW, GROD, MDOW, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, FRST, FRST, WATR, WATR, WATR, WATR, MDOW, GROD, MDOW, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, MDOW, FRST, FRST, WATR, WATR, WATR, MDOW, GROD, MDOW, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, MDOW, MDOW, WATR, WATR, WATR, MDOW, GROD, GROD, GROD, GROD, GROD, GROD, GROD, GROD },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, FRST, FRST, FRST, WATR, FRST, MDOW, MDOW, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, MDOW, FRST, FRST, DFST, FRST, FRST, MDOW, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, MDOW, FRST, DFST, DFST, WATR, FRST, MDOW, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, FRST, DFST, WATR, WATR, FRST, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD }
}), 21, 21, COMMANDER_DUREG, {
    scene_focus_on_tile(&self, 2, 11);

    stage_summon_troops(&self, 2, 11, &ENTITY_CATAPULT, 1);
    stage_summon_troops(&self, 1, 11, &ENTITY_KNIGHT, 5);
    stage_summon_troops(&self, 3, 11, &ENTITY_KNIGHT, 5);

    stage_summon_troops(&self, 15, 16, &ENTITY_GOBLIN, 50);
    stage_summon_troops(&self, 16, 16, &ENTITY_SPEAR_GOBLIN, 25);
    stage_summon_troops(&self, 17, 16, &ENTITY_DAGGER_GOBLIN, 25);
    stage_summon_troops(&self, 18, 16, &ENTITY_SPEAR_GOBLIN, 25);
    stage_summon_troops(&self, 19, 16, &ENTITY_GOBLIN, 50);

}, "Remote Oasis",
    "Time to give the goblins a taste of their own medicine.\n"
    "Enter the central region of the goblin realm and\n"
    "take over the oasis west of the capital."
);