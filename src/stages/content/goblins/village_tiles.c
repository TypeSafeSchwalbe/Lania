
#include <math.h>

#include "../nature.h"
#include "../goblins.h"
#include "../humans.h"

#define PATH_WIDTH 5
#define PATH_HEIGHT 3

#define MIN(a, b) ((a) < (b)? (a) : (b))
#define MAX(a, b) ((a) > (b)? (a) : (b))


IMPL_TILE(GOBLIN_HUT, goblin_hut, {
    tile_state_add(scene_get_tile(scene, tile_x, tile_y), create_entity(&ENTITY_GOBLIN_HUT));
    scene_add_goblin_hut(scene, pos_x + rand() % SCENE_TILE_WIDTH, pos_y + rand() % SCENE_TILE_HEIGHT);
    scene_add_dead_tree(scene, pos_x + rand() % SCENE_TILE_WIDTH, pos_y + rand() % SCENE_TILE_HEIGHT);
    scene_add_shrub(scene, pos_x + rand() % SCENE_TILE_WIDTH, pos_y + rand() % SCENE_TILE_HEIGHT);
    if(rand() % 5 == 0) { scene_add_tumbleweed(scene, pos_x, pos_y); }
}, 0);

IMPL_ENTITY(GOBLIN_HUT, ((RenderObject) {
    .data = (char**[]) { 0 },
    .width = 0, .height = 0,
    .anchor_x = 0, .anchor_y = 0
}), "Goblin Hut",
    0, // size
    0, // speed
    1, // is enemy
    50, // health
    0, // attack strength
    0, // attack size
    0, // attack min distance
    0, // attack max distance
    0  // visibility distance
);