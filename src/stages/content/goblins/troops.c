
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
    1, // attack max distance
    0  // visibility distance
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
    1, // attack max distance
    0  // visibility distance
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
    4, // attack max distance
    0  // visibility distance
);

IMPL_ENTITY(DAGGER_GOBLIN, ((RenderObject) {
    .data = (char**[]) {
        (char*[]) { NULL    , RF "o" C },
        (char*[]) { RF "-" C, RF "#" C }
    },
    .width = 2, .height = 2,
    .anchor_x = 0, .anchor_y = 1
}), "Dagger Goblin",
    1, // size
    5, // speed
    1, // is enemy
    1, // health
    2, // attack strength
    10, // attack size
    1, // attack min distance
    1, // attack max distance
    0  // visibility distance
);

IMPL_ENTITY(GOBLIN_KING, ((RenderObject) {
    .data = (char**[]) {
        (char*[]) { NULL    , NULL     , YF "|" C, YF "\\" C, YF "/" C, YF "\\" C, YF "/" C, YF "\\" C, YF "/" C, YF "|" C, NULL     , NULL    , NULL    , NULL    , NULL     },
        (char*[]) { NULL    , NULL     , YF "|" C, YF "_"  C, YF "_" C, YF "_"  C, YF "_" C, YF "_"  C, YF "_" C, YF "|" C, NULL     , NULL    , NULL    , NULL    , NULL     },
        (char*[]) { NULL    , RF "/"   ,    " "  ,    " "   ,    " "  ,    " "   ,    " "  ,    " "   ,    " "  ,    " "  , RF "\\" C, NULL    , NULL    , NULL    , NULL     },
        (char*[]) { RF "|" C,    " "   ,    "("  , GF "*"  C,    ")"  ,    " "   ,    " "  ,    "("   , GF "*" C,    ")"  ,    " "   , RF "|" C, NULL    , NULL    , NULL     },
        (char*[]) { RF "|" C,    " "   ,    " "  ,    " "   ,    " "  ,    " "   ,    " "  ,    " "   ,    " "  ,    " "  ,    " "   , RF "|" C, NULL    , NULL    , NULL     },
        (char*[]) { NULL    , RF "\\" C, RF "_" C, RF "_"  C, RF "_" C, RF "_"  C, RF "_" C, RF "_"  C, RF "_" C, RF "_" C, RF "/"   , NULL    , NULL    , YF "_" C, NULL     },
        (char*[]) { NULL    ,    " "   , RF "_" C, RF "_"  C, RF "|" C,    " "   ,    " "  , RF "|"  C, RF "_" C, RF "_" C, NULL     , NULL    , YF "(" C, YF "|" C, YF ")" C },
        (char*[]) { NULL    , RF "/"   , RF "|" C,    " "   ,    " "  ,    " "   ,    " "  ,    " "   ,    " "  , RF "|" C, RF "\\" C, NULL    , NULL    , YF "|" C, NULL     },
        (char*[]) { RF "|" C,    " "   , RF "|" C,    " "   ,    " "  ,    " "   ,    " "  ,    " "   ,    " "  , RF "|" C,    " "   , RF "|" C, RF "_" C, YF "|" C, NULL     },
        (char*[]) { RF "|" C,    " "   , RF "|" C,    " "   ,    " "  ,    " "   ,    " "  ,    " "   ,    " "  , RF "|" C, RF "_"   , RF "_" C, RF "_" C, YF "|" C, RF ")" C },
        (char*[]) { RF "|" C, RF "_"  C, RF "|" C,    " "   ,    " "  ,    " "   ,    " "  ,    " "   ,    " "  , RF "|" C, NULL     , NULL    , NULL    , YF "|" C, NULL     },
        (char*[]) { NULL    , NULL     , RF "|" C,    " "   ,    " "  , RF "_"  C, RF "_" C,    " "   ,    " "  , RF "|" C, NULL     , NULL    , NULL    , YF "|" C, NULL     },
        (char*[]) { NULL    , NULL     , RF "|" C,    " "   , RF "|" C,    " "   ,    " "  , RF "|"  C,    " "  , RF "|" C, NULL     , NULL    , NULL    , YF "|" C, NULL     },
        (char*[]) { NULL    , NULL     , RF "|" C, RF "_"  C, RF "|" C,    " "   ,    " "  , RF "|"  C, RF "_"  , RF "|" C, NULL     , NULL    , NULL    , YF "|" C, NULL     }
    },
    .width = 15, .height = 14,
    .anchor_x = 7, .anchor_y = 13
}), "Goblin King",
    20, // size
    1, // speed
    1, // is enemy
    2000, // health
    5, // attack strength
    20, // attack size
    0, // attack min distance
    2, // attack max distance
    0  // visibility distance
);
