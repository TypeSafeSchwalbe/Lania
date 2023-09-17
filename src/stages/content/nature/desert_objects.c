
#include "../nature.h"
#include "../colors.h"


IMPL_OBJECT_PROP(CACTUS, Cactus, cactus, ((RenderObject) {
    .data = (char**[]) {
        (char*[]) { NULL      , NULL    , MF "*" C, NULL    , NULL     },
        (char*[]) { MF "*"  C , NULL    , GF "|" C, NULL    , GF "|" C },
        (char*[]) { GF "|"  C , NULL    , GF "|" C, GF "-" C, GF "/" C },
        (char*[]) { GF "\\" C , GF "-" C, GF "|" C, NULL    , NULL     },
        (char*[]) { NULL      , NULL    , GF "|" C, NULL    , NULL     }
    },
    .width = 5, .height = 5,
    .anchor_x = 2, .anchor_y = 4
}));


IMPL_OBJECT_PROP(SHRUB, Shrub, shrub, ((RenderObject) {
    .data = (char**[]) {
        (char*[]) { YF "\\" C, YF "|" C, YF "/" C },
    },
    .width = 3, .height = 1,
    .anchor_x = 1, .anchor_y = 0
}));


const RenderObject TUMBLEWEED_RENDER_OBJECT = (RenderObject) {
    .data = (char**[]) {
        (char*[]) { YF "@" C }
    },
    .width = 1, .height = 1,
    .anchor_x = 0, .anchor_y = 0
};

IMPL_OBJECT(TUMBLEWEED, Tumbleweed, tumbleweed, {
    render_object(buffer, &TUMBLEWEED_RENDER_OBJECT, self->x + rand() % SCENE_TILE_WIDTH + scene->camera_ox, self->y + rand() % SCENE_TILE_HEIGHT + scene->camera_oy);
}, {}, (Scene* scene, int x, int y), {
    self.x = x;
    self.y = y;
});