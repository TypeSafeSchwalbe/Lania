
#include "stages.h"
#include "content/nature.h"
#include "content/humans.h"
#include "content/goblins.h"
#include "content/elves.h"
#include "../engine/sequences.h"


#define MFST &SCENE_TILE_MAGICAL_FOREST
#define MMDW &SCENE_TILE_MAGICAL_MEADOW
#define MWTR &SCENE_TILE_MAGICAL_WATER
#define EVHT &SCENE_TILE_ELVEN_VILLAGE_HUT

IMPL_STAGE(ELVEN_VILLAGE, elven_village, ((const SceneTile**[]) {
    (const SceneTile*[]) { MFST, MFST, MFST, MFST, MFST, MFST, MWTR, MWTR, MWTR, MWTR, MWTR, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST },
    (const SceneTile*[]) { MFST, MFST, MWTR, MWTR, MWTR, MWTR, MWTR, MWTR, MWTR, MWTR, MWTR, MWTR, MWTR, MWTR, MWTR, MWTR, MWTR, MWTR, MWTR, MFST },
    (const SceneTile*[]) { MFST, MWTR, MWTR, EVHT, EVHT, MFST, MWTR, MWTR, MWTR, MFST, EVHT, EVHT, MFST, EVHT, MFST, EVHT, EVHT, MWTR, MWTR, MWTR },
    (const SceneTile*[]) { MFST, MWTR, MFST, MMDW, MMDW, MMDW, EVHT, MWTR, EVHT, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MFST, MWTR, MWTR },
    (const SceneTile*[]) { MFST, MWTR, EVHT, MMDW, MMDW, MMDW, MFST, MWTR, MFST, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, EVHT, MWTR, MFST },
    (const SceneTile*[]) { MFST, MWTR, MFST, MMDW, MMDW, MMDW, MFST, MWTR, MWTR, MFST, MMDW, MFST, EVHT, MFST, EVHT, MFST, MFST, MWTR, MWTR, MFST },
    (const SceneTile*[]) { MFST, MWTR, MWTR, MFST, MMDW, EVHT, MWTR, MWTR, MWTR, MWTR, MMDW, MWTR, MWTR, MWTR, MWTR, MWTR, MWTR, MWTR, MFST, MFST },
    (const SceneTile*[]) { MFST, MFST, MWTR, MWTR, MMDW, MWTR, MWTR, MWTR, MWTR, EVHT, MMDW, MFST, MWTR, MWTR, MWTR, MFST, MFST, MFST, MFST, MFST },
    (const SceneTile*[]) { MFST, MFST, MFST, MFST, MMDW, MFST, MFST, MWTR, MFST, MMDW, MMDW, MMDW, EVHT, MWTR, MFST, MFST, MFST, MFST, MFST, MFST },
    (const SceneTile*[]) { MMDW, MMDW, MMDW, MMDW, MMDW, MFST, MFST, MWTR, EVHT, MMDW, MMDW, MMDW, EVHT, MWTR, MFST, MFST, MMDW, MMDW, MMDW, MMDW },
    (const SceneTile*[]) { MMDW, MMDW, MMDW, MMDW, MMDW, MFST, MFST, MWTR, MFST, MMDW, MMDW, MMDW, MFST, MWTR, MFST, MFST, MMDW, MMDW, MMDW, MMDW },
    (const SceneTile*[]) { MFST, MFST, MFST, MFST, MMDW, MFST, MFST, MWTR, EVHT, MMDW, MMDW, MMDW, MFST, MWTR, MFST, MFST, MMDW, MFST, MFST, MFST },
    (const SceneTile*[]) { MFST, MWTR, MWTR, MWTR, MMDW, MWTR, MWTR, MWTR, MWTR, MFST, MMDW, EVHT, MWTR, MWTR, MWTR, MFST, MMDW, MFST, MFST, MFST },
    (const SceneTile*[]) { MWTR, MWTR, MWTR, EVHT, MMDW, MFST, MWTR, MWTR, MWTR, MWTR, MMDW, MWTR, MWTR, MWTR, MWTR, MWTR, MMDW, MWTR, MFST, MFST },
    (const SceneTile*[]) { MWTR, MWTR, MFST, MMDW, MMDW, MMDW, EVHT, MWTR, MFST, EVHT, MMDW, MFST, MFST, EVHT, EVHT, MFST, MMDW, MWTR, MWTR, MFST },
    (const SceneTile*[]) { MWTR, MWTR, EVHT, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MFST, MWTR, MFST },
    (const SceneTile*[]) { MWTR, MWTR, EVHT, MMDW, MMDW, MMDW, MFST, MWTR, MFST, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, EVHT, MWTR, MFST },
    (const SceneTile*[]) { MFST, MWTR, MWTR, MFST, EVHT, MFST, MWTR, MWTR, MWTR, MFST, EVHT, MFST, EVHT, MFST, EVHT, EVHT, MFST, MWTR, MWTR, MFST },
    (const SceneTile*[]) { MFST, MFST, MWTR, MWTR, MWTR, MWTR, MWTR, MWTR, MWTR, MWTR, MWTR, MWTR, MWTR, MWTR, MWTR, MWTR, MWTR, MWTR, MFST, MFST },
    (const SceneTile*[]) { MFST, MFST, MFST, MWTR, MWTR, MFST, MFST, MFST, MFST, MFST, MWTR, MWTR, MWTR, MWTR, MFST, MFST, MFST, MFST, MFST, MFST }
}), 20, 20, FOG_ENABLED, &COMMANDER_OBREG, {
    scene_focus_on_tile(&self, 1, 9);

    stage_summon_troops(&self, 0, 9, &ENTITY_ARCHER, 10);
    stage_summon_troops(&self, 0, 10, &ENTITY_ARCHER, 10);
    stage_summon_troops(&self, 1, 9, &ENTITY_KNIGHT, 20);
    stage_summon_troops(&self, 1, 10, &ENTITY_KNIGHT, 20);
    stage_summon_troops(&self, 2, 9, &ENTITY_SCOUT, 1);
    stage_summon_troops(&self, 2, 10, &ENTITY_SCOUT, 1);

    stage_summon_troops(&self, 4, 4, &ENTITY_CYCLOPS, 1);
    stage_summon_troops(&self, 4, 4, &ENTITY_GOBLIN, 10);
    stage_summon_troops(&self, 5, 4, &ENTITY_SPEAR_GOBLIN, 10);

    stage_summon_troops(&self, 4, 15, &ENTITY_CYCLOPS, 1);
    stage_summon_troops(&self, 4, 15, &ENTITY_GOBLIN, 10);
    stage_summon_troops(&self, 5, 15, &ENTITY_SPEAR_GOBLIN, 10);

    stage_summon_troops(&self, 9, 9, &ENTITY_GOBLIN, 5);
    stage_summon_troops(&self, 10, 9, &ENTITY_CYCLOPS, 1);
    stage_summon_troops(&self, 10, 9, &ENTITY_GOBLIN, 10);
    stage_summon_troops(&self, 11, 9, &ENTITY_GOBLIN, 5);
    stage_summon_troops(&self, 9, 10, &ENTITY_GOBLIN, 5);
    stage_summon_troops(&self, 10, 10, &ENTITY_CYCLOPS, 1);
    stage_summon_troops(&self, 10, 10, &ENTITY_GOBLIN, 10);
    stage_summon_troops(&self, 11, 10, &ENTITY_GOBLIN, 5);

    stage_summon_troops(&self, 15, 3, &ENTITY_SPEAR_GOBLIN, 10);
    stage_summon_troops(&self, 14, 4, &ENTITY_GOBLIN, 10);

    stage_summon_troops(&self, 14, 15, &ENTITY_GOBLIN, 10);
    stage_summon_troops(&self, 15, 16, &ENTITY_SPEAR_GOBLIN, 10);
}, {
    stage_win_if_only_humans(self, savegame);
    stage_make_goblin_moves(self);
    stage_lose_if_only_goblins(self, savegame);
    stage_reset_troop_actions(self);
}, "Elven Village",
    "Continue the counter-invasion of the goblin realm by\n"
    "taking control of the elven village in the west of the goblin realm."
);