
#pragma once

#include "../scene.h"
#include "../savegame.h"


typedef Scene (*StageGenerator)(unsigned long stage_number);

typedef struct Stage {
    StageGenerator generator;
    const char* name;
    const char* story;
} Stage;


#define DEF_STAGE(code_name) \
    extern const Stage STAGE_##code_name;

#define IMPL_STAGE(code_name, code_name_lower, tiles, tiles_x, tiles_y, commander, generator_body, displayed_name, displayed_story) \
    const SceneTile*** STAGE_##code_name##_TILES = tiles; \
    Scene stage_##code_name_lower##_generate(unsigned long stage_number) { \
        Scene self = scene_new(stage_number, STAGE_##code_name##_TILES, tiles_x, tiles_y, &commander); \
        generator_body; \
        return self; \
    } \
    const Stage STAGE_##code_name = { \
        .generator = &stage_##code_name_lower##_generate, \
        .name = displayed_name, \
        .story = displayed_story \
    };


void stage_summon_troops(Scene* scene, size_t tile_x, size_t tile_y, const EntityType* e_type, size_t count);


DEF_STAGE(BATTLE_OF_ABIL);
DEF_STAGE(EASTERNMOST_CLEARING);
DEF_STAGE(THICK_THICKETS);

DEF_STAGE(SCRAMBLED_PASSES);
DEF_STAGE(ABANDONED_RUBY_MINE);
DEF_STAGE(ENDLESS_DESERT_PLAIN);

DEF_STAGE(ENCHANTED_LAKE);
DEF_STAGE(ELVEN_VILLAGE);
DEF_STAGE(NARROW_RIVER_FORD);


extern const size_t STAGE_COUNT;
extern const Stage* STAGES[];