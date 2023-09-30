
#pragma once

#include "definitions.h"
#include "../../scene.h"


// forest

DEF_OBJECT_PROP(TREE, Tree, tree);
DEF_OBJECT_PROP(GRASS, Grass, grass);
DEF_OBJECT(FLOWER, Flower, flower, { int x; int y; unsigned char variant; }, (Scene* scene, int x, int y));

DEF_TILE(FOREST);
DEF_TILE(DENSE_FOREST);
DEF_TILE(MEADOW);

// desert

DEF_OBJECT_PROP(CACTUS, Cactus, cactus);
DEF_OBJECT_PROP(SHRUB, Shrub, shrub);
DEF_OBJECT(TUMBLEWEED, Tumbleweed, tumbleweed, { int x; int y; }, (Scene* scene, int x, int y));

DEF_TILE(DESERT);

// ground

DEF_OBJECT(CLIFF_FULL, CliffFull, cliff_full, { int x; int y; char*** cliff_data_v; char** cliff_data_h; char* cliff_data_f; }, (Scene* scene, int x, int y));
DEF_OBJECT(CLIFF_UP_LEFT, CliffUpLeft, cliff_up_left, { int x; int y; char*** cliff_data_v; char** cliff_data_h; char* cliff_data_f; }, (Scene* scene, int x, int y));
DEF_OBJECT(CLIFF_UP_RIGHT, CliffUpRight, cliff_up_right, { int x; int y; char*** cliff_data_v; char** cliff_data_h; char* cliff_data_f; }, (Scene* scene, int x, int y));
DEF_OBJECT(CLIFF_DOWN_LEFT, CliffDownLeft, cliff_down_left, { int x; int y; char*** cliff_data_v; char** cliff_data_h; char* cliff_data_f; }, (Scene* scene, int x, int y));
DEF_OBJECT(CLIFF_DOWN_RIGHT, CliffDownRight, cliff_down_right, { int x; int y; char*** cliff_data_v; char** cliff_data_h; char* cliff_data_f; }, (Scene* scene, int x, int y));
DEF_OBJECT(WATER, Water, water, { int x; int y; unsigned char is_deep; }, (Scene* scene, int x, int y, unsigned char is_deep));

DEF_TILE(CLIFF_FULL);
DEF_TILE(CLIFF_UP_LEFT);
DEF_TILE(CLIFF_UP_RIGHT);
DEF_TILE(CLIFF_DOWN_LEFT);
DEF_TILE(CLIFF_DOWN_RIGHT);
DEF_TILE(WATER);
DEF_TILE(FORD);

// magical

DEF_OBJECT_PROP(MAGICAL_TREE, MagicalTree, magical_tree);
DEF_OBJECT(FIREFLY, Firefly, firefly, { int x; int y; char dir; }, (Scene* scene, int x, int y));
DEF_OBJECT_PROP(MAGICAL_FLOWER, MagicalFlower, magical_flower);

DEF_TILE(MAGICAL_FOREST);
DEF_TILE(MAGICAL_MEADOW);
DEF_TILE(MAGICAL_WATER);

// badands

DEF_OBJECT_PROP(GIANT_BONES, GiantBones, giant_bones);
DEF_OBJECT_PROP(DEAD_TREE, DeadTree, dead_tree);

DEF_TILE(BADLANDS);
DEF_TILE(BADLANDS_BONES);