
#pragma once 

#include "../../goblins.h"
#include "../../../../actions/entity_actions.h"


SceneTileState* scene_get_tile_n(Scene* scene, size_t x, size_t y);


typedef struct GTIterator {
    Vector troop_types;
    size_t current_index;
    const EntityType** output;
} GTIterator;

GTIterator gti_new(SceneTileState* tile, const EntityType** output);

char gti_next(GTIterator* goblintroopi);

void gti_free(GTIterator* goblintroopi);


char tile_state_did_action(SceneTileState* tile, const EntityType* type);

size_t tile_state_type_count(SceneTileState* tile, const EntityType* type);

char tile_state_contains_humans(SceneTileState* tile);

char tile_state_contains_goblins(SceneTileState* tile);