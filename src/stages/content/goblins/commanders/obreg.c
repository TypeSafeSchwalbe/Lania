
#include <limits.h> 

#include "utils.h"
#include "../../../../engine/path_find.h"


char tile_attackable_by_humans(Scene* scene, unsigned int x, unsigned int y) {
    for(unsigned int checked_y = 0; checked_y < scene->tiles_y; checked_y += 1) {
        for(unsigned int checked_x = 0; checked_x < scene->tiles_x; checked_x += 1) {
            SceneTileState* checked_state = scene_get_tile(scene, checked_x, checked_y);
            if(checked_state->entities.size == 0 || tile_state_get(checked_state, 0)->type->is_enemy) { continue; }
            unsigned int distance = ((x > checked_x? x : checked_x) - (x < checked_x? x : checked_x))
                + ((y > checked_y? y : checked_y) - (y < checked_y? y : checked_y));
            for(unsigned int e = 0; e < checked_state->entities.size; e += 1) {
                Entity* entity = tile_state_get(checked_state, e);
                if(distance < entity->type->attack_min_distance
                || distance > entity->type->attack_max_distance) { continue; }
                return 1;
            }
        }
    }
    return 0;
}


#define MAX_HUMAN_TARGET_DISTANCE 7

IMPL_COMMANDER(OBREG, obreg, {
    SceneTileState* tile = scene_get_tile(scene, x, y);
    const EntityType* troop_type;
    GTIterator gti = gti_new(tile, &troop_type);
    while(gti_next(&gti)) {
        if(tile_state_did_action(tile, troop_type)) { continue; }
        size_t troop_count = tile_state_type_count(tile, troop_type);
        // ===========================================================================
        // Commented out for the sake of actually making the game fun to play.
        // ---------------------------------------------------------------------------
        // Commenting this part of the code out will stop the bot from moving
        // troops that are under attack to a tile that is not.
        // This stops painful chasing of troops around the map.
        // ===========================================================================
        // if(tile_attackable_by_humans(scene, x, y)) {
        //     char valid_tiles[scene->tiles_y * scene->tiles_x];
        //     for(unsigned int checked_y = 0; checked_y < scene->tiles_y; checked_y += 1) {
        //         for(unsigned int checked_x = 0; checked_x < scene->tiles_x; checked_x += 1) {
        //             const SceneTile* checked_type = scene_get_tile_type(scene, checked_x, checked_y);
        //             valid_tiles[checked_y * scene->tiles_x + checked_x] = troop_type->size * troop_count <= checked_type->capacity;
        //         }
        //     }
        //     unsigned int safe_d = UINT_MAX;
        //     unsigned int* safe_s = NULL;
        //     for(unsigned int searched_y = 0; searched_y < scene->tiles_y; searched_y += 1) {
        //         for(unsigned int searched_x = 0; searched_x < scene->tiles_x; searched_x += 1) {
        //             if(tile_attackable_by_humans(scene, searched_x, searched_y)) { continue; }
        //             unsigned int distance;
        //             unsigned int* steps;
        //             if(!find_path(valid_tiles, scene->tiles_x, scene->tiles_y, x, y, searched_x, searched_y, &steps, &distance)) { continue; }
        //             if(distance >= safe_d) {
        //                 free(steps);
        //                 continue;
        //             }
        //             safe_d = distance;
        //             if(safe_s != NULL) { free(safe_s); }
        //             safe_s = steps;
        //         }
        //     }
        //     if(safe_s != NULL && safe_d <= troop_type->speed) {
        //         unsigned int s = 0;
        //         for(;;) {
        //             if(s >= safe_d) { break; }
        //             if(s >= troop_type->speed) { break; }
        //             unsigned int step_x = safe_s[s * 2    ];
        //             unsigned int step_y = safe_s[s * 2 + 1];
        //             SceneTileState* step_state = scene_get_tile(scene, step_x, step_y);
        //             const SceneTile* step_type = scene_get_tile_type(scene, step_x, step_y);
        //             if(step_state->entities.size > 0 && !tile_state_get(step_state, 0)->type->is_enemy) { break; }
        //             size_t step_available_capacity = step_type->capacity - tile_state_used_capacity(step_state);
        //             if(step_available_capacity < troop_count * troop_type->size) { break; }
        //             s += 1;
        //         }
        //         if(s > 0) {
        //             s -= 1;
        //             entities_move(scene, x, y, troop_type, troop_count, safe_s[s * 2], safe_s[s * 2 + 1]);
        //             free(safe_s);
        //             continue;
        //         }
        //         free(safe_s);
        //     }
        // }
        {
            unsigned int humans_x;
            unsigned int humans_y;
            unsigned int humans_d = UINT_MAX;
            for(unsigned int checked_y = 0; checked_y < scene->tiles_y; checked_y += 1) {
                for(unsigned int checked_x = 0; checked_x < scene->tiles_x; checked_x += 1) {
                    SceneTileState* checked_state = scene_get_tile(scene, checked_x, checked_y);
                    if(checked_state->entities.size == 0 || tile_state_get(checked_state, 0)->type->is_enemy) { continue; }
                    unsigned int distance = ((x > checked_x? x : checked_x) - (x < checked_x? x : checked_x))
                        + ((y > checked_y? y : checked_y) - (y < checked_y? y : checked_y));
                    if(distance > humans_d) { continue; }
                    humans_x = checked_x;
                    humans_y = checked_y;
                    humans_d = distance;
                }
            }
            if(humans_d >= troop_type->attack_min_distance
            && humans_d <= troop_type->attack_max_distance) {
                entities_attack(scene, x, y, troop_type, troop_count, humans_x, humans_y);
                continue;
            } 
        }
        {
            char valid_tiles[scene->tiles_y * scene->tiles_x];
            for(unsigned int checked_y = 0; checked_y < scene->tiles_y; checked_y += 1) {
                for(unsigned int checked_x = 0; checked_x < scene->tiles_x; checked_x += 1) {
                    const SceneTile* checked_type = scene_get_tile_type(scene, checked_x, checked_y);
                    valid_tiles[checked_y * scene->tiles_x + checked_x] = troop_type->size * troop_count <= checked_type->capacity;
                }
            }
            unsigned int humans_d = UINT_MAX;
            unsigned int* humans_s = NULL;
            for(unsigned int searched_y = 0; searched_y < scene->tiles_y; searched_y += 1) {
                for(unsigned int searched_x = 0; searched_x < scene->tiles_x; searched_x += 1) {
                    SceneTileState* tile = scene_get_tile(scene, searched_x, searched_y);
                    if(tile->entities.size == 0 || tile_state_get(tile, 0)->type->is_enemy) { continue; }
                    unsigned int distance;
                    unsigned int* steps;
                    if(!find_path(valid_tiles, scene->tiles_x, scene->tiles_y, x, y, searched_x, searched_y, &steps, &distance)) { continue; }
                    if(distance >= humans_d || distance > MAX_HUMAN_TARGET_DISTANCE) {
                        free(steps);
                        continue;
                    }
                    humans_d = distance;
                    if(humans_s != NULL) { free(humans_s); }
                    humans_s = steps;
                }
            }
            if(humans_s != NULL) {
                unsigned int s = 0;
                for(;;) {
                    if(s >= humans_d) { break; }
                    if(s >= troop_type->speed) { break; }
                    unsigned int step_x = humans_s[s * 2    ];
                    unsigned int step_y = humans_s[s * 2 + 1];
                    if(!tile_attackable_by_humans(scene, x, y) && tile_attackable_by_humans(scene, step_x, step_y)) { break; }
                    SceneTileState* step_state = scene_get_tile(scene, step_x, step_y);
                    const SceneTile* step_type = scene_get_tile_type(scene, step_x, step_y);
                    if(step_state->entities.size > 0 && !tile_state_get(step_state, 0)->type->is_enemy) { break; }
                    size_t step_available_capacity = step_type->capacity - tile_state_used_capacity(step_state);
                    if(step_available_capacity < troop_count * troop_type->size) { break; }
                    s += 1;
                }
                if(s > 0) {
                    s -= 1;
                    entities_move(scene, x, y, troop_type, troop_count, humans_s[s * 2], humans_s[s * 2 + 1]);
                } 
                free(humans_s);
            }
        }
    }
    gti_free(&gti);
});
