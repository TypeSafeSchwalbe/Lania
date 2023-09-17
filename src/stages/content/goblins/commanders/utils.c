
#include "utils.h"


SceneTileState* scene_get_tile_n(Scene* scene, size_t x, size_t y) {
    return x >= scene->tiles_x || y >= scene->tiles_y? NULL : scene_get_tile(scene, x, y);
}



GTIterator gti_new(SceneTileState* tile, const EntityType** output) {
    GTIterator created = {
        .troop_types = vector_new(sizeof(const EntityType*)),
        .current_index = 0,
        .output = output
    };
    if(tile == NULL) { return created; }
    for(size_t e = 0; e < tile->entities.size; e += 1) {
        Entity* entity = tile_state_get(tile, e);
        char found = 0;
        for(size_t et = 0; et < created.troop_types.size; et += 1) {
            const EntityType** stored_type = vector_get(&created.troop_types, et);
            if(entity->type != *stored_type) { continue; }
            found = 1;
            break;
        }
        if(found) { continue; }
        vector_push(&created.troop_types, &entity->type);
    }
    return created;
}

char gti_next(GTIterator* goblintroopi) {
    if(goblintroopi->current_index >= goblintroopi->troop_types.size) { return 0; }
    const EntityType** next_type = vector_get(&goblintroopi->troop_types, goblintroopi->current_index);
    *goblintroopi->output = *next_type;
    goblintroopi->current_index += 1;
    return 1;
}

void gti_free(GTIterator* goblintroopi) {
    vector_free(&goblintroopi->troop_types);
}


char tile_state_did_action(SceneTileState* tile, const EntityType* type) {
    for(size_t e = 0; e < tile->entities.size; e += 1) {
        Entity* entity = tile_state_get(tile, e);
        if(entity->type != type) { continue; }
        return entity->did_action;
    }
    return 0;
}

size_t tile_state_type_count(SceneTileState* tile, const EntityType* type) {
    if(tile == NULL) { return 0; }
    size_t c = 0;
    for(size_t e = 0; e < tile->entities.size; e += 1) {
        Entity* entity = tile_state_get(tile, e);
        if(entity->type != type) { continue; }
        c += 1;
    }
    return c;
}

char tile_state_contains_humans(SceneTileState* tile) {
    return tile != NULL && tile->entities.size > 0 && !tile_state_get(tile, 0)->type->is_enemy;
}

char tile_state_contains_goblins(SceneTileState* tile) {
    return tile != NULL && tile->entities.size > 0 && tile_state_get(tile, 0)->type->is_enemy;
}