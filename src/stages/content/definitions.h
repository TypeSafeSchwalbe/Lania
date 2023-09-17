
#pragma once


#define DEF_OBJECT(otype_name, type_name, name, type_structure, constructor_args) \
    extern const SceneObjectType SCENE_OBJECT_##otype_name; \
    typedef struct type_name type_structure type_name; \
    size_t scene_add_##name constructor_args;

#define IMPL_OBJECT(otype_name, type_name, name, render_body, free_body, constructor_args, constructor_body) \
    void name##_render(type_name* self, Scene* scene, RenderBuffer* buffer) render_body; \
    void name##_free(type_name* self) free_body; \
    const SceneObjectType SCENE_OBJECT_##otype_name = { \
        .render_h = (void*) &name##_render, \
        .delete_h = (void*) &name##_free, \
        .data_size = sizeof(type_name) \
    }; \
    size_t scene_add_##name constructor_args { \
        type_name self; \
        constructor_body ; \
        return scene_add(scene, &SCENE_OBJECT_##otype_name, &self); \
    };


#define DEF_OBJECT_PROP(otype_name, type_name, name) \
    DEF_OBJECT(otype_name, type_name, name, { int x; int y; }, (Scene* scene, int x, int y))

#define IMPL_OBJECT_PROP(otype_name, type_name, name, render_obj) \
    const RenderObject otype_name##_RENDER_OBJECT = render_obj; \
    IMPL_OBJECT(otype_name, type_name, name, { \
        render_object(buffer, &otype_name##_RENDER_OBJECT, self->x + scene->camera_ox, self->y + scene->camera_oy); \
    }, {}, (Scene* scene, int x, int y), { \
        self.x = x; \
        self.y = y; \
    });


#define DEF_TILE(tile_name) \
    extern const SceneTile SCENE_TILE_##tile_name;

#define IMPL_TILE(tile_name, tile_name_lower, generator_body, capacity_number) \
    void scene_tile_##tile_name_lower##generator(Scene* scene, size_t tile_x, size_t tile_y) { \
        unsigned int pos_x = SCENE_TILE_WIDTH * tile_x; \
        unsigned int pos_y = SCENE_TILE_HEIGHT * tile_y; \
        generator_body; \
    }; \
    const SceneTile SCENE_TILE_##tile_name = { \
        .generator = &scene_tile_##tile_name_lower##generator, \
        .capacity = capacity_number \
    };


#define DEF_ENTITY(entity_name) \
    extern const EntityType ENTITY_##entity_name;

#define IMPL_ENTITY(entity_name, render_obj, p_name, p_size, p_speed, p_is_enemy, p_health, p_attack_strength, p_attack_size, p_attack_min_distance, p_attack_max_distance) \
    const RenderObject ENTITY_##entity_name##_RENDER_OBJECT = render_obj; \
    const EntityType ENTITY_##entity_name = { \
        .render_object = &ENTITY_##entity_name##_RENDER_OBJECT, \
        .name = p_name, \
        .size = p_size, \
        .speed = p_speed, \
        .is_enemy = p_is_enemy, \
        .health = p_health, \
        .attack_strength = p_attack_strength, \
        .attack_size = p_attack_size, \
        .attack_min_distance = p_attack_min_distance, \
        .attack_max_distance = p_attack_max_distance \
    };
    

#define DEF_COMMANDER(commander_name) \
    extern const Commander COMMANDER_##commander_name;

#define IMPL_COMMANDER(commander_name, commander_name_lower, commander_decision_body) \
    void commander_##commander_name_lower##_decision(Scene* scene, size_t x, size_t y) commander_decision_body; \
    const Commander COMMANDER_##commander_name = { \
        .tactic = &commander_##commander_name_lower##_decision \
    };
    