
#include "actions.h"
#include "../ui.h"


char attack_tile_validator(Scene* scene, unsigned int start_x, unsigned int start_y, const EntityType* troop_type, size_t troop_count, unsigned int dest_x, unsigned int dest_y) {
    size_t distance = abs((int) dest_x - (int) start_x) + abs((int) dest_y - (int) start_y);
    if(distance < troop_type->attack_min_distance || distance > troop_type->attack_max_distance) { return 0; }
    SceneTileState* dest_state = scene_get_tile(scene, dest_x, dest_y);
    for(size_t e = 0; e < dest_state->entities.size; e += 1) {
        Entity* entity = tile_state_get(dest_state, e);
        if(!entity->type->is_enemy) { return 0; }
    }
    return 1;
}

void entities_attack(Scene* scene, unsigned int from_x, unsigned int from_y, const EntityType* troop_type, size_t troop_count, unsigned int dest_x, unsigned int dest_y) {
    SceneTileState* from_state = scene_get_tile(scene, from_x, from_y);
    SceneTileState* dest_state = scene_get_tile(scene, dest_x, dest_y);
    size_t did_attack = 0;
    for(size_t e = 0; e < from_state->entities.size && did_attack < troop_count; e += 1) {
        Entity* entity = tile_state_get(from_state, e);
        if(entity->type != troop_type) { continue; }
        size_t attacked_entities = 0;
        while(attacked_entities < troop_type->attack_size
        && dest_state->entities.size > 0) {
            size_t a = rand() % dest_state->entities.size;
            Entity* attacked = tile_state_get(dest_state, a);
            signed int new_health = attacked->health - troop_type->attack_strength;
            attacked_entities += 1;
            if(new_health <= 0) { tile_state_remove(dest_state, a); }
            else { attacked->health = new_health; }
        }
        entity->did_action = 1;
        did_attack += 1;
    }
}

IMPL_ACTION(ATTACK, attack, "Attack", {
    const EntityType* troop_type = select_tile_troop_type(buffer, scene, tile_x, tile_y);
    if(troop_type == NULL) { return; }
    size_t troop_count;
    if(!select_tile_troop_count(buffer, scene, tile_x, tile_y, troop_type, &troop_count)) { return; }
    unsigned int dest_x;
    unsigned int dest_y;
    if(!select_destination_tile(buffer, scene, tile_x, tile_y, troop_type, troop_count, &attack_tile_validator, &dest_x, &dest_y)) { return; }
    entities_attack(scene, tile_x, tile_y, troop_type, troop_count, dest_x, dest_y);
    scene_focus_on_tile(scene, dest_x, dest_y);
});