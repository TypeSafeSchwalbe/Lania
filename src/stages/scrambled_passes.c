
#include "stages.h"
#include "content/nature.h"
#include "content/humans.h"
#include "content/goblins.h"
#include "../engine/sequences.h"


#define FRST &SCENE_TILE_FOREST
#define MDOW &SCENE_TILE_MEADOW
#define DSRT &SCENE_TILE_DESERT
#define CLFF &SCENE_TILE_CLIFF_FULL
#define CLUL &SCENE_TILE_CLIFF_UP_LEFT
#define CLUR &SCENE_TILE_CLIFF_UP_RIGHT
#define CLDL &SCENE_TILE_CLIFF_DOWN_LEFT
#define CLDR &SCENE_TILE_CLIFF_DOWN_RIGHT

IMPL_STAGE(SCRAMBLED_PASSES, scrambled_passes, ((const SceneTile**[]) {
    (const SceneTile*[]) { FRST, CLUL, CLFF, CLFF, CLFF, CLFF, CLFF, CLFF, CLFF, CLFF, DSRT },
    (const SceneTile*[]) { MDOW, MDOW, MDOW, MDOW, MDOW, CLUL, CLFF, CLFF, CLFF, CLUR, DSRT },
    (const SceneTile*[]) { MDOW, CLDL, CLFF, CLDR, MDOW, DSRT, CLUL, CLFF, CLUR, DSRT, DSRT },
    (const SceneTile*[]) { CLFF, CLFF, CLFF, CLUR, MDOW, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT },
    (const SceneTile*[]) { CLFF, CLFF, CLFF, MDOW, MDOW, CLDL, CLFF, CLFF, CLDR, DSRT, DSRT },
    (const SceneTile*[]) { CLFF, CLFF, CLUR, MDOW, CLDL, CLFF, CLFF, CLFF, CLFF, DSRT, DSRT },
    (const SceneTile*[]) { CLFF, CLUR, MDOW, MDOW, CLFF, CLFF, CLFF, CLFF, CLUR, DSRT, DSRT },
    (const SceneTile*[]) { FRST, MDOW, MDOW, CLDL, CLFF, CLUR, DSRT, DSRT, DSRT, DSRT, DSRT },
    (const SceneTile*[]) { MDOW, MDOW, FRST, CLFF, CLUR, DSRT, DSRT, CLDL, CLFF, CLDR, DSRT },
    (const SceneTile*[]) { FRST, MDOW, MDOW, MDOW, MDOW, DSRT, CLDL, CLFF, CLFF, CLFF, DSRT },
    (const SceneTile*[]) { CLFF, CLFF, CLFF, CLFF, CLFF, CLFF, CLFF, CLFF, CLFF, CLFF, DSRT }
}), 11, 11, COMMANDER_DUREG, {
    scene_focus_on_tile(&self, 1, 1);
    stage_summon_troops(&self, 0, 1, &ENTITY_ARCHER, 5);
    stage_summon_troops(&self, 0, 1, &ENTITY_KNIGHT, 5);
    stage_summon_troops(&self, 0, 8, &ENTITY_ARCHER, 5);
    stage_summon_troops(&self, 1, 8, &ENTITY_KNIGHT, 5);
    stage_summon_troops(&self, 9, 3, &ENTITY_CYCLOPS, 1);
    stage_summon_troops(&self, 9, 3, &ENTITY_GOBLIN, 5);
    stage_summon_troops(&self, 9, 4, &ENTITY_GOBLIN, 5);
    stage_summon_troops(&self, 8, 3, &ENTITY_GOBLIN, 5);
    stage_summon_troops(&self, 9, 7, &ENTITY_CYCLOPS, 1);
    stage_summon_troops(&self, 9, 7, &ENTITY_GOBLIN, 5);
    stage_summon_troops(&self, 8, 7, &ENTITY_GOBLIN, 5);
}, "Scrambled Passes",
    "Now that the goblins have been pushed away into the mountains\n"
    "that separate the eastern forest in the human realm from the desert in the disputed territory,\n"
    "it is your job to take back control of the mountain passes that stretch through said mountains.\n"
    "This will secure control over the region."
);