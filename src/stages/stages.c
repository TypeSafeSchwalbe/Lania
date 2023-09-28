
#include <stdio.h>

#include "stages.h"
#include "../engine/console.h"
#include "../engine/sequences.h"


void stage_summon_troops(Scene* scene, size_t tile_x, size_t tile_y, const EntityType* e_type, size_t count) {
    SceneTileState* target_tile = scene_get_tile(scene, tile_x, tile_y);
    for(size_t i = 0; i < count; i += 1) {
        tile_state_add(target_tile, create_entity(e_type));
    }
}


const size_t STAGE_COUNT = 10;

const Stage* STAGES[] = {
    &STAGE_BATTLE_OF_ABIL,
    &STAGE_EASTERNMOST_CLEARING,
    &STAGE_THICK_THICKETS,

    &STAGE_SCRAMBLED_PASSES,
    &STAGE_ABANDONED_RUBY_MINE,
    &STAGE_ENDLESS_DESERT_PLAIN,

    &STAGE_ENCHANTED_LAKE,
    &STAGE_ELVEN_VILLAGE,
    &STAGE_NARROW_RIVER_FORDS,

    &STAGE_REMOTE_OASIS
};