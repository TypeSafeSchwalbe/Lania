
#include "../nature.h"


IMPL_TILE(BADLANDS, badlands, {
    scene_add_dead_tree(scene, pos_x + rand() % SCENE_TILE_WIDTH, pos_y + rand() % SCENE_TILE_HEIGHT);
    scene_add_shrub(scene, pos_x + rand() % SCENE_TILE_WIDTH, pos_y + rand() % SCENE_TILE_HEIGHT);
    if(rand() % 5 == 0) { scene_add_tumbleweed(scene, pos_x, pos_y); }
}, 20);

IMPL_TILE(BADLANDS_BONES, badlands_bones, {
    scene_add_dead_tree(scene, pos_x + rand() % SCENE_TILE_WIDTH, pos_y + rand() % SCENE_TILE_HEIGHT);
    scene_add_shrub(scene, pos_x + rand() % SCENE_TILE_WIDTH, pos_y + rand() % SCENE_TILE_HEIGHT);
    if(rand() % 5 == 0) { scene_add_tumbleweed(scene, pos_x, pos_y); }
    scene_add_giant_bones(scene, pos_x + rand() % SCENE_TILE_WIDTH, pos_y + rand() % SCENE_TILE_HEIGHT);
}, 0);