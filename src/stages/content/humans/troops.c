
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
    1  // attack max distance
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
    5, // attack strength
    1, // attack size
    1, // attack min distance
    1  // attack max distance
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
    1, // speed
    0, // is enemy
    1, // health
    3, // attack strength
    3, // attack size
    3, // attack min distance
    6  // attack max distance
);

IMPL_ENTITY(DIGGER, ((RenderObject) {
    .data = (char**[]) {
        (char*[]) { NULL, "_" },
        (char*[]) { "o",  "U" },
        (char*[]) { "#",  "|" }
    },
    .width = 2, .height = 3,
    .anchor_x = 0, .anchor_y = 2
}), "Digger",
    2, // size
    255, // speed
    0, // is enemy
    1, // health
    5, // attack strength
    1, // attack size
    1, // attack min distance
    1  // attack max distance
);