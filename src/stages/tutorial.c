
#include "stages.h"
#include "content/tutorial.h"
#include "content/nature.h"
#include "content/humans.h"
#include "content/goblins.h"
#include "../ui.h"
#include "../engine/sequences.h"
#include "../engine/console.h"


#define VOID &SCENE_TILE_EMPTY
#define FRST &SCENE_TILE_FOREST
#define MDOW &SCENE_TILE_MEADOW
#define WATR &SCENE_TILE_WATER

IMPL_STAGE(TUTORIAL_SELECTION, tutorial_selection, ((const SceneTile**[]) {
    (const SceneTile*[]) { VOID, VOID, VOID, VOID, VOID, VOID, VOID, VOID, VOID },
    (const SceneTile*[]) { VOID, VOID, VOID, VOID, VOID, VOID, VOID, VOID, VOID },
    (const SceneTile*[]) { VOID, VOID, MDOW, VOID, VOID, VOID, VOID, VOID, VOID },
    (const SceneTile*[]) { VOID, MDOW, FRST, MDOW, VOID, VOID, FRST, MDOW, VOID },
    (const SceneTile*[]) { VOID, FRST, MDOW, VOID, VOID, VOID, WATR, FRST, VOID },
    (const SceneTile*[]) { VOID, VOID, MDOW, VOID, VOID, MDOW, MDOW, MDOW, VOID },
    (const SceneTile*[]) { VOID, VOID, VOID, VOID, VOID, VOID, MDOW, VOID, VOID },
    (const SceneTile*[]) { VOID, VOID, VOID, VOID, VOID, VOID, VOID, VOID, VOID },
    (const SceneTile*[]) { VOID, VOID, VOID, VOID, VOID, VOID, VOID, VOID, VOID }
}), 9, 9, FOG_DISABLED, NULL, {
    scene_focus_on_tile(&self, 2, 4);

    scene_add_hologram(&self, (int) (2.5 * SCENE_TILE_WIDTH), (int) (4.5 * SCENE_TILE_HEIGHT), "", "Change the currently");
    scene_add_hologram(&self, (int) (2.5 * SCENE_TILE_WIDTH), (int) (4.5 * SCENE_TILE_HEIGHT) + 1, "", "selected tile with");
    scene_add_hologram(&self, (int) (2.5 * SCENE_TILE_WIDTH), (int) (4.5 * SCENE_TILE_HEIGHT) + 2, "", "the arrow keys.");

    scene_add_hologram(&self, (int) (6.5 * SCENE_TILE_WIDTH), (int) (4.5 * SCENE_TILE_HEIGHT), "", "Select this tile");
    scene_add_hologram(&self, (int) (6.5 * SCENE_TILE_WIDTH), (int) (4.5 * SCENE_TILE_HEIGHT) + 1, "", "and end your turn.");
}, {
    if(self->camera_tile_x == 6 && self->camera_tile_y == 4) {
        scene_free(self);
        *self = (STAGE_TUTORIAL_MOVE.generator)(0);
    }
}, "Tutorial", NULL);


IMPL_STAGE(TUTORIAL_MOVE, tutorial_move, ((const SceneTile**[]) {
    (const SceneTile*[]) { VOID, VOID, VOID, VOID, VOID, VOID, VOID, VOID, VOID },
    (const SceneTile*[]) { VOID, VOID, VOID, VOID, VOID, VOID, VOID, VOID, VOID },
    (const SceneTile*[]) { VOID, VOID, MDOW, VOID, MDOW, MDOW, FRST, VOID, VOID },
    (const SceneTile*[]) { VOID, MDOW, FRST, MDOW, FRST, FRST, FRST, MDOW, VOID },
    (const SceneTile*[]) { VOID, MDOW, MDOW, VOID, VOID, VOID, MDOW, FRST, VOID },
    (const SceneTile*[]) { VOID, MDOW, VOID, VOID, FRST, MDOW, MDOW, VOID, VOID },
    (const SceneTile*[]) { VOID, VOID, VOID, MDOW, MDOW, VOID, VOID, VOID, VOID },
    (const SceneTile*[]) { VOID, VOID, VOID, VOID, VOID, VOID, VOID, VOID, VOID },
    (const SceneTile*[]) { VOID, VOID, VOID, VOID, VOID, VOID, VOID, VOID, VOID },
}), 9, 9, FOG_DISABLED, NULL, {
    scene_focus_on_tile(&self, 2, 4);

    scene_add_hologram(&self, (int) (4.5 * SCENE_TILE_WIDTH), (int) (4.5 * SCENE_TILE_HEIGHT), "", "Select this tile,");
    scene_add_hologram(&self, (int) (4.5 * SCENE_TILE_WIDTH), (int) (4.5 * SCENE_TILE_HEIGHT) + 1, "", "press [Enter] and");
    scene_add_hologram(&self, (int) (4.5 * SCENE_TILE_WIDTH), (int) (4.5 * SCENE_TILE_HEIGHT) + 2, "", "select 'Move'.");
    stage_summon_troops(&self, 4, 4, &ENTITY_KNIGHT, 5);

    scene_add_hologram(&self, (int) (6.5 * SCENE_TILE_WIDTH), (int) (4.5 * SCENE_TILE_HEIGHT), "", "Move all of the");
    scene_add_hologram(&self, (int) (6.5 * SCENE_TILE_WIDTH), (int) (4.5 * SCENE_TILE_HEIGHT) + 1, "", "knights here and");
    scene_add_hologram(&self, (int) (6.5 * SCENE_TILE_WIDTH), (int) (4.5 * SCENE_TILE_HEIGHT) + 2, "", "end your turn.");
}, {
    stage_reset_troop_actions(self);
    if(scene_get_tile(self, 6, 4)->entities.size == 5) {
        scene_free(self);
        *self = (STAGE_TUTORIAL_ATTACK.generator)(0);
    }
}, "Tutorial", NULL);


