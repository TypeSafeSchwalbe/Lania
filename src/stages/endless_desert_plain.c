
#include "stages.h"
#include "content/nature.h"
#include "content/humans.h"
#include "content/goblins.h"
#include "../engine/sequences.h"

#define DSRT &SCENE_TILE_DESERT

IMPL_STAGE(ENDLESS_DESERT_PLAIN, endless_desert_plain, ((const SceneTile**[]) {
    (const SceneTile*[]) { DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT },
    (const SceneTile*[]) { DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT },
    (const SceneTile*[]) { DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT },
    (const SceneTile*[]) { DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT },
    (const SceneTile*[]) { DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT },
    (const SceneTile*[]) { DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT },
    (const SceneTile*[]) { DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT },
    (const SceneTile*[]) { DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT },
    (const SceneTile*[]) { DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT },
    (const SceneTile*[]) { DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT },
    (const SceneTile*[]) { DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT },
    (const SceneTile*[]) { DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT },
    (const SceneTile*[]) { DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT },
    (const SceneTile*[]) { DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT },
    (const SceneTile*[]) { DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT },
    (const SceneTile*[]) { DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT },
    (const SceneTile*[]) { DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT },
    (const SceneTile*[]) { DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT },
    (const SceneTile*[]) { DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT },
    (const SceneTile*[]) { DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT, DSRT }
}), 20, 20, FOG_DISABLED, &COMMANDER_DUREG, {
    scene_focus_on_tile(&self, 2, 2);

    stage_summon_troops(&self, 2, 2, &ENTITY_ARCHER, 15);
    stage_summon_troops(&self, 3, 2, &ENTITY_KNIGHT, 30);
    stage_summon_troops(&self, 2, 3, &ENTITY_KNIGHT, 30);
    stage_summon_troops(&self, 3, 3, &ENTITY_KNIGHT, 30);

    stage_summon_troops(&self, 15, 3, &ENTITY_CYCLOPS, 1);
    stage_summon_troops(&self, 15, 3, &ENTITY_GOBLIN, 20);
    stage_summon_troops(&self, 16, 3, &ENTITY_GOBLIN, 30);
    stage_summon_troops(&self, 16, 4, &ENTITY_CYCLOPS, 1);
    stage_summon_troops(&self, 16, 4, &ENTITY_GOBLIN, 20);
    stage_summon_troops(&self, 15, 4, &ENTITY_GOBLIN, 30);

    stage_summon_troops(&self, 16, 16, &ENTITY_GOBLIN, 30);
    stage_summon_troops(&self, 17, 16, &ENTITY_GOBLIN, 30);
    stage_summon_troops(&self, 18, 16, &ENTITY_GOBLIN, 30);
    stage_summon_troops(&self, 19, 16, &ENTITY_GOBLIN, 30);
    stage_summon_troops(&self, 16, 17, &ENTITY_GOBLIN, 30);
    stage_summon_troops(&self, 17, 17, &ENTITY_CYCLOPS, 3);
    stage_summon_troops(&self, 18, 17, &ENTITY_GOBLIN, 30);
    stage_summon_troops(&self, 19, 17, &ENTITY_GOBLIN, 30);
    stage_summon_troops(&self, 16, 18, &ENTITY_GOBLIN, 30);
    stage_summon_troops(&self, 17, 18, &ENTITY_GOBLIN, 30);
    stage_summon_troops(&self, 18, 18, &ENTITY_CYCLOPS, 3);
    stage_summon_troops(&self, 19, 18, &ENTITY_GOBLIN, 30);
    stage_summon_troops(&self, 16, 19, &ENTITY_GOBLIN, 30);
    stage_summon_troops(&self, 17, 19, &ENTITY_GOBLIN, 30);
    stage_summon_troops(&self, 18, 19, &ENTITY_GOBLIN, 30);
    stage_summon_troops(&self, 19, 19, &ENTITY_GOBLIN, 30);
}, {
    stage_win_if_only_humans(self, savegame);
    stage_make_goblin_moves(self);
    stage_lose_if_only_goblins(self, savegame);
    stage_reset_troop_actions(self);
}, "Endless Desert Plain",
    "After you successfully took control over the eastern part of the disputed territory,\n"
    "you are now tasked with clearing the western part - which is a giant, barren desert."
);