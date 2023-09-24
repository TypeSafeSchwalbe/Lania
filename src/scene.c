
#include <string.h>
#include <stdio.h>
#include <limits.h>

#include "scene.h"
#include "engine/sequences.h"
#include "engine/console.h"


Entity create_entity(const EntityType* type) {
    return (Entity) {
        .type = type,
        .health = type->health,
        .did_action = 0
    };
}


size_t tile_state_add(SceneTileState* tile, Entity entity) {
    vector_push(&tile->entities, &entity);
    return tile->entities.size - 1;
}

unsigned short tile_state_used_capacity(SceneTileState* tile) {
    unsigned short used = 0;
    for(size_t i = 0; i < tile->entities.size; i += 1) {
        Entity* e = tile_state_get(tile, i);
        used += e->type->size;
    }
    return used;
}

Entity* tile_state_get(SceneTileState* tile, size_t index) {
    return vector_get(&tile->entities, index);
}

void tile_state_remove(SceneTileState* tile, size_t index) {
    for(size_t moved = index + 1; moved < tile->entities.size; moved += 1) {
        vector_set(&tile->entities, moved - 1, vector_get(&tile->entities, moved));
    }
    vector_pop(&tile->entities);
}


Scene scene_new(unsigned long stage_number, const SceneTile*** tiles, size_t tiles_x, size_t tiles_y, unsigned char has_fog, const Commander* enemy_commander) {
    Scene new;
    new.stage_number = stage_number;
    new.tiles = tiles;
    new.tile_states = malloc(sizeof(SceneTileState) * tiles_x * tiles_y);
    new.tiles_x = tiles_x;
    new.tiles_y = tiles_y;
    new.enemy_commander = enemy_commander;
    new.objects = vector_new(sizeof(SceneObject));
    new.camera_ox = 0;
    new.camera_oy = 0;
    new.has_fog = has_fog;
    for(size_t y = 0; y < new.tiles_y; y += 1) {
        for(size_t x = 0; x < new.tiles_x; x += 1) {
            const SceneTile* tile = new.tiles[y][x];
            (tile->generator)(&new, x, y);
            new.tile_states[y * new.tiles_x + x] = (SceneTileState) {
                .entities = vector_new(sizeof(Entity))
            };
        }
    }
    return new;
}

void scene_focus_on_tile(Scene* scene, signed int tile_x, signed int tile_y) {
    if(tile_x < 0) { tile_x += ((-tile_x) / scene->tiles_x + 1) * scene->tiles_x; }
    if(tile_y < 0) { tile_y += ((-tile_y) / scene->tiles_y + 1) * scene->tiles_y; }
    scene->camera_tile_x = tile_x % scene->tiles_x;
    scene->camera_tile_y = tile_y % scene->tiles_y;
    scene->camera_ox = - (scene->camera_tile_x * SCENE_TILE_WIDTH - (console_width() - SCENE_TILE_WIDTH) / 2);
    scene->camera_oy = - (scene->camera_tile_y * SCENE_TILE_HEIGHT - (console_height() - SCENE_TILE_HEIGHT) / 2);
    if(scene->camera_ox > 0) { scene->camera_ox = 0; }
    signed int limit_x = -((signed int) scene->tiles_x * SCENE_TILE_WIDTH - console_width());
    if(scene->camera_ox < limit_x) { scene->camera_ox = limit_x; }
    if(scene->camera_oy > 0) { scene->camera_oy = 0; }
    signed int limit_y = -((signed int) scene->tiles_y * SCENE_TILE_HEIGHT - console_height());
    if(scene->camera_oy < limit_y) { scene->camera_oy = limit_y; }
}

size_t scene_add(Scene* scene, const SceneObjectType* type, void* data) {
    SceneObject new = {
        .data = malloc(type->data_size),
        .type = type
    };
    memcpy(new.data, data, type->data_size);
    vector_push(&scene->objects, &new);
    return scene->objects.size - 1;
}

void* scene_get(Scene* scene, size_t index) {
    SceneObject* object = vector_get(&scene->objects, index);
    return object->data;
}

SceneTileState* scene_get_tile(Scene* scene, size_t x, size_t y) {
    return &scene->tile_states[y * scene->tiles_x + x];
}

const SceneTile* scene_get_tile_type(Scene* scene, size_t x, size_t y) {
    return scene->tiles[y][x];  
}

#define MIN(a, b) ((a) < (b)? (a) : (b))
#define MAX(a, b) ((a) > (b)? (a) : (b))

char scene_tile_has_fog(Scene* scene, size_t x, size_t y) {
    if(!scene->has_fog) { return 0; }
    for(unsigned int cy = 0; cy < scene->tiles_y; cy += 1) {
        for(unsigned int cx = 0; cx < scene->tiles_x; cx += 1) {
            SceneTileState* tile = scene_get_tile(scene, cx, cy);
            unsigned short tile_max_visual_acuity = 0;
            for(size_t e = 0; e < tile->entities.size; e += 1) {
                const EntityType* entity = tile_state_get(tile, e)->type;
                if(entity->visual_acuity < tile_max_visual_acuity) { continue; }
                tile_max_visual_acuity = entity->visual_acuity;
            }
            unsigned int distance = (MAX(cx, x) - MIN(cx, x)) + (MAX(cy, y) - MIN(cy, y));
            if(distance < tile_max_visual_acuity) { return 0; }
        }
    }
    return 1;
}

