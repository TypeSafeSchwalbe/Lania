
#include <stdio.h>

#include "stages.h"
#include "../ui.h"
#include "../engine/console.h"
#include "../engine/sequences.h"


void stage_summon_troops(Scene* scene, size_t tile_x, size_t tile_y, const EntityType* e_type, size_t count) {
    SceneTileState* target_tile = scene_get_tile(scene, tile_x, tile_y);
    for(size_t i = 0; i < count; i += 1) {
        tile_state_add(target_tile, create_entity(e_type));
    }
}


void stage_win_if_only_humans(Scene* scene, SaveGame* savegame) {
    for(size_t y = 0; y < scene->tiles_y; y += 1) {
        for(size_t x = 0; x < scene->tiles_x; x += 1) {
            SceneTileState* tile = scene_get_tile(scene, x, y);
            if(tile->entities.size == 0 || !tile_state_get(tile, 0)->type->is_enemy) { continue; }
            return;
        }
    }
    stage_end_screen(S_GREEN_FG S_BOLD "\nGood job!\nAll goblin troops were defeated.\n" S_RESET, UNLOCK_NEXT_STAGE, savegame, scene);
}

void stage_make_goblin_moves(Scene* scene) {
    for(size_t y = 0; y < scene->tiles_y; y += 1) {
        for(size_t x = 0; x < scene->tiles_x; x += 1) {
            SceneTileState* tile = scene_get_tile(scene, x, y);
            if(tile->entities.size == 0) { continue; }
            if(!tile_state_get(tile, 0)->type->is_enemy) { continue; }
            (scene->enemy_commander->tactic)(scene, x, y);
        }
    }
}

void stage_lose_if_only_goblins(Scene* scene, SaveGame* savegame) {
    for(size_t y = 0; y < scene->tiles_y; y += 1) {
        for(size_t x = 0; x < scene->tiles_x; x += 1) {
            SceneTileState* tile = scene_get_tile(scene, x, y);
            if(tile->entities.size == 0 || tile_state_get(tile, 0)->type->is_enemy) { continue; }
            return;
        }
    }
    stage_end_screen(S_RED_FG S_BOLD "\nGame over!\nYour troops were defeated.\n" S_RESET, NO_STAGE_UNLOCK, savegame, scene);
}

void stage_reset_troop_actions(Scene* scene) {
    for(size_t y = 0; y < scene->tiles_y; y += 1) {
        for(size_t x = 0; x < scene->tiles_x; x += 1) {
            SceneTileState* tile = scene_get_tile(scene, x, y);
            for(size_t e = 0; e < tile->entities.size; e += 1) {
                tile_state_get(tile, e)->did_action = 0;
            }
        }
    }
}


const size_t STAGE_COUNT = 12;

const Stage* STAGES[] = {
    &STAGE_TUTORIAL_SELECTION,

    &STAGE_BATTLE_OF_ABIL,
    &STAGE_EASTERNMOST_CLEARING,
    &STAGE_THICK_THICKETS,

    &STAGE_SCRAMBLED_PASSES,
    &STAGE_ABANDONED_RUBY_MINE,
    &STAGE_ENDLESS_DESERT_PLAIN,

    &STAGE_ENCHANTED_LAKE,
    &STAGE_ELVEN_VILLAGE,
    &STAGE_NARROW_RIVER_FORDS,

    &STAGE_WESTERN_OASIS,
    &STAGE_SEPARATED_SUBURBS
};