
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
#define FORD &SCENE_TILE_FORD

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

IMPL_STAGE(SEPARATED_SUBURBS, separated_suburbs, ((const SceneTile**[]) {
    (const SceneTile*[]) { BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, GHUT, BDLD, GHUT, BDLD, BDLD, GHUT, BDLD, GHUT, BDLD, GHUT, BDLD, BDLD, GHUT, BDLD, GHUT, BDLD, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, VPBR, VPLR, VPLR, VPLR, VPBL, GHUT, VPLR, VPLR, VP3T, VPLR, VPLR, VPBL, GHUT, VPBR, VPLR, VPLR, BDLD, VPTB, GHUT },
    (const SceneTile*[]) { BDLD, GHUT, VPTB, BDLD, GHUT, BDLD, VPTB, BDLD, GHUT, BDLD, VPTB, GHUT, BDLD, VPTB, BDLD, VPTB, GHUT, BDLD, GHUT, VPTB, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, VPTB, GHUT, BDLD, BDLD, VP3L, VPLR, VPLR, VPLR, VP3R, BDLD, VPLR, VPTL, GHUT, VP3L, VPLR, VPLR, VPLR, VP3R, GHUT },
    (const SceneTile*[]) { BDLD, BDLD, VPTB, BDLD, GHUT, BDLD, VPTB, BDLD, GHUT, BDLD, VPTB, GHUT, BDLD, GHUT, BDLD, VPTB, GHUT, BDLD, GHUT, VPTB, BDLD },
    (const SceneTile*[]) { BDLD, GHUT, VP3L, VPLR, VPLR, GHUT, VPTR, VPLR, VPLR, BDLD, VPTR, VPLR, VPLR, VP3T, VPLR, VPTL, BDLD, BDLD, VPLR, VPTL, GHUT },
    (const SceneTile*[]) { BDLD, BDLD, VPTB, GHUT, BDLD, BDLD, GHUT, GHUT, BDLD, GHUT, BDLD, GHUT, BDLD, VPTB, BDLD, GHUT, BDLD, BDLD, GHUT, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, GHUT, VPTB, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, VPTB, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, VPTB, BDLD, BDLD, FRST, FRST, MDOW, FRST, FRST, FRST, FRST, MDOW, VPTB, FRST, FRST, FRST, MDOW, FRST, FRST, MDOW },
    (const SceneTile*[]) { VPLR, VPLR, VP3R, BDLD, BDLD, FRST, WATR, WATR, WATR, WATR, WATR, WATR, WATR, FORD, WATR, WATR, WATR, WATR, WATR, WATR, WATR },
    (const SceneTile*[]) { BDLD, BDLD, VPTB, BDLD, BDLD, MDOW, FRST, FRST, FRST, MDOW, FRST, FRST, FRST, VPTB, FRST, MDOW, FRST, FRST, MDOW, FRST, FRST },
    (const SceneTile*[]) { BDLD, BDLD, VPTB, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, VPTB, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, GHUT, VPTB, GHUT, BDLD, GHUT, BDLD, BDLD, GHUT, BDLD, GHUT, BDLD, GHUT, VPTB, BDLD, BDLD, GHUT, VPBR, VPLR, GHUT, BDLD },
    (const SceneTile*[]) { BDLD, VPBR, VP3B, VPLR, VPLR, VPLR, VPBL, GHUT, VPBR, VPLR, VP3T, VPLR, VPLR, VP3B, VPLR, VPBL, BDLD, VPTB, GHUT, BDLD, BDLD },
    (const SceneTile*[]) { GHUT, VPTB, GHUT, BDLD, GHUT, BDLD, VPTB, BDLD, VPTB, BDLD, VPTB, GHUT, BDLD, BDLD, BDLD, VPTB, GHUT, VPTB, BDLD, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, VPTB, BDLD, BDLD, BDLD, GHUT, VPTB, GHUT, BDLD, GHUT, VPTB, BDLD, BDLD, VPTB, GHUT, VP3L, VPLR, VP3B, VPLR, VPBL, GHUT },
    (const SceneTile*[]) { GHUT, VPTB, BDLD, GHUT, VPTB, BDLD, VPTB, BDLD, GHUT, BDLD, VPTB, GHUT, BDLD, VPTB, BDLD, VPTB, BDLD, BDLD, GHUT, VPTB, BDLD },
    (const SceneTile*[]) { BDLD, VPTB, GHUT, BDLD, VPTR, VPLR, VP3B, VPLR, VPLR, VPLR, VPTL, BDLD, GHUT, VPTR, VPLR, VPTL, GHUT, GHUT, VPLR, VPTL, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, BDLD, GHUT, BDLD, GHUT, BDLD, BDLD, BDLD, GHUT, BDLD, BDLD, BDLD, GHUT, BDLD, BDLD, BDLD, BDLD, GHUT, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD }
}), 21, 21, FOG_ENABLED, &COMMANDER_OBREG, {
    scene_focus_on_tile(&self, 1, 10);

    stage_summon_troops(&self, 2, 9, &ENTITY_KNIGHT, 20);
    stage_summon_troops(&self, 0, 10, &ENTITY_CATAPULT, 1);
    stage_summon_troops(&self, 1, 10, &ENTITY_CATAPULT, 1);
    stage_summon_troops(&self, 2, 10, &ENTITY_SCOUT, 2);
    stage_summon_troops(&self, 2, 11, &ENTITY_KNIGHT, 20);

    stage_summon_troops(&self, 4, 2, &ENTITY_DAGGER_GOBLIN, 20);
    stage_summon_troops(&self, 5, 2, &ENTITY_SPEAR_GOBLIN, 10);
    stage_summon_troops(&self, 6, 2, &ENTITY_GOBLIN, 20);

    stage_summon_troops(&self, 6, 6, &ENTITY_DAGGER_GOBLIN, 20);
    stage_summon_troops(&self, 7, 6, &ENTITY_SPEAR_GOBLIN, 10);
    stage_summon_troops(&self, 8, 6, &ENTITY_GOBLIN, 20);

    stage_summon_troops(&self, 10, 3, &ENTITY_GOBLIN, 20);
    stage_summon_troops(&self, 8, 4, &ENTITY_DAGGER_GOBLIN, 20);
    stage_summon_troops(&self, 9, 4, &ENTITY_SPEAR_GOBLIN, 10);
    stage_summon_troops(&self, 10, 4, &ENTITY_CYCLOPS, 2);
    stage_summon_troops(&self, 10, 5, &ENTITY_GOBLIN, 20);

    stage_summon_troops(&self, 15, 4, &ENTITY_GOBLIN, 20);
    stage_summon_troops(&self, 15, 5, &ENTITY_SPEAR_GOBLIN, 10);
    stage_summon_troops(&self, 13, 6, &ENTITY_DAGGER_GOBLIN, 20);
    stage_summon_troops(&self, 14, 6, &ENTITY_DAGGER_GOBLIN, 20);
    stage_summon_troops(&self, 15, 6, &ENTITY_SPEAR_GOBLIN, 10);

    stage_summon_troops(&self, 18, 4, &ENTITY_DAGGER_GOBLIN, 20);
    stage_summon_troops(&self, 19, 4, &ENTITY_SPEAR_GOBLIN, 10);

    stage_summon_troops(&self, 6, 16, &ENTITY_DAGGER_GOBLIN, 20);
    stage_summon_troops(&self, 6, 17, &ENTITY_SPEAR_GOBLIN, 10);
    stage_summon_troops(&self, 5, 18, &ENTITY_GOBLIN, 20);
    stage_summon_troops(&self, 6, 18, &ENTITY_GOBLIN, 20);
    stage_summon_troops(&self, 7, 18, &ENTITY_GOBLIN, 20);

    stage_summon_troops(&self, 10, 15, &ENTITY_GOBLIN, 20);
    stage_summon_troops(&self, 10, 16, &ENTITY_SPEAR_GOBLIN, 10);
    stage_summon_troops(&self, 10, 17, &ENTITY_CYCLOPS, 2);
    stage_summon_troops(&self, 9, 18, &ENTITY_DAGGER_GOBLIN, 20);
    stage_summon_troops(&self, 10, 18, &ENTITY_SPEAR_GOBLIN, 10);

    stage_summon_troops(&self, 14, 14, &ENTITY_DAGGER_GOBLIN, 20);
    stage_summon_troops(&self, 15, 14, &ENTITY_SPEAR_GOBLIN, 10);
    stage_summon_troops(&self, 15, 15, &ENTITY_GOBLIN, 20);
    stage_summon_troops(&self, 15, 16, &ENTITY_GOBLIN, 20);

    stage_summon_troops(&self, 17, 14, &ENTITY_SPEAR_GOBLIN, 10);
    stage_summon_troops(&self, 17, 15, &ENTITY_DAGGER_GOBLIN, 20);
    stage_summon_troops(&self, 17, 16, &ENTITY_DAGGER_GOBLIN, 20);
    stage_summon_troops(&self, 18, 16, &ENTITY_DAGGER_GOBLIN, 20);
    stage_summon_troops(&self, 19, 16, &ENTITY_SPEAR_GOBLIN, 10);
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
}, "Separated Suburbs",
    "You have reached the western suburbs of the goblin captial.\n"
    "Take over and destroy this part to get easy access to the central part of the settlement."
);