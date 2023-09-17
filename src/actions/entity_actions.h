
#pragma once

#include "../scene.h"


void entities_move(Scene* scene, unsigned int from_x, unsigned int from_y, const EntityType* troop_type, size_t troop_count, unsigned int dest_x, unsigned int dest_y);

void entities_attack(Scene* scene, unsigned int from_x, unsigned int from_y, const EntityType* troop_type, size_t troop_count, unsigned int dest_x, unsigned int dest_y);