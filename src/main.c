
#include <stdio.h>
#include <time.h>
#include <string.h>

#include "ui.h"
#include "engine/console.h"
#include "engine/sequences.h"
#include "stages/stages.h"


void end_turn(SaveGame* savegame, Scene* scene, RenderBuffer* buffer) { 
    char goblins_won = 0;
    for(size_t y = 0; y < scene->tiles_y && !goblins_won; y += 1) {
        for(size_t x = 0; x < scene->tiles_x && !goblins_won; x += 1) {
            SceneTileState* tile = scene_get_tile(scene, x, y);
            if(tile->entities.size == 0) { continue; }
            if(!tile_state_get(tile, 0)->type->is_enemy) { continue; }
            (scene->enemy_commander->tactic)(scene, x, y);

            goblins_won = 1;
            for(size_t y = 0; y < scene->tiles_y && goblins_won; y += 1) {
                for(size_t x = 0; x < scene->tiles_x && goblins_won; x += 1) {
                    SceneTileState* tile = scene_get_tile(scene, x, y);
                    if(tile->entities.size == 0) { continue; }
                    if(!tile_state_get(tile, 0)->type->is_enemy) { goblins_won = 0; }
                }
            }
            if(goblins_won) {
                stage_end_screen(1, savegame, scene);
            }
        }
    }
    for(size_t y = 0; y < scene->tiles_y; y += 1) {
        for(size_t x = 0; x < scene->tiles_x; x += 1) {
            SceneTileState* tile = scene_get_tile(scene, x, y);
            for(size_t e = 0; e < tile->entities.size; e += 1) {
                tile_state_get(tile, e)->did_action = 0;
            }
        }
    }
}

void gameloop(SaveGame* savegame, Scene* scene, RenderBuffer* buffer) {
    const char* DONE_TEXT = "done";
    unsigned char done_typed_i = 0;
    for(;;) {
        update_main_buffer_size(buffer);
        clear_buffer(buffer);
        scene_render(scene, buffer);
        render_selected_tile(buffer, scene, scene->camera_tile_x, scene->camera_tile_y, S_WHITE_BG);
        console_clear();
        print_buffer(buffer);
        printf("Type 'done' to end your turn. ");
        int c = console_read_char();
        if(c == '\033') {
            console_read_char();
            signed int new_tile_x = scene->camera_tile_x;
            signed int new_tile_y = scene->camera_tile_y;
            switch(console_read_char()) {
                case 'A': new_tile_y -= 1; break;
                case 'B': new_tile_y += 1; break;
                case 'D': new_tile_x -= 1; break;
                case 'C': new_tile_x += 1; break;
            }
            scene_focus_on_tile(scene, new_tile_x, new_tile_y);
        }
        if(c == '\n') {
            const Action* action = select_tile_action(buffer, scene, scene->camera_tile_x, scene->camera_tile_y);
            if(action == NULL) { continue; }
            (action->handler)(savegame, buffer, scene, scene->camera_tile_x, scene->camera_tile_y);
        }
        if(c == DONE_TEXT[done_typed_i]) {
            done_typed_i += 1;
            if(done_typed_i >= strlen(DONE_TEXT)) {
                end_turn(savegame, scene, buffer);
                done_typed_i = 0;
            }
        } else {
            done_typed_i = 0;
        }
    }
}

int main() {
    srand(time(NULL));
    console_init();
    console_set_raw(1);

    SaveGame savegame = load_savegame();
    Scene scene = (STAGES[0]->generator)(0);

    select_stage(&savegame, &scene);

    RenderBuffer buffer = make_buffer(expected_main_buffer_width(), expected_main_buffer_height());

    gameloop(&savegame, &scene, &buffer);

    scene_free(&scene);
    free_buffer(&buffer);

    console_set_raw(0);
    return 0;
}