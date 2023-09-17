
#include <math.h>

#include "actions.h"
#include "../ui.h"
#include "../engine/path_find.h"


char tile_is_valid(Scene* scene, unsigned int tile_x, unsigned int tile_y, const EntityType* troop_type, size_t troop_count) {
    SceneTileState* tile_state = scene_get_tile(scene, tile_x, tile_y);
    const SceneTile* tile_type = scene_get_tile_type(scene, tile_x, tile_y);
    size_t dest_available_capacity = tile_type->capacity - tile_state_used_capacity(tile_state);
    if(troop_type->size * troop_count > dest_available_capacity) { return 0; }
    for(size_t e = 0; e < tile_state->entities.size; e += 1) {
        Entity* entity = tile_state_get(tile_state, e);
        if(entity->type->is_enemy) { return 0; }
    }
    return 1;
}

char move_tile_validator(Scene* scene, unsigned int start_x, unsigned int start_y, const EntityType* troop_type, size_t troop_count, unsigned int dest_x, unsigned int dest_y) {
    if(dest_x == start_x && dest_y == start_y) { return 0; }
    if(!tile_is_valid(scene, dest_x, dest_y, troop_type, troop_count)) { return 0; }
    char valid_tiles[scene->tiles_y * scene->tiles_x];
    for(unsigned int y = 0; y < scene->tiles_y; y += 1) {
        for(unsigned int x = 0; x < scene->tiles_x; x += 1) {
            valid_tiles[y * scene->tiles_x + x] = tile_is_valid(scene, x, y, troop_type, troop_count);
        }
    }
    unsigned int distance;
    if(!find_path(valid_tiles, scene->tiles_x, scene->tiles_y, start_x, start_y, dest_x, dest_y, NULL, &distance)) { return 0; }
    if(distance > troop_type->speed) { return 0; }
    return 1;
}

void entities_move(Scene* scene, unsigned int from_x, unsigned int from_y, const EntityType* troop_type, size_t troop_count, unsigned int dest_x, unsigned int dest_y) {
    SceneTileState* from_state = scene_get_tile(scene, from_x, from_y);
    SceneTileState* dest_state = scene_get_tile(scene, dest_x, dest_y);
    size_t e = 0;
    size_t moved = 0;
    while(e < from_state->entities.size && moved < troop_count) {
        Entity* entity = tile_state_get(from_state, e);
        if(entity->type != troop_type) {
            e += 1;
            continue;
        }
        entity->did_action = 1;
        tile_state_add(dest_state, *entity);
        tile_state_remove(from_state, e);
        moved += 1;
    }
}

IMPL_ACTION(MOVE, move, "Move", {
    const EntityType* troop_type = select_tile_troop_type(buffer, scene, tile_x, tile_y);
    if(troop_type == NULL) { return; }
    size_t troop_count;
    if(!select_tile_troop_count(buffer, scene, tile_x, tile_y, troop_type, &troop_count)) { return; }
    unsigned int dest_x;
    unsigned int dest_y;
    if(!select_destination_tile(buffer, scene, tile_x, tile_y, troop_type, troop_count, &move_tile_validator, &dest_x, &dest_y)) { return; }
    entities_move(scene, tile_x, tile_y, troop_type, troop_count, dest_x, dest_y);
    scene_focus_on_tile(scene, dest_x, dest_y);
});