#define FOG_GRADIENT_LENGTH_X 6.0
#define FOG_GRADIENT_LENGTH_Y 3.0

void render_fog(RenderBuffer* buffer, Scene* scene, unsigned int tile_x, unsigned int tile_y, char above_has_fog, char below_has_fog, char left_has_fog, char right_has_fog) {
    for(unsigned int y = 0; y < SCENE_TILE_HEIGHT; y += 1) {
        for(unsigned int x = 0; x < SCENE_TILE_WIDTH; x += 1) {
            double density = 1.0;
            if(!above_has_fog) { density = MIN(density, MIN((double) y / FOG_GRADIENT_LENGTH_Y, 1.0)); }
            if(!below_has_fog) { density = MIN(density, MIN((double) (SCENE_TILE_HEIGHT - y) / FOG_GRADIENT_LENGTH_Y, 1.0)); }
            if(!left_has_fog) { density = MIN(density, MIN((double) x / FOG_GRADIENT_LENGTH_X, 1.0)); }
            if(!right_has_fog) { density = MIN(density, MIN((double) (SCENE_TILE_WIDTH - x) / FOG_GRADIENT_LENGTH_X, 1.0)); }
            if((double) rand() / (double) RAND_MAX < density) {
                write_onto_buffer(buffer, tile_x * SCENE_TILE_WIDTH + x + scene->camera_ox, tile_y * SCENE_TILE_HEIGHT + y + scene->camera_oy, " ", SHRT_MAX);
            }
        }
    }
}

void scene_render(Scene* scene, RenderBuffer* buffer) {
    for(size_t i = 0; i < scene->objects.size; i += 1) {
        SceneObject* object = vector_get(&scene->objects, i);
        (object->type->render_h)(object->data, scene, buffer);
    }
    char tiles_have_fog[scene->tiles_y][scene->tiles_x];
    for(size_t y = 0; y < scene->tiles_y; y += 1) {
        for(size_t x = 0; x < scene->tiles_x; x += 1) {
            tiles_have_fog[y][x] = scene_tile_has_fog(scene, x, y);
        }
    }
    for(size_t y = 0; y < scene->tiles_y; y += 1) {
        for(size_t x = 0; x < scene->tiles_x; x += 1) {
            SceneTileState* tile_state = scene_get_tile(scene, x, y);
            for(size_t e = 0; e < tile_state->entities.size; e += 1) {
                Entity* entity = tile_state_get(tile_state, e);
                int ox = rand() % SCENE_TILE_WIDTH;
                int oy = rand() % SCENE_TILE_HEIGHT;
                render_object(buffer, entity->type->render_object, x * SCENE_TILE_WIDTH + ox + scene->camera_ox, y * SCENE_TILE_HEIGHT + oy + scene->camera_oy);
            }
            if(tiles_have_fog[y][x]) { render_fog(buffer, scene, x, y,
                y     > 0?              tiles_have_fog[y - 1][x] : 1,
                y + 1 < scene->tiles_y? tiles_have_fog[y + 1][x] : 1,
                x     > 0?              tiles_have_fog[y][x - 1] : 1,
                x + 1 < scene->tiles_x? tiles_have_fog[y][x + 1] : 1
            ); }
        }
    }
}

void scene_delete(Scene* scene, size_t index) {
    SceneObject* object = vector_get(&scene->objects, index);
    (object->type->delete_h)(object->data);
    free(object->data);
    for(size_t i = index; i < scene->objects.size - 1; i += 1) {
        vector_set(&scene->objects, i, vector_get(&scene->objects, i + 1));
    }
    vector_pop(&scene->objects);
}

void scene_free(Scene* scene) {
    for(size_t i = 0; i < scene->objects.size; i += 1) {
        SceneObject* object = vector_get(&scene->objects, i);
        (object->type->delete_h)(object->data);
        free(object->data);
    }
    free(scene->tile_states);
    vector_free(&scene->objects);
}


SceneIterator scenei_new(Scene* scene, const SceneObjectType* type, size_t* output) {
    SceneIterator new;
    new.scene = scene;
    new.current_index = 0;
    new.type = type;
    new.output = output;
    return new;
}

char scenei_next(SceneIterator* scenei) {
    while(scenei->current_index < scenei->scene->objects.size) {
        SceneObject* current = vector_get(&scenei->scene->objects, scenei->current_index);
        if(current->type == scenei->type) {
            *scenei->output = scenei->current_index;
            return 1;
        }
        scenei->current_index += 1;
    }
    return 0;
}