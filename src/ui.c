
#include <stdio.h>
#include <string.h>
#include <limits.h>

#include "ui.h"
#include "stages/stages.h"
#include "engine/sequences.h"
#include "engine/console.h"
#include "engine/format.h"


void select_stage(SaveGame* savegame, Scene* scene) {
    signed long scenes_on_screen = console_height() - 4;
    signed long selected = 0;
    signed long max_selectable = (savegame->unlocked_stages < STAGE_COUNT? savegame->unlocked_stages : STAGE_COUNT) - 1;
    char done = 0;
    while(!done) {
        console_clear();
        puts("\nSelect a stage using [Up] and [Down]; confirm with [Enter].\n");
        signed long start = selected - (scenes_on_screen / 2);
        if(start < 0) { start = 0; }
        size_t end = start + scenes_on_screen;
        if(end >= STAGE_COUNT) { end = STAGE_COUNT; }
        for(size_t s = start; s < end; s += 1) {
            if(s < savegame->unlocked_stages) {
                printf("%s %s %s\n", (signed long) s == selected? S_WHITE_BG S_BLACK_FG : "", STAGES[s]->name, S_RESET);
            } else {
                puts(S_RED_BG " locked " S_RESET);
            }
        }
        switch(console_read_char()) {
            case '\n': done = 1; break;
            case '\033': {
                console_read_char();
                switch(console_read_char()) {
                    case 'A': selected -= 1; break;
                    case 'B': selected += 1; break;
                }
            } break;
        }
        if(selected < 0) { selected = max_selectable; }
        if(selected > max_selectable) { selected = 0; }
    }
    scene_free(scene);
    *scene = (STAGES[selected]->generator)(selected);
    
    if(STAGES[selected]->story != NULL) {
        console_clear();
        printf("\n%s\n\nContinue by pressing any key. ", STAGES[selected]->story);
        fflush(stdout);
        console_read_char();
    }
}


void stage_end_screen(const char* text, char unlock_next_stage, SaveGame* savegame, Scene* scene) {
    console_clear();
    puts(text);
    if(unlock_next_stage && scene->stage_number >= savegame->unlocked_stages - 1) {
        savegame->unlocked_stages += 1;
        if(savegame->unlocked_stages > STAGE_COUNT) { savegame->unlocked_stages = STAGE_COUNT; }
        else { printf("As a result, the stage '%s' was unlocked.\n\n", STAGES[savegame->unlocked_stages - 1]->name); }
        store_savegame(savegame);
    }
    printf("Press any key to continue. ");
    fflush(stdout);
    console_read_char();
    select_stage(savegame, scene);
}


int expected_main_buffer_width() { return console_width(); }
int expected_main_buffer_height() { return console_height() - 1; }

void update_main_buffer_size(RenderBuffer* buffer) {
    if(buffer->width != expected_main_buffer_width() || buffer->height != expected_main_buffer_height()) {
        free_buffer(buffer);
        *buffer = make_buffer(expected_main_buffer_width(), expected_main_buffer_height());
    }
}


void render_selected_tile(RenderBuffer* buffer, Scene* scene, unsigned int tile_x, unsigned int tile_y, const char* coloring) {
    size_t coloring_size = strlen(coloring);
    size_t char_buffer_size = coloring_size + 1 + strlen(S_RESET);
    char char_buffer[char_buffer_size + 1];
    memcpy(char_buffer, coloring, coloring_size);
    char_buffer[coloring_size] = ' ';
    strcpy(char_buffer + coloring_size + 1, S_RESET);
    for(size_t y = 0; y < SCENE_TILE_HEIGHT; y += 1) {
        for(size_t x = 0; x < SCENE_TILE_WIDTH; x += 1) {
            if(x != 0 && x != SCENE_TILE_WIDTH - 1 && y != 0 && y != SCENE_TILE_HEIGHT - 1) { continue; }
            write_onto_buffer(buffer, tile_x * SCENE_TILE_WIDTH + x + scene->camera_ox, tile_y * SCENE_TILE_HEIGHT + y + scene->camera_oy, char_buffer, tile_y * SCENE_TILE_HEIGHT + y + scene->camera_oy - 1);
        }
    }
}


