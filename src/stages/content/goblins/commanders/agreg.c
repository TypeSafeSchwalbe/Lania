
#include <stdio.h>

#include "utils.h"


IMPL_COMMANDER(AGREG, agreg, {
    SceneTileState* tile = scene_get_tile(scene, x, y);
    signed char ox = 0;
    signed char oy = 0;
    if(tile_state_contains_humans(scene_get_tile_n(scene, x - 1, y))) { ox = -1; oy =  0; }
    if(tile_state_contains_humans(scene_get_tile_n(scene, x + 1, y))) { ox =  1; oy =  0; }
    if(tile_state_contains_humans(scene_get_tile_n(scene, x, y - 1))) { ox =  0; oy = -1; }
    if(tile_state_contains_humans(scene_get_tile_n(scene, x, y + 1))) { ox =  0; oy =  1; }
    const EntityType* e_type;
    GTIterator gti = gti_new(tile, &e_type);
    while(gti_next(&gti)) {
        if(tile_state_did_action(tile, e_type)) { continue; }
        size_t count = tile_state_type_count(tile, e_type);
        if(ox == 0 && oy == 0) {
            SceneTileState* otile = NULL;
            unsigned char t = 0;
            do {
                ox = rand() % 3 - 1;
                oy = rand() % 3 - 1;
                otile = scene_get_tile_n(scene, x + ox, y + oy);
                t += 1;
            } while(((ox == 0 && oy == 0)
            || (ox != 0 && oy != 0)
            || otile == NULL
            || otile == NULL
            || tile_state_contains_goblins(otile)
            || tile_state_contains_humans(otile)
            || e_type->size * count > scene_get_tile_type(scene, x + ox, y + oy)->capacity)
            && t < 100);
            if(t < 100) {
                entities_move(scene, x, y, e_type, count, x + ox, y + oy);
            }
        } else if(ox != 0 || oy != 0) {
            entities_attack(scene, x, y, e_type, count, x + ox, y + oy);
        }
    }
    gti_free(&gti);
});
