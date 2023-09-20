
#include "../goblins.h"
#include "../colors.h"


IMPL_ENTITY(GOBLIN, ((RenderObject) {
    .data = (char**[]) {
        (char*[]) { RF "o" C },
        (char*[]) { RF "@" C }
    },
    .width = 1, .height = 2,
    .anchor_x = 0, .anchor_y = 1
}), "Goblin",
    1, // size
    2, // speed
    1, // is enemy
    5, // health
    5, // attack strength
    1, // attack size
    1, // attack min distance
    1  // attack max distance
);

IMPL_ENTITY(CYCLOPS, ((RenderObject) {
    .data = (char**[]) {
        (char*[]) { NULL     , RF "_" C, RF "_" C, RF "_" C, NULL      },
        (char*[]) { RF "/"  C,    "("  , GF "o" C,    ")"  , RF "\\" C },
        (char*[]) { RF "\\" C, RF "_" C, RF "_" C, RF "_" C, RF "/"  C },
        (char*[]) { RF "/"  C, RF "|" C, RF "_" C, RF "|" C, RF "\\" C },
        (char*[]) { NULL     , RF "|" C, NULL    , RF "|" C, NULL      }
    },
    .width = 5, .height = 5,
    .anchor_x = 2, .anchor_y = 4
}), "Cyclops",
    10, // size
    1, // speed
    1, // is enemy
    100, // health
    10, // attack strength
    10, // attack size
    1, // attack min distance
    1  // attack max distance
);

IMPL_ENTITY(SPEAR_GOBLIN, ((RenderObject) {
    .data = (char**[]) {
        (char*[]) { RF "o" C, RF "^" C },
        (char*[]) { RF "#" C, RF "|" C }
    },
    .width = 2, .height = 2,
    .anchor_x = 0, .anchor_y = 1
}), "Spear Goblin",
    2, // size
    2, // speed
    1, // is enemy
    2, // health
    5, // attack strength
    1, // attack size
    1, // attack min distance
    4  // attack max distance
);