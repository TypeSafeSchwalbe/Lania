
#pragma once

#include "savegame.h"
#include "scene.h"
#include "engine/rendering.h"
#include "actions/actions.h"


void select_stage(SaveGame* savegame, Scene* scene);


#define NO_STAGE_UNLOCK 0
#define UNLOCK_NEXT_STAGE 1

void stage_end_screen(const char* text, char unlock_next_stage, SaveGame* savegame, Scene* scene);


int expected_main_buffer_width();
int expected_main_buffer_height();

void update_main_buffer_size(RenderBuffer* buffer);


void render_selected_tile(RenderBuffer* buffer, Scene* scene, unsigned int tile_x, unsigned int tile_y, const char* coloring);


const Action* select_tile_action(RenderBuffer* buffer, Scene* scene, unsigned int tile_x, unsigned int tile_y);

const EntityType* select_tile_troop_type(RenderBuffer* buffer, Scene* scene, unsigned int tile_x, unsigned int tile_y);

char select_tile_troop_count(RenderBuffer* buffer, Scene* scene, unsigned int tile_x, unsigned int tile_y, const EntityType* troop_type, size_t* selected_count);

typedef char (*TileValidator)(Scene* scene, unsigned int start_x, unsigned int start_y, const EntityType* troop_type, size_t troop_count, unsigned int dest_x, unsigned int dest_y);
char select_destination_tile(RenderBuffer* buffer, Scene* scene, unsigned int tile_x, unsigned int tile_y, const EntityType* troop_type, size_t troop_count, TileValidator tile_validator, unsigned int* selected_x, unsigned int* selected_y);