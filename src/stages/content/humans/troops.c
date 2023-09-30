
#include "../humans.h"


IMPL_ENTITY(FARMER, ((RenderObject) {
    .data = (char**[]) {
        (char*[]) { "o", "w" },
        (char*[]) { "|", "|"  }
    },
    .width = 2, .height = 2,
    .anchor_x = 0, .anchor_y = 1
}), "Farmer",
    1, // size
    2, // speed
    0, // is enemy
    5, // health
    5, // attack strength
    1, // attack size
    1, // attack min distance
    1, // attack max distance
    2+1  // visibility distance
);

IMPL_ENTITY(KNIGHT, ((RenderObject) {
    .data = (char**[]) {
        (char*[]) { "o", "|" },
        (char*[]) { "@", "+"  }
    },
    .width = 2, .height = 2,
    .anchor_x = 0, .anchor_y = 1
}), "Knight",
    1, // size
    2, // speed
    0, // is enemy
    5, // health
    2, // attack strength
    3, // attack size
    1, // attack min distance
    1, // attack max distance
    2+1  // visibility distance
);

IMPL_ENTITY(ARCHER, ((RenderObject) {
    .data = (char**[]) {
        (char*[]) { "o", NULL, NULL },
        (char*[]) { "|", "(",  "-"  }
    },
    .width = 3, .height = 2,
    .anchor_x = 0, .anchor_y = 1
}), "Archer",
    2, // size
    2, // speed
    0, // is enemy
    1, // health
    3, // attack strength
    3, // attack size
    3, // attack min distance
    6, // attack max distance
    4+1  // visibility distance
);

IMPL_ENTITY(SCOUT, ((RenderObject) {
    .data = (char**[]) {
        (char*[]) { "o", "=", NULL  },
        (char*[]) { "#", "[", "]"   }
    },
    .width = 3, .height = 2,
    .anchor_x = 0, .anchor_y = 1
}), "Scout",
    1, // size
    5, // speed
    0, // is enemy
    1, // health
    0, // attack strength
    0, // attack size
    0, // attack min distance
    0, // attack max distance
    6+1  // visibility distance
);

IMPL_ENTITY(CATAPULT, ((RenderObject) {
    .data = (char**[]) {
        (char*[]) { "+",  "-",  "+",  "_",  "_",  "_", "_", "_", "/",  "\\", "_", NULL, NULL },
        (char*[]) { "+",  "-",  "+",  NULL, NULL, "+", "o", "|", NULL, NULL, "|", "o",  "+"  },
        (char*[]) { NULL, NULL, NULL, NULL, NULL, "+", "o", "-", "-",  "-",  "-", "o",  "+"  }
    },
    .width = 13, .height = 3,
    .anchor_x = 6, .anchor_y = 2
}), "Catapult",
    20, // size
    2, // speed
    0, // is enemy
    25, // health
    5, // attack strength
    20, // attack size
    3, // attack min distance
    20, // attack max distance
    1  // visibility distance
);