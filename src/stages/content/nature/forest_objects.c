
#include <math.h>

#include "../nature.h"
#include "../colors.h"


IMPL_OBJECT_PROP(TREE, Tree, tree, ((RenderObject) {
    .data = (char**[]) {
        (char*[]) { NULL,     GF "#" C, GF "@" C, NULL,     NULL,    },
        (char*[]) { GF "#" C, GF "@" C, GF "#" C, GF "@" C, NULL,    },
        (char*[]) { NULL,     NULL,     GF "@" C, YF "+" C, GF "@" C },
        (char*[]) { GF "@" C, YF "+" C, YF "/" C, NULL,     NULL,    },
        (char*[]) { NULL,     YF "|" C, NULL,     NULL,     NULL,    }
    },
    .width = 5, .height = 5,
    .anchor_x = 1, .anchor_y = 4
}));


IMPL_OBJECT_PROP(GRASS, Grass, grass, ((RenderObject) {
    .data = (char**[]) {
        (char*[]) { GF "\\" C, GF "|" C, GF "/" C },
    },
    .width = 3, .height = 1,
    .anchor_x = 1, .anchor_y = 0
}));


const RenderObject FLOWER = {
    .data = (char**[]) {
        (char*[]) { "*" },
    },
    .width = 1, .height = 1,
    .anchor_x = 0, .anchor_y = -1
};

const unsigned char FLOWER_VARIANT_COUNT = 3;

IMPL_OBJECT(FLOWER, Flower, flower, {
    switch(self->variant) {
        case 0: FLOWER.data[0][0] = S_CYAN_FG "*" S_RESET; break;
        case 1: FLOWER.data[0][0] = S_BLUE_FG "*" S_RESET; break;
        case 2: FLOWER.data[0][0] = S_MAGENTA_FG "*" S_RESET; break;
    }
    render_object(buffer, &FLOWER, self->x + scene->camera_ox, self->y + scene->camera_oy);
}, {}, (Scene* scene, int x, int y), {
    self.x = x;
    self.y = y + 1;
    self.variant = rand() % FLOWER_VARIANT_COUNT;
});