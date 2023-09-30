
#include <stdio.h>

#include "stages.h"
#include "content/nature.h"
#include "content/humans.h"
#include "content/goblins.h"
#include "../ui.h"
#include "../engine/sequences.h"


#define BDLD &SCENE_TILE_BADLANDS
#define BDLB &SCENE_TILE_BADLANDS_BONES
#define GHUT &SCENE_TILE_GOBLIN_HUT

#define FRST &SCENE_TILE_FOREST
#define DFST &SCENE_TILE_DENSE_FOREST
#define MDOW &SCENE_TILE_MEADOW
#define WATR &SCENE_TILE_WATER

#define VPLR &SCENE_TILE_VILLAGE_PATH_LR
#define VPTB &SCENE_TILE_VILLAGE_PATH_TB
#define VPTL &SCENE_TILE_VILLAGE_PATH_TL
#define VPTR &SCENE_TILE_VILLAGE_PATH_TR
#define VPBL &SCENE_TILE_VILLAGE_PATH_BL
#define VPBR &SCENE_TILE_VILLAGE_PATH_BR
#define VP3L &SCENE_TILE_VILLAGE_PATH_3L
#define VP3R &SCENE_TILE_VILLAGE_PATH_3R
#define VP3T &SCENE_TILE_VILLAGE_PATH_3T
#define VP3B &SCENE_TILE_VILLAGE_PATH_3B

