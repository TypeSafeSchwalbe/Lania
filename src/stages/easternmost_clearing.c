
#include "stages.h"
#include "content/nature.h"
#include "content/humans.h"
#include "content/goblins.h"
#include "../engine/sequences.h"
#include "../engine/console.h"


#define FRST &SCENE_TILE_FOREST
#define DFST &SCENE_TILE_DENSE_FOREST
#define MDOW &SCENE_TILE_MEADOW
#define VPLR &SCENE_TILE_VILLAGE_PATH_LR

IMPL_STAGE(EASTERNMOST_CLEARING, easternmost_clearing, ((const SceneTile**[]) {
    (const SceneTile*[]) { DFST, DFST, DFST, DFST, DFST, DFST, DFST },
    (const SceneTile*[]) { DFST, FRST, MDOW, MDOW, MDOW, FRST, DFST },
    (const SceneTile*[]) { DFST, MDOW, MDOW, MDOW, MDOW, MDOW, DFST },
    (const SceneTile*[]) { VPLR, VPLR, MDOW, MDOW, MDOW, VPLR, VPLR },
    (const SceneTile*[]) { DFST, MDOW, MDOW, MDOW, MDOW, MDOW, DFST },
    (const SceneTile*[]) { DFST, FRST, MDOW, MDOW, MDOW, FRST, DFST },
    (const SceneTile*[]) { DFST, DFST, DFST, DFST, DFST, DFST, DFST }
}), 7, 7, FOG_DISABLED, COMMANDER_AGREG, {
    scene_focus_on_tile(&self, 0, 3);
    stage_summon_troops(&self, 0, 3, &ENTITY_KNIGHT, 10);
    stage_summon_troops(&self, 5, 2, &ENTITY_GOBLIN, 5);
    stage_summon_troops(&self, 5, 3, &ENTITY_GOBLIN, 5);
    stage_summon_troops(&self, 5, 4, &ENTITY_GOBLIN, 5);
    stage_summon_troops(&self, 6, 3, &ENTITY_GOBLIN, 5);
}, "Easternmost Clearing",
    "After the goblins' attack on Abil failed the kingdom of the humans\n"
    "is looking for more commanders for their counter-invasion,\n"
    "knowing that the goblins will certainly come back.\n"
    "Your leadership during the battle of Abil gained you a position as a commander.\n"
    "Get rid of an invading group of goblins that are expected to pass by\n"
    "a forest clearing in the east of the human realm."
);




