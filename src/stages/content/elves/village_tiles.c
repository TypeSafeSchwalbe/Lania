
#include "../nature.h"
#include "../elves.h"


IMPL_TILE(ELVEN_VILLAGE_HUT, elven_village_hut, {
    scene_add_elven_hut(scene, pos_x + rand() % SCENE_TILE_WIDTH, pos_y + rand() % SCENE_TILE_HEIGHT);
    for(int t = 0; t < 2; t += 1) {
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
}, 0);