const Action* select_tile_action(RenderBuffer* buffer, Scene* scene, unsigned int tile_x, unsigned int tile_y) {
    size_t selected_action = 0;
    update_main_buffer_size(buffer);
    clear_buffer(buffer);
    scene_render(scene, buffer);
    for(;;) {
        signed int pos_x = tile_x * SCENE_TILE_WIDTH + scene->camera_ox;
        signed int pos_y = tile_y * SCENE_TILE_HEIGHT + scene->camera_oy;
        for(size_t a = 0; a < ACTION_COUNT; a += 1) {
            const Action* action = ACTIONS[a];
            FORMAT(displayed, displayed_length, " %s ", action->name);
            write_line_onto_buffer(buffer, pos_x + 2, pos_y + 1 + a, a == selected_action? S_WHITE_BG S_BLACK_FG : "", displayed, S_RESET, displayed_length, SHRT_MAX);
        }
        console_clear();
        print_buffer(buffer);
        switch(console_read_char()) {
            case '\033': {
                console_read_char();
                switch(console_read_char()) {
                    case 'A': selected_action += (selected_action == 0? (signed long) ACTION_COUNT - 1 : -1); continue;
                    case 'B': selected_action -= (selected_action == ACTION_COUNT - 1? (signed long) ACTION_COUNT - 1 : -1); continue;
                }
            } break;
            case '\n': {
                return ACTIONS[selected_action];
            } break;
        }
        break;
    }
    return NULL;
}


const EntityType* select_tile_troop_type(RenderBuffer* buffer, Scene* scene, unsigned int tile_x, unsigned int tile_y) {
    SceneTileState* tile_state = scene_get_tile(scene, tile_x, tile_y);
    Vector troop_types = vector_new(sizeof(const EntityType*));
    for(size_t e = 0; e < tile_state->entities.size; e += 1) {
        Entity* entity = tile_state_get(tile_state, e);
        if(entity->did_action || entity->type->is_enemy) { continue; }
        char found = 0;
        for(size_t t = 0; t < troop_types.size; t += 1) {
            const EntityType** type = vector_get(&troop_types, t);
            if(*type != entity->type) { continue; }
            found = 1;
            break;
        }
        if(found) { continue; }
        vector_push(&troop_types, &entity->type);
    }
    if(troop_types.size == 0) { return NULL; }
    size_t selected_type = 0;
    update_main_buffer_size(buffer);
    clear_buffer(buffer);
    scene_render(scene, buffer);
    for(;;) {
        signed int pos_x = tile_x * SCENE_TILE_WIDTH + scene->camera_ox;
        signed int pos_y = tile_y * SCENE_TILE_HEIGHT + scene->camera_oy;
        for(size_t t = 0; t < troop_types.size; t += 1) {
            const EntityType** troop_type = vector_get(&troop_types, t);
            FORMAT(displayed, displayed_length, " %s ", (*troop_type)->name);
            write_line_onto_buffer(buffer, pos_x + 2, pos_y + 1 + t, t == selected_type? S_WHITE_BG S_BLACK_FG : "", displayed, S_RESET, displayed_length, SHRT_MAX);
        }
        console_clear();
        print_buffer(buffer);
        switch(console_read_char()) {
            case '\033': {
                console_read_char();
                switch(console_read_char()) {
                    case 'A': selected_type += (selected_type == 0? (signed long) troop_types.size - 1 : -1); continue;
                    case 'B': selected_type -= (selected_type == troop_types.size - 1? (signed long) troop_types.size - 1 : -1); continue;
                }
            } break;
            case '\n': {
                const EntityType* selected = *((const EntityType**) vector_get(&troop_types, selected_type));
                vector_free(&troop_types);
                return selected;
            } break;
        }
        break;
    }
    vector_free(&troop_types);
    return NULL;
}

