
#include "../humans.h"
#include "../colors.h"


IMPL_OBJECT_PROP(TOMATO, Tomato, tomato, ((RenderObject) {
    .data = (char**[]) {
        (char*[]) { NULL    , GF "|"  C, GF "\\" C },
        (char*[]) { GF "/" C, GF "|"  C, RF "O"  C },
        (char*[]) { RF "O" C, GF "\\" C, NULL      },
        (char*[]) { NULL    , NULL     , GF "|"  C }
    },
    .width = 3, .height = 4,
    .anchor_x = 1, .anchor_y = 3
}));