
#pragma once

#include "definitions.h"
#include "../../scene.h"

// village_objects.c

DEF_OBJECT(PATH, Path, path, { int x; int y; }, (Scene* scene, int x, int y));
DEF_OBJECT_PROP(FENCE_H, FenceH, fenceh);
DEF_OBJECT_PROP(HUT, Hut, hut);
//DEF_OBJECT_PROP(WELL, Well, well);

// village_tiles.c

DEF_TILE(VILLAGE_HUT);
DEF_TILE(VILLAGE_FIELD);
DEF_TILE(VILLAGE_PATH_LR);
DEF_TILE(VILLAGE_PATH_TB);
DEF_TILE(VILLAGE_PATH_TL);
DEF_TILE(VILLAGE_PATH_TR);
DEF_TILE(VILLAGE_PATH_BL);
DEF_TILE(VILLAGE_PATH_BR);
DEF_TILE(VILLAGE_PATH_3T);
DEF_TILE(VILLAGE_PATH_3B);
DEF_TILE(VILLAGE_PATH_3L);
DEF_TILE(VILLAGE_PATH_3R);
DEF_TILE(VILLAGE_PATH_X);

// farm_objects.c

DEF_OBJECT_PROP(TOMATO, Tomato, tomato);

// troops.c

DEF_ENTITY(FARMER);
DEF_ENTITY(KNIGHT);
DEF_ENTITY(ARCHER);
DEF_ENTITY(DIGGER);