char select_tile_troop_count(RenderBuffer* buffer, Scene* scene, unsigned int tile_x, unsigned int tile_y, const EntityType* troop_type, size_t* selected_count) {
    SceneTileState* tile_state = scene_get_tile(scene, tile_x, tile_y);
    size_t available_count = 0;
    for(size_t e = 0; e < tile_state->entities.size; e += 1) {
        Entity* entity = tile_state_get(tile_state, e);
        if(entity->type == troop_type && !entity->did_action) { available_count += 1; }
    }
    if(available_count == 0) { return 0; }
    *selected_count = available_count;
    update_main_buffer_size(buffer);
    clear_buffer(buffer);
    scene_render(scene, buffer);
    for(;;) {
        signed int pos_x = tile_x * SCENE_TILE_WIDTH + scene->camera_ox;
        signed int pos_y = tile_y * SCENE_TILE_HEIGHT + scene->camera_oy;
        write_line_onto_buffer(buffer, pos_x + 2, pos_y + 1, S_WHITE_BG S_BLACK_FG, " + ", S_RESET, 3, SHRT_MAX);
        FORMAT(displayed_number, displayed_number_length, " %lu ", *selected_count);
        write_line_onto_buffer(buffer, pos_x + 2, pos_y + 2, S_WHITE_BG S_BLACK_FG, displayed_number, S_RESET, displayed_number_length, SHRT_MAX);
        write_line_onto_buffer(buffer, pos_x + 2, pos_y + 3, S_WHITE_BG S_BLACK_FG, " - ", S_RESET, 3, SHRT_MAX);
        console_clear();
        print_buffer(buffer);
        switch(console_read_char()) {
            case '\033': {
                console_read_char();
                switch(console_read_char()) {
                    case 'A': *selected_count -= (*selected_count == available_count? (signed long) available_count - 1 : -1); continue;
                    case 'B': *selected_count += (*selected_count == 1? (signed long) available_count - 1 : -1); continue;
                }
            } break;
            case '\n': {
                return 1;
            } break;
        }
        break;
    }
    return 0;
}

char select_destination_tile(RenderBuffer* buffer, Scene* scene, unsigned int tile_x, unsigned int tile_y, const EntityType* troop_type, size_t troop_count, TileValidator tile_validator, unsigned int* selected_x, unsigned int* selected_y) {
    *selected_x = tile_x;
    *selected_y = tile_y;
    for(;;) {
        update_main_buffer_size(buffer);
        clear_buffer(buffer);
        scene_render(scene, buffer);
        char is_valid = (tile_validator)(scene, tile_x, tile_y, troop_type, troop_count, *selected_x, *selected_y);
        render_selected_tile(buffer, scene, scene->camera_tile_x, scene->camera_tile_y, S_WHITE_BG);
        render_selected_tile(buffer, scene, *selected_x, *selected_y, is_valid? S_GREEN_BG : S_RED_BG);
        console_clear();
        print_buffer(buffer);
        switch(console_read_char()) {
            case '\033': {
                console_read_char();
                signed long new_selected_x = *selected_x;
                signed long new_selected_y = *selected_y;
                switch(console_read_char()) {
                    case 'A': new_selected_y -= 1; break;
                    case 'B': new_selected_y += 1; break;
                    case 'D': new_selected_x -= 1; break;
                    case 'C': new_selected_x += 1; break;
                }
                scene_focus_on_tile(scene, new_selected_x, new_selected_y);
                *selected_x = scene->camera_tile_x;
                *selected_y = scene->camera_tile_y;
                scene->camera_tile_x = tile_x;
                scene->camera_tile_y = tile_y;
                continue;
            } break;
            case '\n': {
                if(!is_valid) { continue; }
                return 1;
            } break;
        }
        break;
    }
    return 0;
}