
#include "../nature.h"
#include "../colors.h"


IMPL_OBJECT_PROP(MAGICAL_TREE, MagicalTree, magical_tree, ((RenderObject) {
    .data = (char**[]) {
        (char*[]) { NULL    , NULL    , NULL     , NULL    , NULL    , NULL    , MF "@"  C, MF "O"  C, MF "o" C, NULL     },
        (char*[]) { NULL    , MF "@" C, MF "@"  C, MF "o" C, NULL    , MF "@" C, MF "o"  C, YF "|"  C, MF "@" C, MF "o" C },
        (char*[]) { MF "o" C, MF "@" C, YF "\\" C, MF "O" C, MF "o" C, MF "|" C, YF "/"  C, NULL     , MF "|" C, MF "|" C },
        (char*[]) { MF "|" C, MF "|" C, NULL     , YF "-" C, MF "|" C, MF "|" C, NULL     , NULL     , MF "|" C, MF "|" C },
        (char*[]) { MF "|" C, MF "|" C, NULL     , NULL    , MF "|" C, MF "|" C, YF "\\" C, NULL     , NULL    , MF "|" C },
        (char*[]) { MF "|" C, NULL    , NULL     , NULL    , NULL    , NULL    , YF "/"  C, YF "\\" C, NULL    , NULL     },
    },
    .width = 10, .height = 6,
    .anchor_x = 6, .anchor_y = 5
}));


const RenderObject FIREFLY_LEFT = {
    .data = (char**[]) {
        (char*[]) { YF "*" C, DF GB "*" C },
    },
    .width = 2, .height = 1,
    .anchor_x = 0, .anchor_y = 3
};

const RenderObject FIREFLY_RIGHT = {
    .data = (char**[]) {
        (char*[]) { DF GB "*" C, YF "*" C },
    },
    .width = 2, .height = 1,
    .anchor_x = 0, .anchor_y = 3
};

const int FIREFLY_RADIUS = 5;

IMPL_OBJECT(FIREFLY, Firefly, firefly, {
   render_object(buffer, self->dir == 0? &FIREFLY_LEFT : &FIREFLY_RIGHT, self->x + scene->camera_ox + rand() % (FIREFLY_RADIUS * 2) - FIREFLY_RADIUS, self->y + scene->camera_oy + rand() % (FIREFLY_RADIUS * 2) - FIREFLY_RADIUS);
}, {}, (Scene* scene, int x, int y), {
    self.x = x;
    self.y = y;
    self.dir = rand() % 2;
});


IMPL_OBJECT_PROP(MAGICAL_FLOWER, MagicalFlower, magical_flower, ((RenderObject) {
    .data = (char**[]) {
        (char*[]) { BF "("  C,    "*"  , BF ")" C },
        (char*[]) { GF "\\" C, GF "|" C, GF "/" C }
    },
    .width = 3, .height = 2,
    .anchor_x = 1, .anchor_y = 1
}));
