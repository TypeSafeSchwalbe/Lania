
#include "stages.h"
#include "content/nature.h"
#include "content/humans.h"
#include "content/goblins.h"
#include "../engine/sequences.h"


#define DSRT &SCENE_TILE_DESERT
#define CLFF &SCENE_TILE_CLIFF_FULL
#define CLUL &SCENE_TILE_CLIFF_UP_LEFT
#define CLUR &SCENE_TILE_CLIFF_UP_RIGHT
#define CLDL &SCENE_TILE_CLIFF_DOWN_LEFT
#define CLDR &SCENE_TILE_CLIFF_DOWN_RIGHT

IMPL_STAGE(ABANDONED_RUBY_MINE, abandoned_ruby_mine, ((const SceneTile**[]) {
    (const SceneTile*[]) { DSRT, CLUL, CLFF, CLFF, CLFF, CLFF, CLFF, CLFF, CLFF, CLFF, CLFF },
    (const SceneTile*[]) { DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, CLUL },
    (const SceneTile*[]) { CLDL, CLDR, DSRT, DSRT, CLDL, CLFF, CLFF, CLUR, DSRT, DSRT, DSRT },
    (const SceneTile*[]) { CLUR, DSRT, DSRT, CLDL, CLUR, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT },
    (const SceneTile*[]) { CLFF, CLFF, CLFF, CLUR, DSRT, DSRT, DSRT, CLDL, CLFF, CLFF, CLFF },
    (const SceneTile*[]) { CLFF, CLFF, CLUR, DSRT, DSRT, CLDL, CLFF, CLFF, CLFF, CLFF, CLFF },
    (const SceneTile*[]) { DSRT, DSRT, DSRT, DSRT, CLDL, CLUR, DSRT, DSRT, DSRT, DSRT, DSRT },
    (const SceneTile*[]) { DSRT, DSRT, CLDL, CLFF, CLUR, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT },
    (const SceneTile*[]) { DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT },
    (const SceneTile*[]) { CLDR, DSRT, DSRT, DSRT, DSRT, CLDL, CLFF, CLFF, CLFF, CLFF, CLFF },
    (const SceneTile*[]) { CLFF, CLFF, CLFF, CLFF, CLFF, CLFF, CLFF, CLFF, CLFF, CLFF, CLFF }
}), 11, 11, COMMANDER_DUREG, {
    scene_focus_on_tile(&self, 1, 1);

    stage_summon_troops(&self, 0, 1, &ENTITY_KNIGHT, 10);
    stage_summon_troops(&self, 1, 1, &ENTITY_ARCHER, 10);
    stage_summon_troops(&self, 2, 1, &ENTITY_KNIGHT, 10);
    stage_summon_troops(&self, 2, 2, &ENTITY_KNIGHT, 10);

    stage_summon_troops(&self, 8, 1, &ENTITY_GOBLIN, 10);
    stage_summon_troops(&self, 9, 1, &ENTITY_CYCLOPS, 1);
    stage_summon_troops(&self, 9, 1, &ENTITY_GOBLIN, 10);
    stage_summon_troops(&self, 9, 2, &ENTITY_GOBLIN, 10);

    stage_summon_troops(&self, 0, 7, &ENTITY_GOBLIN, 10);
    stage_summon_troops(&self, 0, 8, &ENTITY_CYCLOPS, 1);
    stage_summon_troops(&self, 0, 8, &ENTITY_GOBLIN, 10);
    stage_summon_troops(&self, 1, 8, &ENTITY_GOBLIN, 10);
    stage_summon_troops(&self, 1, 9, &ENTITY_GOBLIN, 10);

    stage_summon_troops(&self, 7, 6, &ENTITY_GOBLIN, 10);
    stage_summon_troops(&self, 9, 6, &ENTITY_GOBLIN, 10);
    stage_summon_troops(&self, 6, 7, &ENTITY_GOBLIN, 10);
    stage_summon_troops(&self, 7, 7, &ENTITY_CYCLOPS, 1);
    stage_summon_troops(&self, 7, 7, &ENTITY_GOBLIN, 10);
    stage_summon_troops(&self, 8, 7, &ENTITY_GOBLIN, 10);
    stage_summon_troops(&self, 9, 7, &ENTITY_CYCLOPS, 1);
    stage_summon_troops(&self, 9, 7, &ENTITY_GOBLIN, 10);
    stage_summon_troops(&self, 10, 7, &ENTITY_GOBLIN, 10);
    stage_summon_troops(&self, 7, 8, &ENTITY_GOBLIN, 10);
    stage_summon_troops(&self, 9, 8, &ENTITY_GOBLIN, 10);
}, "Abandoned Ruby Mine",
    "On the eastern end of the desert that is the disputed territory\n"
    "there is an old abandoned ruby mine that was once used by the humans.\n"
    "Free the mine from all goblins currently stationed there."
);