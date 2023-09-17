
#include <math.h>

#include "../nature.h"
#include "../humans.h"


IMPL_TILE(VILLAGE_HUT, village_hut, {
    scene_add_hut   (scene, pos_x +  5, pos_y + 6);
    scene_add_fenceh(scene, pos_x,      pos_y + 9);
    scene_add_fenceh(scene, pos_x +  7, pos_y + 9);
    scene_add_tree  (scene, pos_x + 21, pos_y + 6);
    scene_add_path  (scene, pos_x + 16, pos_y + 11);
    scene_add_path  (scene, pos_x + 21, pos_y + 11);
    scene_add_tomato(scene, pos_x + 18, pos_y + 12);
    scene_add_tomato(scene, pos_x + 23, pos_y + 12);
    scene_add_fenceh(scene, pos_x + 13, pos_y + 15);
    scene_add_fenceh(scene, pos_x + 20, pos_y + 15);
    scene_add_tree  (scene, pos_x +  5, pos_y + 14);
}, 0);


#define PATH_WIDTH 5
#define PATH_HEIGHT 3

#define MIN(a, b) ((a) < (b)? (a) : (b))
#define MAX(a, b) ((a) > (b)? (a) : (b))


IMPL_TILE(VILLAGE_FIELD, village_field, {
    for(int y = 0; y < (int) ceil((double) SCENE_TILE_HEIGHT / PATH_HEIGHT); y += 1) {
        for(int x = 0; x < (int) ceil((double) SCENE_TILE_WIDTH / PATH_WIDTH); x += 1) {
            scene_add_path(scene, pos_x + MIN(x * PATH_WIDTH, SCENE_TILE_WIDTH - PATH_WIDTH), pos_y + MIN(y * PATH_HEIGHT, SCENE_TILE_HEIGHT - PATH_HEIGHT));
        }
    }
    for(int p = 0; p < 20; p += 1) {
        scene_add_tomato(scene, pos_x + rand() % SCENE_TILE_WIDTH, pos_y + rand() % SCENE_TILE_HEIGHT);
    }
}, 5);


#define PATH_RANDOM_OFFSET(x) (((x) % 2 == 0 || rand() % 2 == 0)? 0 : (rand() % 2 == 0)? -1 : 1)

void path_left(Scene* scene, size_t pos_x, size_t pos_y) {
    for(int s = 0; s < (int) ceil((SCENE_TILE_WIDTH / 2.0) / PATH_WIDTH); s += 1) {
        scene_add_path(scene, pos_x + MIN(PATH_WIDTH * s, SCENE_TILE_WIDTH / 2 - PATH_WIDTH), pos_y + (SCENE_TILE_HEIGHT - PATH_HEIGHT) / 2 + PATH_RANDOM_OFFSET(s));
    }
}

void path_right(Scene* scene, size_t pos_x, size_t pos_y) {
    for(int s = 0; s < (int) ceil((SCENE_TILE_WIDTH / 2.0) / PATH_WIDTH); s += 1) {
        scene_add_path(scene, pos_x + (SCENE_TILE_WIDTH - PATH_WIDTH - MIN(PATH_WIDTH * s, SCENE_TILE_WIDTH / 2 - PATH_WIDTH)), pos_y + (SCENE_TILE_HEIGHT - PATH_HEIGHT) / 2 + PATH_RANDOM_OFFSET(s));
    }
}

void path_top(Scene* scene, size_t pos_x, size_t pos_y) {
    for(int s = 0; s < (int) ceil((SCENE_TILE_HEIGHT / 2.0) / PATH_HEIGHT); s += 1) {
        scene_add_path(scene, pos_x + (SCENE_TILE_WIDTH - PATH_WIDTH) / 2 + PATH_RANDOM_OFFSET(s), pos_y + MIN(PATH_HEIGHT * s, SCENE_TILE_HEIGHT / 2 - PATH_HEIGHT));
    }
}

void path_bottom(Scene* scene, size_t pos_x, size_t pos_y) {
    for(int s = 0; s < (int) ceil((SCENE_TILE_HEIGHT / 2.0) / PATH_HEIGHT); s += 1) {
        scene_add_path(scene, pos_x + (SCENE_TILE_WIDTH - PATH_WIDTH) / 2 + PATH_RANDOM_OFFSET(s), pos_y + (SCENE_TILE_HEIGHT - PATH_HEIGHT - MIN(PATH_HEIGHT * s, SCENE_TILE_HEIGHT / 2 - PATH_HEIGHT)));
    }
}

IMPL_TILE(VILLAGE_PATH_LR, village_path_lr, {
    path_left(scene, pos_x, pos_y);
    path_right(scene, pos_x, pos_y);
}, 20);

IMPL_TILE(VILLAGE_PATH_TB, village_path_tb, {
    path_top(scene, pos_x, pos_y);
    path_bottom(scene, pos_x, pos_y);
}, 20);

IMPL_TILE(VILLAGE_PATH_TL, village_path_tl, {
    path_top(scene, pos_x, pos_y);
    path_left(scene, pos_x, pos_y);
}, 20);

IMPL_TILE(VILLAGE_PATH_TR, village_path_tr, {
    path_top(scene, pos_x, pos_y);
    path_right(scene, pos_x, pos_y);
}, 20);

IMPL_TILE(VILLAGE_PATH_BL, village_path_bl, {
    path_bottom(scene, pos_x, pos_y);
    path_left(scene, pos_x, pos_y);
}, 20);

IMPL_TILE(VILLAGE_PATH_BR, village_path_br, {
    path_bottom(scene, pos_x, pos_y);
    path_right(scene, pos_x, pos_y);
}, 20);

IMPL_TILE(VILLAGE_PATH_3T, village_path_3t, {
    path_bottom(scene, pos_x, pos_y);
    path_left(scene, pos_x, pos_y);
    path_right(scene, pos_x, pos_y);
}, 20);

IMPL_TILE(VILLAGE_PATH_3B, village_path_3b, {
    path_top(scene, pos_x, pos_y);
    path_left(scene, pos_x, pos_y);
    path_right(scene, pos_x, pos_y);
}, 20);

IMPL_TILE(VILLAGE_PATH_3L, village_path_3l, {
    path_top(scene, pos_x, pos_y);
    path_bottom(scene, pos_x, pos_y);
    path_right(scene, pos_x, pos_y);
}, 20);

IMPL_TILE(VILLAGE_PATH_3R, village_path_3r, {
    path_top(scene, pos_x, pos_y);
    path_bottom(scene, pos_x, pos_y);
    path_left(scene, pos_x, pos_y);
}, 20);

IMPL_TILE(VILLAGE_PATH_X, village_path_x, {
    path_top(scene, pos_x, pos_y);
    path_bottom(scene, pos_x, pos_y);
    path_left(scene, pos_x, pos_y);
    path_right(scene, pos_x, pos_y);
}, 20);
