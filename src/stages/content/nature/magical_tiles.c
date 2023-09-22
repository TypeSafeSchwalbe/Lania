
#include "../nature.h"


IMPL_TILE(MAGICAL_FOREST, magical_forest, {
    for(int t = 0; t < 3; t += 1) {
        scene_add_magical_tree(scene, pos_x + rand() % SCENE_TILE_WIDTH, pos_y + rand() % SCENE_TILE_HEIGHT);
    }
    for(int f = 0; f < 20; f += 1) {
        scene_add_flower(scene, pos_x + rand() % SCENE_TILE_WIDTH, pos_y + rand() % SCENE_TILE_HEIGHT);
    }
    for(int f = 0; f < 5; f += 1) {
        scene_add_magical_flower(scene, pos_x + rand() % SCENE_TILE_WIDTH, pos_y + rand() % SCENE_TILE_HEIGHT);
    }
    if(rand() % 4 == 0) {
        int x = pos_x + rand() % SCENE_TILE_WIDTH;
        int y = pos_y + rand() % SCENE_TILE_HEIGHT;
        for(int f = 0; f < 5; f += 1) {
            scene_add_firefly(scene, x, y);
        }
    }
}, 5);

IMPL_TILE(MAGICAL_MEADOW, magical_meadow, {
    for(int f = 0; f < 50; f += 1) {
        scene_add_flower(scene, pos_x + rand() % SCENE_TILE_WIDTH, pos_y + rand() % SCENE_TILE_HEIGHT);
    }
    for(int f = 0; f < 5; f += 1) {
        scene_add_magical_flower(scene, pos_x + rand() % SCENE_TILE_WIDTH, pos_y + rand() % SCENE_TILE_HEIGHT);
    }
    if(rand() % 4 == 0) {
        int x = pos_x + rand() % SCENE_TILE_WIDTH;
        int y = pos_y + rand() % SCENE_TILE_HEIGHT;
        for(int f = 0; f < 5; f += 1) {
            scene_add_firefly(scene, x, y);
        }
    }
}, 20);

IMPL_TILE(MAGICAL_WATER, magical_water, {
    scene_add_water(scene, pos_x, pos_y, 1);
    if(rand() % 8 == 0) {
        int x = pos_x + rand() % SCENE_TILE_WIDTH;
        int y = pos_y + rand() % SCENE_TILE_HEIGHT;
        for(int f = 0; f < 5; f += 1) {
            scene_add_firefly(scene, x, y);
        }
    }
}, 0);