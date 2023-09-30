
#include "stages.h"
#include "content/nature.h"
#include "content/humans.h"
#include "content/goblins.h"
#include "../ui.h"
#include "../engine/sequences.h"


#define BDLD &SCENE_TILE_BADLANDS
#define BDLB &SCENE_TILE_BADLANDS_BONES
#define GHUT &SCENE_TILE_GOBLIN_HUT

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
#define VPTX &SCENE_TILE_VILLAGE_PATH_X

IMPL_STAGE(GOBLIN_CAPITAL, goblin_capital, ((const SceneTile**[]) {
    (const SceneTile*[]) { BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD },
    (const SceneTile*[]) { BDLD, GHUT, BDLD, GHUT, BDLD, GHUT, GHUT, GHUT, BDLD, GHUT, BDLD, GHUT, BDLD, GHUT, BDLD, GHUT, BDLD, GHUT, BDLD, GHUT, BDLD },
    (const SceneTile*[]) { GHUT, BDLD, GHUT, VPBR, VPLR, VPLR, VPLR, VPLR, VPLR, VP3T, VPLR, VPLR, VPLR, VPLR, VPLR, VP3T, VPLR, VPLR, VP3T, VPLR, VPLR },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, VPTB, GHUT, BDLB, GHUT, GHUT, BDLB, VPTB, GHUT, GHUT, GHUT, BDLB, GHUT, VPTB, GHUT, BDLD, VPTB, GHUT, BDLD },
    (const SceneTile*[]) { BDLD, GHUT, GHUT, VP3L, VPLR, VPLR, VPLR, VPLR, VPLR, VPTX, VPLR, VPLR, VPLR, VPLR, VPLR, VP3R, BDLD, GHUT, VPTB, BDLD, GHUT },
    (const SceneTile*[]) { GHUT, BDLD, GHUT, VPTB, GHUT, BDLD, GHUT, GHUT, BDLD, VPTB, GHUT, BDLD, BDLD, GHUT, BDLD, VPTB, GHUT, GHUT, VPTB, GHUT, BDLD },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, VPTB, BDLD, GHUT, GHUT, BDLD, GHUT, VPTB, BDLD, GHUT, GHUT, GHUT, GHUT, VP3L, VPLR, VPLR, VPTX, VPLR, VPLR },
    (const SceneTile*[]) { BDLD, GHUT, GHUT, VPTB, GHUT, GHUT, BDLD, VPBR, VPLR, VP3B, VPLR, VPBL, BDLD, GHUT, BDLD, VPTB, GHUT, BDLD, VPTB, BDLD, GHUT },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, VPTB, GHUT, BDLD, GHUT, VPTB, GHUT, GHUT, BDLD, VPTB, GHUT, BDLD, GHUT, VPTB, GHUT, BDLD, VPTB, GHUT, GHUT },
    (const SceneTile*[]) { BDLD, GHUT, GHUT, VPTB, BDLD, GHUT, BDLD, VPTB, BDLD, GHUT, GHUT, VPTB, BDLD, GHUT, BDLD, VPTB, BDLD, GHUT, VPTB, GHUT, BDLD },
    (const SceneTile*[]) { VPLR, VPLR, VPLR, VPTX, VPLR, VPLR, VPLR, VPTX, VPLR, VPLR, VPLR, VPTX, VPLR, VPLR, VPLR, VPTX, VPLR, VPLR, VPTX, VPLR, VPLR },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, VPTB, GHUT, BDLD, BDLD, VPTB, BDLD, GHUT, GHUT, VPTB, GHUT, GHUT, BDLD, VPTB, BDLD, GHUT, VPTB, BDLD, GHUT },
    (const SceneTile*[]) { GHUT, BDLD, GHUT, VPTB, BDLD, GHUT, GHUT, VPTB, GHUT, BDLD, GHUT, VPTB, BDLD, BDLD, GHUT, VPTB, GHUT, GHUT, VPTB, GHUT, BDLD },
    (const SceneTile*[]) { BDLD, GHUT, BDLD, VPTB, GHUT, BDLD, BDLD, VPTR, VPLR, VP3T, VPLR, VPTL, GHUT, GHUT, BDLD, VPTB, GHUT, BDLD, VPTB, GHUT, GHUT },
    (const SceneTile*[]) { BDLD, BDLD, GHUT, VPTB, BDLD, GHUT, GHUT, BDLD, GHUT, VPTB, BDLD, BDLD, GHUT, BDLD, GHUT, VP3L, VPLR, VPLR, VPTX, VPLR, VPLR },
    (const SceneTile*[]) { GHUT, GHUT, GHUT, VPTB, GHUT, GHUT, BDLD, GHUT, BDLD, VPTB, BDLD, GHUT, BDLD, GHUT, BDLD, VPTB, GHUT, GHUT, VPTB, BDLD, GHUT },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, VP3L, VPLR, VPLR, VPLR, VPLR, VPLR, VPTX, VPLR, VPLR, VPLR, VPLR, VPLR, VP3R, BDLD, GHUT, VPTB, GHUT, BDLD },
    (const SceneTile*[]) { BDLD, GHUT, GHUT, VPTB, GHUT, BDLB, BDLB, GHUT, BDLB, VPTB, GHUT, BDLB, GHUT, GHUT, BDLB, VPTB, GHUT, GHUT, VPTB, GHUT, GHUT },
    (const SceneTile*[]) { GHUT, BDLD, BDLD, VPTR, VPLR, VPLR, VPLR, VPLR, VPLR, VP3B, VPLR, VPLR, VPLR, VPLR, VPLR, VP3B, VPLR, VPLR, VP3B, VPLR, VPLR },
    (const SceneTile*[]) { BDLD, GHUT, GHUT, BDLD, GHUT, GHUT, BDLD, GHUT, GHUT, BDLD, GHUT, GHUT, GHUT, BDLD, GHUT, GHUT, BDLD, GHUT, GHUT, BDLD, GHUT },
    (const SceneTile*[]) { BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD, BDLD }
}), 21, 21, FOG_DISABLED, &COMMANDER_DUREG, {
    scene_focus_on_tile(&self, 1, 10);

    stage_summon_troops(&self, 0, 10, &ENTITY_KNIGHT, 20);
    stage_summon_troops(&self, 1, 10, &ENTITY_CATAPULT, 1);
    stage_summon_troops(&self, 2, 10, &ENTITY_CATAPULT, 1);
    stage_summon_troops(&self, 3, 10, &ENTITY_KNIGHT, 20);

    stage_summon_troops(&self, 15, 10, &ENTITY_GOBLIN_KING, 1);
}, {
    size_t goblin_hut_idx;
    SceneIterator goblin_huts = scenei_new(self, &SCENE_OBJECT_GOBLIN_HUT, &goblin_hut_idx);
    while(scenei_next(&goblin_huts)) {
        GoblinHut* goblin_hut = scene_get(self, goblin_hut_idx);
        SceneTileState* goblin_hut_tile = scene_get_tile(self, goblin_hut->x / SCENE_TILE_WIDTH, goblin_hut->y / SCENE_TILE_HEIGHT);
        if(goblin_hut_tile->entities.size > 0) { continue; }
        scene_add_goblin_hut_rubble(self, goblin_hut->x, goblin_hut->y);
        scene_delete(self, goblin_hut_idx);
        scenei_rewind(&goblin_huts);
    }
    for(unsigned int spawn_point_idx = 0; spawn_point_idx < 5; spawn_point_idx += 1) {
        unsigned int spawn_point_x = 20;
        unsigned int spawn_point_y = 2 + spawn_point_idx * 4;
        if(rand() % 4 != 0
        || scene_get_tile(self, spawn_point_x, spawn_point_y)->entities.size != 0) { continue; }
        int r = rand() % 10;
        switch(r) {
            case 0: case 1: case 2:
                stage_summon_troops(self, spawn_point_x, spawn_point_y, &ENTITY_GOBLIN, 20);
                break;
            case 3: case 4: case 5:
                stage_summon_troops(self, spawn_point_x, spawn_point_y, &ENTITY_DAGGER_GOBLIN, 20);
                break;
            case 6: case 7:
                stage_summon_troops(self, spawn_point_x, spawn_point_y, &ENTITY_SPEAR_GOBLIN, 10);
                break;
            case 8: case 9:
                stage_summon_troops(self, spawn_point_x, spawn_point_y, &ENTITY_CYCLOPS, 2);
                break;
        }
    }
    char goblin_king_alive = 0;
    for(size_t y = 0; y < self->tiles_y && !goblin_king_alive; y += 1) {
        for(size_t x = 0; x < self->tiles_x && !goblin_king_alive; x += 1) {
            SceneTileState* tile = scene_get_tile(self, x, y);
            if(tile->entities.size == 0 || !tile_state_get(tile, 0)->type->is_enemy) { continue; }
            for(size_t e = 0; e < tile->entities.size; e += 1) {
                if(tile_state_get(tile, e)->type != &ENTITY_GOBLIN_KING) { continue; }
                goblin_king_alive = 1;
                break;
            }
        }
    }
    if(!goblin_king_alive) {
        stage_end_screen(S_GREEN_FG S_BOLD "\nGood job!\nThe goblin king was defeated and the war against the goblins was won!\n" S_RESET, UNLOCK_NEXT_STAGE, savegame, self);
    }
    stage_make_goblin_moves(self);
    stage_lose_if_only_goblins(self, savegame);
    stage_reset_troop_actions(self);
}, "Goblin Capital",
    "At last you have reached the center of the goblin realm, it's capital.\n"
    "Your arrival has been awaited by the goblin king, and he is not going to give up easily.\n"
    "\n"
    "(Take out the goblin king to complete this stage.)"
);