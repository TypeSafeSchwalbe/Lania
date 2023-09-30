
#pragma once

#include "definitions.h"
#include "../../scene.h"

// village_objects.c

DEF_OBJECT_PROP(GOBLIN_HUT, GoblinHut, goblin_hut);
DEF_OBJECT_PROP(GOBLIN_HUT_RUBBLE, GoblinHutRubble, goblin_hut_rubble);

// village_tiles.c

DEF_TILE(GOBLIN_HUT);

DEF_ENTITY(GOBLIN_HUT);

// troops.c

DEF_ENTITY(GOBLIN);
DEF_ENTITY(CYCLOPS);
DEF_ENTITY(SPEAR_GOBLIN);
DEF_ENTITY(DAGGER_GOBLIN);

// ./commanders

DEF_COMMANDER(AGREG);
DEF_COMMANDER(DUREG);
DEF_COMMANDER(OBREG);