IMPL_STAGE(TUTORIAL_ATTACK, tutorial_attack, ((const SceneTile**[]) {
    (const SceneTile*[]) { VOID, VOID, VOID, VOID, VOID, VOID, VOID, VOID, VOID },
    (const SceneTile*[]) { VOID, VOID, VOID, VOID, VOID, VOID, VOID, VOID, VOID },
    (const SceneTile*[]) { VOID, VOID, MDOW, MDOW, FRST, MDOW, VOID, VOID, VOID },
    (const SceneTile*[]) { VOID, MDOW, FRST, MDOW, MDOW, FRST, MDOW, VOID, VOID },
    (const SceneTile*[]) { VOID, FRST, MDOW, VOID, VOID, MDOW, MDOW, FRST, VOID },
    (const SceneTile*[]) { VOID, MDOW, VOID, VOID, VOID, MDOW, FRST, VOID, VOID },
    (const SceneTile*[]) { VOID, VOID, VOID, VOID, VOID, VOID, VOID, VOID, VOID },
    (const SceneTile*[]) { VOID, VOID, VOID, VOID, VOID, VOID, VOID, VOID, VOID },
    (const SceneTile*[]) { VOID, VOID, VOID, VOID, VOID, VOID, VOID, VOID, VOID },
}), 9, 9, FOG_DISABLED, NULL, {
    scene_focus_on_tile(&self, 2, 4);

    stage_summon_troops(&self, 2, 4, &ENTITY_KNIGHT, 5);

    scene_add_hologram(&self, (int) (4.5 * SCENE_TILE_WIDTH), (int) (4.5 * SCENE_TILE_HEIGHT), "", "Move the knights here.");
    scene_add_hologram(&self, (int) (4.5 * SCENE_TILE_WIDTH), (int) (4.5 * SCENE_TILE_HEIGHT) + 1, "", "(Just out of range)");

    stage_summon_troops(&self, 6, 4, &ENTITY_GOBLIN, 5);
    scene_add_hologram(&self, (int) (6.5 * SCENE_TILE_WIDTH), (int) (4.5 * SCENE_TILE_HEIGHT), "", "These are enemies.");
}, {
    stage_reset_troop_actions(self);
    if(scene_get_tile(self, 4, 4)->entities.size == 5 && scene_get_tile(self, 6, 4)->entities.size == 5) {
        SceneTileState* moved_from = scene_get_tile(self, 6, 4);
        SceneTileState* moved_to = scene_get_tile(self, 5, 4);
        for(unsigned int e = 0; e < 5; e += 1) {
            tile_state_add(moved_to, *tile_state_get(moved_from, 0));
            tile_state_remove(moved_from, 0);
        }
        size_t hologram;
        SceneIterator holograms = scenei_new(self, &SCENE_OBJECT_HOLOGRAM, &hologram);
        while(scenei_next(&holograms)) {
            scene_delete(self, hologram);
            scenei_rewind(&holograms);
        }
        scene_add_hologram(self, (int) (4.5 * SCENE_TILE_WIDTH), (int) (4.5 * SCENE_TILE_HEIGHT), "", "Select this tile,");
        scene_add_hologram(self, (int) (4.5 * SCENE_TILE_WIDTH), (int) (4.5 * SCENE_TILE_HEIGHT) + 1, "", "press [Enter] and");
        scene_add_hologram(self, (int) (4.5 * SCENE_TILE_WIDTH), (int) (4.5 * SCENE_TILE_HEIGHT) + 2, "", "select 'Attack'.");
        scene_add_hologram(self, (int) (5.5 * SCENE_TILE_WIDTH), (int) (4.5 * SCENE_TILE_HEIGHT), "", "Attack these goblins");
        scene_add_hologram(self, (int) (5.5 * SCENE_TILE_WIDTH), (int) (4.5 * SCENE_TILE_HEIGHT) + 1, "", "and end your turn.");
    } else if(scene_get_tile(self, 6, 4)->entities.size == 5 || scene_get_tile(self, 5, 4)->entities.size == 5) {
        scene_free(self);
        *self = (STAGE_TUTORIAL_ATTACK.generator)(0);
    }
    stage_win_if_only_humans(self, savegame);
}, "Tutorial", NULL);