IMPL_STAGE(WESTERN_OASIS, western_oasis, ((const SceneTile**[]) {
    (const SceneTile*[]) { BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, GHUT, BDLD, GHUT, BDLD, BDLD, BDLB, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, GHUT, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, VPBR, VPLR, VPLR, VPLR, VP3T, VPLR, VPLR, VPLR, VPLR, VPLR, VPLR, VPLR, VPLR, VPLR, VPLR, VP3T, VPLR, VPLR, VPBL, GHUT },
    (const SceneTile*[]) { BDLD, VPTB, GHUT, BDLB, GHUT, VPTB, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, GHUT, BDLD, VPTB, GHUT, BDLD, VPTB, BDLD },
    (const SceneTile*[]) { GHUT, VP3L, VPLR, VPBL, BDLD, VPTB, BDLD, BDLB, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, GHUT, VPTB, BDLD, GHUT, VPTB, GHUT },
    (const SceneTile*[]) { BDLD, VPTB, GHUT, VPTB, GHUT, BDLD, BDLD, BDLD, MDOW, MDOW, BDLD, BDLD, BDLD, BDLB, GHUT, BDLD, VPTB, GHUT, BDLD, GHUT, BDLD },
    (const SceneTile*[]) { GHUT, VPTB, BDLD, VPTB, BDLD, BDLD, BDLD, MDOW, FRST, MDOW, MDOW, BDLD, BDLD, BDLD, VPLR, VPLR, VP3B, VPLR, VPBL, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, GHUT, BDLD, VPTB, BDLD, BDLD, BDLD, FRST, FRST, WATR, MDOW, MDOW, BDLD, BDLD, GHUT, BDLD, BDLD, GHUT, VPTB, GHUT, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, VPTB, BDLD, BDLD, MDOW, FRST, WATR, WATR, WATR, MDOW, BDLD, BDLD, BDLD, BDLD, GHUT, VPBR, VP3B, VPBL, BDLD },
    (const SceneTile*[]) { BDLD, BDLB, BDLD, VPTB, BDLD, BDLD, MDOW, WATR, WATR, WATR, WATR, FRST, MDOW, BDLD, GHUT, VPLR, VPLR, VP3R, BDLB, VPTB, GHUT },
    (const SceneTile*[]) { BDLB, BDLD, BDLD, VPTB, BDLD, BDLD, MDOW, WATR, WATR, WATR, FRST, FRST, MDOW, BDLD, BDLD, GHUT, BDLD, VPTR, VP3T, VPTL, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, VPTB, BDLD, BDLD, MDOW, MDOW, WATR, MDOW, FRST, FRST, BDLD, BDLD, BDLD, BDLD, BDLD, GHUT, VPTB, GHUT, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, VPTB, BDLD, BDLD, BDLD, MDOW, MDOW, MDOW, BDLD, BDLD, BDLD, BDLD, BDLD, BDLB, BDLD, BDLD, VPTB, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, VPTB, BDLD, BDLD, BDLD, BDLD, BDLD, GHUT, BDLD, BDLD, BDLD, BDLD, BDLB, BDLD, BDLD, BDLD, VPTB, BDLD, BDLD },
    (const SceneTile*[]) { VPLR, VPLR, VPLR, VP3B, VPLR, VPBL, BDLD, BDLD, GHUT, VPLR, VPBL, GHUT, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, VPTB, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, BDLD, BDLD, VPTB, BDLD, BDLD, BDLD, BDLD, VP3L, VPLR, VPLR, VPLR, VPLR, VPLR, VPLR, VPLR, VP3B, VPLR, VPLR },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, BDLD, BDLD, VPTR, VPLR, VP3T, VPLR, GHUT, VPTB, GHUT, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, BDLB, BDLD, BDLD, BDLD, BDLD, VPTB, GHUT, BDLB, VP3L, VPLR, VPLR, GHUT, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, BDLD, BDLB, BDLD, GHUT, VPTR, VPLR, VPLR, VP3R, GHUT, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLB, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, BDLB, BDLD, BDLD, BDLD, BDLD, BDLD, GHUT, BDLD, GHUT, VPTR, VPLR, GHUT, BDLD, BDLD, BDLB, BDLD, BDLD, BDLD, BDLB, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD }
}), 21, 21, FOG_ENABLED, &COMMANDER_OBREG, {
    scene_focus_on_tile(&self, 1, 14);

    stage_summon_troops(&self, 0, 14, &ENTITY_CATAPULT, 1);
    stage_summon_troops(&self, 1, 14, &ENTITY_KNIGHT, 20);
    stage_summon_troops(&self, 2, 14, &ENTITY_KNIGHT, 20);
    stage_summon_troops(&self, 3, 14, &ENTITY_SCOUT, 2);

    stage_summon_troops(&self, 1, 2, &ENTITY_GOBLIN, 20);
    stage_summon_troops(&self, 2, 2, &ENTITY_GOBLIN, 20);
    stage_summon_troops(&self, 1, 3, &ENTITY_DAGGER_GOBLIN, 20);
    stage_summon_troops(&self, 5, 4, &ENTITY_GOBLIN, 20);
    stage_summon_troops(&self, 5, 3, &ENTITY_DAGGER_GOBLIN, 20);

    stage_summon_troops(&self, 10, 15, &ENTITY_DAGGER_GOBLIN, 20);
    stage_summon_troops(&self, 11, 15, &ENTITY_GOBLIN, 20);
    stage_summon_troops(&self, 10, 17, &ENTITY_GOBLIN, 20);
    stage_summon_troops(&self, 9, 18, &ENTITY_DAGGER_GOBLIN, 20);
    stage_summon_troops(&self, 10, 18, &ENTITY_GOBLIN, 20);

    stage_summon_troops(&self, 14, 2, &ENTITY_DAGGER_GOBLIN, 20);
    stage_summon_troops(&self, 15, 2, &ENTITY_DAGGER_GOBLIN, 20);
    stage_summon_troops(&self, 16, 2, &ENTITY_GOBLIN, 20);
    stage_summon_troops(&self, 17, 2, &ENTITY_GOBLIN, 20);
    stage_summon_troops(&self, 16, 3, &ENTITY_GOBLIN, 20);

    stage_summon_troops(&self, 17, 8, &ENTITY_GOBLIN, 20);
    stage_summon_troops(&self, 18, 8, &ENTITY_GOBLIN, 20);
    stage_summon_troops(&self, 19, 8, &ENTITY_DAGGER_GOBLIN, 20);
    stage_summon_troops(&self, 17, 9, &ENTITY_GOBLIN, 20);
    stage_summon_troops(&self, 17, 10, &ENTITY_DAGGER_GOBLIN, 20);
}, {
    char goblin_hut_found = 0;
    size_t goblin_hut_idx;
    SceneIterator goblin_huts = scenei_new(self, &SCENE_OBJECT_GOBLIN_HUT, &goblin_hut_idx);
    while(scenei_next(&goblin_huts)) {
        GoblinHut* goblin_hut = scene_get(self, goblin_hut_idx);
        SceneTileState* goblin_hut_tile = scene_get_tile(self, goblin_hut->x / SCENE_TILE_WIDTH, goblin_hut->y / SCENE_TILE_HEIGHT);
        if(goblin_hut_tile->entities.size > 0) {
            goblin_hut_found = 1;
            continue;
        }
        scene_add_goblin_hut_rubble(self, goblin_hut->x, goblin_hut->y);
        scene_delete(self, goblin_hut_idx);
        scenei_rewind(&goblin_huts);
    }
    if(!goblin_hut_found) {
        stage_end_screen(S_GREEN_FG S_BOLD "\nGood job!\nAll goblin huts were destroyed.\n" S_RESET, UNLOCK_NEXT_STAGE, savegame, self);
    }
    stage_make_goblin_moves(self);
    stage_lose_if_only_goblins(self, savegame);
    stage_reset_troop_actions(self);
}, "Western Oasis",
    "Time to give the goblins a taste of their own medicine.\n"
    "Enter the central region of the goblin realm and\n"
    "destroy the settlements around the western oasis.\n"
    "\n"
    "(Attack huts to destroy them. Destroy all huts to complete this stage.)"
);