
#include <limits.h>

#include "actions.h"
#include "../engine/console.h"
#include "../engine/format.h"
#include "../engine/sequences.h"


IMPL_ACTION(INFO, info, "Information", {
    clear_buffer(buffer);
    scene_render(scene, buffer);
    signed int pos_x = tile_x * SCENE_TILE_WIDTH + scene->camera_ox;
    signed int pos_y = tile_y * SCENE_TILE_HEIGHT + scene->camera_oy;
    const SceneTile* tile_type = scene_get_tile_type(scene, tile_x, tile_y);
    SceneTileState* tile_state = scene_get_tile(scene, tile_x, tile_y);
    unsigned short used_capacity = tile_state_used_capacity(tile_state);
    FORMAT(capacity, capacity_length, "%d / %d", used_capacity, tile_type->capacity);
    write_line_onto_buffer(buffer, pos_x + 2, pos_y + 1, S_WHITE_BG S_BLACK_FG, "Capacity:", S_RESET, 9, SHRT_MAX);
    write_line_onto_buffer(buffer, pos_x + 2, pos_y + 2, S_WHITE_BG S_BLACK_FG, capacity, S_RESET, capacity_length, SHRT_MAX);
    Vector troop_types = vector_new(sizeof(const EntityType*));
    Vector troop_counts = vector_new(sizeof(unsigned int));
    for(size_t e = 0; e < tile_state->entities.size; e += 1) {
        Entity* entity = tile_state_get(tile_state, e);
        char found = 0;
        for(size_t t = 0; t < troop_types.size; t += 1) {
            const EntityType** type = vector_get(&troop_types, t);
            if(*type != entity->type) { continue; }
            unsigned int* count = vector_get(&troop_counts, t);
            *count += 1;
            found = 1;
            break;
        }
        if(found) { continue; }
        vector_push(&troop_types, &entity->type);
        unsigned int count = 1;
        vector_push(&troop_counts, &count);
    }
    write_line_onto_buffer(buffer, pos_x + 2, pos_y + 4, S_WHITE_BG S_BLACK_FG, "Troops:", S_RESET, 7, SHRT_MAX);
    for(size_t t = 0; t < troop_types.size; t += 1) {
        const EntityType** type = vector_get(&troop_types, t);
        unsigned int* count = vector_get(&troop_counts, t);
        FORMAT(troop_info, troop_info_length, "%u * %s", *count, (*type)->name);
        write_line_onto_buffer(buffer, pos_x + 2, pos_y + 5 + t, S_WHITE_BG S_BLACK_FG, troop_info, S_RESET, troop_info_length, SHRT_MAX);
    }
    vector_free(&troop_types);
    vector_free(&troop_counts);
    console_clear();
    print_buffer(buffer);
    console_read_char();
});