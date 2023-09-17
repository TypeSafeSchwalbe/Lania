
#include "../nature.h"


IMPL_TILE(CLIFF_FULL, cliff_full, {
    scene_add_cliff_full(scene, pos_x, pos_y);
}, 0);

IMPL_TILE(CLIFF_UP_LEFT, cliff_up_left, {
    scene_add_cliff_up_left(scene, pos_x, pos_y);
}, 0);

IMPL_TILE(CLIFF_UP_RIGHT, cliff_up_right, {
    scene_add_cliff_up_right(scene, pos_x, pos_y);
}, 0);

IMPL_TILE(CLIFF_DOWN_LEFT, cliff_down_left, {
    scene_add_cliff_down_left(scene, pos_x, pos_y);
}, 0);

IMPL_TILE(CLIFF_DOWN_RIGHT, cliff_down_right, {
    scene_add_cliff_down_right(scene, pos_x, pos_y);
}, 0);

IMPL_TILE(WATER, water, {
    scene_add_water(scene, pos_x, pos_y);
}, 0);