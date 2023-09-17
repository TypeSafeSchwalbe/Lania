
#include "../nature.h"


IMPL_TILE(FOREST, forest, {
    for(int t = 0; t < 5; t += 1) {
        scene_add_tree(scene, pos_x + rand() % SCENE_TILE_WIDTH, pos_y + rand() % SCENE_TILE_HEIGHT);
    }
    for(int g = 0; g < 10; g += 1) {
        scene_add_grass(scene, pos_x + rand() % SCENE_TILE_WIDTH, pos_y + rand() % SCENE_TILE_HEIGHT);
    }
    for(int f = 0; f < 15; f += 1) {
        scene_add_flower(scene, pos_x + rand() % SCENE_TILE_WIDTH, pos_y + rand() % SCENE_TILE_HEIGHT);
    }
}, 5);


IMPL_TILE(DENSE_FOREST, dense_forest, {
    for(int t = 0; t < 15; t += 1) {
        scene_add_tree(scene, pos_x + rand() % SCENE_TILE_WIDTH, pos_y + rand() % SCENE_TILE_HEIGHT);
    }
    for(int g = 0; g < 5; g += 1) {
        scene_add_grass(scene, pos_x + rand() % SCENE_TILE_WIDTH, pos_y + rand() % SCENE_TILE_HEIGHT);
    }
    for(int f = 0; f < 5; f += 1) {
        scene_add_flower(scene, pos_x + rand() % SCENE_TILE_WIDTH, pos_y + rand() % SCENE_TILE_HEIGHT);
    }
}, 0);


IMPL_TILE(MEADOW, meadow, {
    for(int g = 0; g < 15; g += 1) {
        scene_add_grass(scene, pos_x + rand() % SCENE_TILE_WIDTH, pos_y + rand() % SCENE_TILE_HEIGHT);
    }
    for(int f = 0; f < 20; f += 1) {
        scene_add_flower(scene, pos_x + rand() % SCENE_TILE_WIDTH, pos_y + rand() % SCENE_TILE_HEIGHT);
    }
}, 20);