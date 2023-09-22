
#include <math.h>

#include "../nature.h"
#include "../goblins.h"
#include "../humans.h"

#define PATH_WIDTH 5
#define PATH_HEIGHT 3

#define MIN(a, b) ((a) < (b)? (a) : (b))
#define MAX(a, b) ((a) > (b)? (a) : (b))


IMPL_TILE(GOBLIN_ROAD, goblin_road, {
    for(int y = 0; y < (int) ceil((double) SCENE_TILE_HEIGHT / PATH_HEIGHT); y += 1) {
        for(int x = 0; x < (int) ceil((double) SCENE_TILE_WIDTH / PATH_WIDTH); x += 1) {
            scene_add_path(scene, pos_x + MIN(x * PATH_WIDTH, SCENE_TILE_WIDTH - PATH_WIDTH), pos_y + MIN(y * PATH_HEIGHT, SCENE_TILE_HEIGHT - PATH_HEIGHT));
        }
    }
}, 50);