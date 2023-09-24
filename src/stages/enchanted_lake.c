
#include "stages.h"
#include "content/nature.h"
#include "content/humans.h"
#include "content/goblins.h"
#include "../engine/sequences.h"


#define MFST &SCENE_TILE_MAGICAL_FOREST
#define MMDW &SCENE_TILE_MAGICAL_MEADOW
#define MWTR &SCENE_TILE_MAGICAL_WATER

#define CFLL &SCENE_TILE_CLIFF_FULL
#define CFDL &SCENE_TILE_CLIFF_DOWN_LEFT
#define CFDR &SCENE_TILE_CLIFF_DOWN_RIGHT
#define CFUL &SCENE_TILE_CLIFF_UP_LEFT
#define CFUR &SCENE_TILE_CLIFF_UP_RIGHT

IMPL_STAGE(ENCHANTED_LAKE, enchanted_lake, ((const SceneTile**[]) {
    (const SceneTile*[]) { MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST },
    (const SceneTile*[]) { MMDW, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MMDW, MMDW, MFST, MFST, MFST, MFST },
    (const SceneTile*[]) { MMDW, MMDW, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MFST, MFST, MFST },
    (const SceneTile*[]) { MMDW, MMDW, MMDW, MFST, MFST, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MFST, MFST, MFST },
    (const SceneTile*[]) { MFST, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MFST, MFST, MFST, MMDW, MMDW, MMDW, MMDW, MMDW, MFST, MFST },
    (const SceneTile*[]) { MFST, MFST, MMDW, MMDW, MMDW, MMDW, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MFST },
    (const SceneTile*[]) { MFST, MFST, MFST, MMDW, MMDW, MFST, MFST, CFDL, CFLL, CFLL, CFLL, CFLL, CFDR, MFST, MMDW, MFST, MMDW, MMDW, MMDW, MFST },
    (const SceneTile*[]) { MFST, MFST, MMDW, MMDW, MMDW, MFST, CFDL, CFUR, MFST, MWTR, MWTR, MFST, CFUL, CFDR, MFST, MFST, MFST, MMDW, MMDW, MMDW },
    (const SceneTile*[]) { MFST, MMDW, MMDW, MMDW, MMDW, MMDW, CFUR, MFST, MWTR, MWTR, MWTR, MFST, MFST, CFUL, CFLL, CFLL, CFDR, MFST, MMDW, MMDW },
    (const SceneTile*[]) { MFST, MMDW, MMDW, MFST, MMDW, MMDW, MMDW, MFST, MWTR, MWTR, MWTR, MWTR, MFST, MFST, MFST, MFST, MFST, MFST, MMDW, MMDW },
    (const SceneTile*[]) { MFST, MMDW, MMDW, MFST, MFST, MMDW, MMDW, MFST, MWTR, MWTR, MWTR, MWTR, MFST, MFST, MFST, MFST, MFST, MFST, MMDW, MMDW },
    (const SceneTile*[]) { MMDW, MMDW, MMDW, MFST, MFST, MMDW, MMDW, MMDW, MFST, MWTR, MWTR, MWTR, MFST, MFST, MFST, MFST, MFST, MFST, MMDW, MFST },
    (const SceneTile*[]) { MMDW, MMDW, MFST, MFST, MFST, MFST, MMDW, MMDW, MWTR, MWTR, MWTR, MFST, MFST, MFST, MFST, MFST, MFST, MMDW, MMDW, MFST },
    (const SceneTile*[]) { MMDW, MMDW, MMDW, MFST, MFST, MFST, MMDW, MMDW, MWTR, MWTR, MWTR, MFST, MFST, MFST, MFST, MFST, MFST, MMDW, MMDW, MFST },
    (const SceneTile*[]) { MFST, MMDW, MMDW, MFST, MFST, MMDW, MMDW, MFST, MWTR, MWTR, MFST, MFST, MFST, MFST, MMDW, MMDW, MFST, MMDW, MMDW, MFST },
    (const SceneTile*[]) { MFST, MMDW, MMDW, MFST, MFST, MMDW, MMDW, MMDW, MFST, MFST, MFST, MFST, MFST, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MFST },
    (const SceneTile*[]) { MFST, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MFST, MFST, MFST, MMDW, MMDW, MMDW, MMDW, MMDW, MFST, MFST },
    (const SceneTile*[]) { MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MFST, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MFST, MFST, MFST },
    (const SceneTile*[]) { MMDW, MMDW, MMDW, MMDW, MFST, MFST, MFST, MFST, MFST, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MMDW, MFST, MFST, MFST },
    (const SceneTile*[]) { MMDW, MMDW, MMDW, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MMDW, MMDW, MMDW, MFST, MFST, MFST, MFST }
}), 20, 20, FOG_ENABLED, COMMANDER_OBREG, {
    scene_focus_on_tile(&self, 1, 17);

    stage_summon_troops(&self, 1, 17, &ENTITY_SCOUT, 2);
    stage_summon_troops(&self, 2, 17, &ENTITY_KNIGHT, 10);
    stage_summon_troops(&self, 1, 18, &ENTITY_KNIGHT, 10);
    stage_summon_troops(&self, 2, 18, &ENTITY_ARCHER, 10);

    stage_summon_troops(&self, 5, 4, &ENTITY_GOBLIN, 5);

    stage_summon_troops(&self, 14, 3, &ENTITY_CYCLOPS, 1);
    stage_summon_troops(&self, 15, 3, &ENTITY_GOBLIN, 10);
    stage_summon_troops(&self, 14, 4, &ENTITY_GOBLIN, 10);
    stage_summon_troops(&self, 15, 4, &ENTITY_SPEAR_GOBLIN, 5);

    stage_summon_troops(&self, 9, 17, &ENTITY_GOBLIN, 5);

    stage_summon_troops(&self, 14, 16, &ENTITY_GOBLIN, 10);
    stage_summon_troops(&self, 15, 16, &ENTITY_SPEAR_GOBLIN, 5);
    stage_summon_troops(&self, 14, 17, &ENTITY_CYCLOPS, 1);
    stage_summon_troops(&self, 15, 17, &ENTITY_GOBLIN, 10);
}, "Enchanted Lake",
    "After you successfully took control of the disputed territory,\n"
    "you now entered the western side of the goblin realm."
);