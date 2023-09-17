
#pragma once

#include "../scene.h"
#include "../savegame.h"


typedef void (*ActionHandler)(SaveGame* savegame, RenderBuffer* buffer, Scene* scene, unsigned int tile_x, unsigned int tile_y);

typedef struct Action {
    const char* name;
    ActionHandler handler;
} Action;


#define DEF_ACTION(def_name) \
    extern const Action ACTION_##def_name;

#define IMPL_ACTION(def_name, name_lower, name_val, handler_body) \
    void action_##name_lower##_handler(SaveGame* savegame, RenderBuffer* buffer, Scene* scene, unsigned int tile_x, unsigned int tile_y) handler_body; \
    const Action ACTION_##def_name = (Action) { \
        .name = name_val, \
        .handler = &action_##name_lower##_handler \
    };


DEF_ACTION(MOVE)
DEF_ACTION(ATTACK)
DEF_ACTION(INFO)


extern const size_t ACTION_COUNT;
extern const Action* ACTIONS[];
