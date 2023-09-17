
#pragma once

#include "engine/vector.h"
#include "engine/rendering.h"


typedef struct Scene Scene;

#define SCENE_TILE_WIDTH 32
#define SCENE_TILE_HEIGHT 16

typedef void (*SceneTileGenerator)(Scene* scene, size_t tile_x, size_t tile_y);

typedef struct SceneTile {
    SceneTileGenerator generator;
    unsigned short capacity;
} SceneTile;


typedef struct EntityType {
    const RenderObject* render_object;
    const char* name;
    unsigned short size;
    unsigned char speed; // tiles the entity can move every turn
    char is_enemy;
    unsigned short health;
    unsigned short attack_strength; // health removed from attacked entity
    unsigned short attack_size; // total capacity that may be attacked with one hit
    unsigned char attack_min_distance;
    unsigned char attack_max_distance;
} EntityType;

typedef struct Entity {
    const EntityType* type;
    unsigned short health;
    char did_action;
} Entity;

Entity create_entity(const EntityType* type);


typedef struct SceneTileState {
    Vector entities;
} SceneTileState;

size_t tile_state_add(SceneTileState* tile, Entity entity);

unsigned short tile_state_used_capacity(SceneTileState* tile);

Entity* tile_state_get(SceneTileState* tile, size_t index);

void tile_state_remove(SceneTileState* tile, size_t index);


typedef void (*CommanderDecision)(Scene* scene, size_t tile_x, size_t tile_y);

typedef struct Commander {
    CommanderDecision tactic;
} Commander;


typedef struct Scene {
    const SceneTile*** tiles;
    SceneTileState* tile_states;
    size_t tiles_x;
    size_t tiles_y;
    const Commander* enemy_commander;
    Vector objects;
    signed int camera_ox;
    signed int camera_oy;
    unsigned int camera_tile_x;
    unsigned int camera_tile_y;
    unsigned long stage_number;
} Scene;

typedef void (*RenderHandler)(void*, Scene*, RenderBuffer*);
typedef void (*Deletehandler)(void*);

typedef struct SceneObjectType {
    RenderHandler render_h;
    Deletehandler delete_h;
    size_t data_size;
} SceneObjectType;

typedef struct SceneObject {
    const SceneObjectType* type;
    void* data;
} SceneObject;

Scene scene_new(unsigned long stage_number, const SceneTile*** tiles, size_t tiles_x, size_t tiles_y, const Commander* enemy_commander);

void scene_focus_on_tile(Scene* scene, signed int tile_x, signed int tile_y);

size_t scene_add(Scene* scene, const SceneObjectType* type, void* data);

void* scene_get(Scene* scene, size_t index);

SceneTileState* scene_get_tile(Scene* scene, size_t x, size_t y);

const SceneTile* scene_get_tile_type(Scene* scene, size_t x, size_t y);

void scene_render(Scene* scene, RenderBuffer* buffer);

void scene_delete(Scene* scene, size_t index);

void scene_free(Scene* scene);


typedef struct SceneIterator {
    Scene* scene;
    size_t current_index;
    const SceneObjectType* type;
    size_t* output;
} SceneIterator;

SceneIterator scenei_new(Scene* scene, const SceneObjectType* type, size_t* output);

char scenei_next(SceneIterator* scenei);