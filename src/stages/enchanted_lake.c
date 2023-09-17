
#include "stages.h"
#include "content/nature.h"
#include "content/humans.h"
#include "content/goblins.h"
#include "../engine/sequences.h"


#define MFST &SCENE_TILE_MAGICAL_FOREST
#define MMDW &SCENE_TILE_MAGICAL_MEADOW
#define MWTR &SCENE_TILE_MAGICAL_WATER

IMPL_STAGE(ENCHANTED_LAKE, enchanted_lake, ((const SceneTile**[]) {
    (const SceneTile*[]) { MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST },
    (const SceneTile*[]) { MMDW, MMDW, MMDW, MMDW, MFST, MFST, MFST, MFST, MFST, MFST, MFST },
    (const SceneTile*[]) { MMDW, MMDW, MMDW, MMDW, MMDW, MWTR, MWTR, MFST, MFST, MFST, MFST },
    (const SceneTile*[]) { MFST, MMDW, MMDW, MMDW, MWTR, MWTR, MWTR, MWTR, MMDW, MMDW, MMDW },
    (const SceneTile*[]) { MFST, MFST, MMDW, MWTR, MWTR, MWTR, MWTR, MWTR, MFST, MMDW, MMDW },
    (const SceneTile*[]) { MFST, MFST, MMDW, MWTR, MWTR, MFST, MWTR, MMDW, MMDW, MMDW, MFST },
    (const SceneTile*[]) { MFST, MFST, MMDW, MWTR, MWTR, MWTR, MWTR, MMDW, MMDW, MFST, MFST },
    (const SceneTile*[]) { MFST, MFST, MMDW, MFST, MWTR, MWTR, MFST, MMDW, MMDW, MFST, MFST },
    (const SceneTile*[]) { MFST, MFST, MMDW, MMDW, MMDW, MFST, MMDW, MMDW, MMDW, MFST, MFST },
    (const SceneTile*[]) { MFST, MFST, MFST, MMDW, MMDW, MMDW, MMDW, MMDW, MFST, MFST, MFST },
    (const SceneTile*[]) { MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST, MFST }
}), 11, 11, COMMANDER_OBREG, {
    scene_focus_on_tile(&self, 1, 1);

    stage_summon_troops(&self, 0, 1, &ENTITY_KNIGHT, 20);
    stage_summon_troops(&self, 1, 1, &ENTITY_DIGGER, 10);
    stage_summon_troops(&self, 2, 1, &ENTITY_ARCHER, 10);

    stage_summon_troops(&self, 8, 3, &ENTITY_GOBLIN, 10);
    stage_summon_troops(&self, 8, 3, &ENTITY_CYCLOPS, 1);
    stage_summon_troops(&self, 9, 3, &ENTITY_SPEAR_GOBLIN, 10);
    stage_summon_troops(&self, 9, 4, &ENTITY_GOBLIN, 10);
    stage_summon_troops(&self, 9, 4, &ENTITY_CYCLOPS, 1);
}, "Enchanted Lake",
    "After you successfully took control of the disputed territory, you now entered the western side of the goblin realm."
);