
#include "../humans.h"
#include "../colors.h"


const RenderObject PATH_RENDER_OBJECT = (RenderObject) {
    .data = (char**[]) {
        (char*[]) { YF "o" C, YF "o" C, YF "." C, YF "O" C, YF "o" C },
        (char*[]) { YF "." C, YF "O" C, YF "O" C, YF "O" C, YF "O" C },
        (char*[]) { YF "O" C, YF "." C, YF "o" C, YF "." C, YF "O" C },
    },
    .width = 5, .height = 3,
    .anchor_x = 0, .anchor_y = -1
};

IMPL_OBJECT(PATH, Path, path, {
    render_object(buffer, &PATH_RENDER_OBJECT, self->x + scene->camera_ox, self->y + scene->camera_oy);
}, {}, (Scene* scene, int x, int y), {
    self.x = x;
    self.y = y - 1;
});


IMPL_OBJECT_PROP(FENCE_H, FenceH, fenceh, ((RenderObject) {
    .data = (char**[]) {
        (char*[]) { "|", "|", "-", "-", "-", "-", "-", "|", "|" },
        (char*[]) { "|", "|", "-", "-", "-", "-", "-", "|", "|" }
    },
    .width = 9, .height = 2,
    .anchor_x = 0, .anchor_y = 1
}));


IMPL_OBJECT_PROP(HUT, Hut, hut, ((RenderObject) {
    .data = (char**[]) {
        (char*[]) { NULL    , NULL    , RF "_" C, RF "_" C, RF "_" C, RF "_" C, RF "_" C, RF "_" C, RF "_" C, RF "_" C, RF "_" C, NULL    ,  NULL      },
        (char*[]) { NULL    , RF "/" C, RF "|" C,    " "  ,    " "  ,    " "  ,    " "  ,    "|"  ,    "|"  ,    " "  , RF "|" C, RF "\\" C, NULL      },
        (char*[]) { RF "/" C, RF "/" C, RF "|" C,    " "  ,    " "  ,    " "  ,    " "  ,    " "  ,    " "  ,    " "  , RF "|" C, RF "\\" C, RF "\\" C },
        (char*[]) { RF "|" C, RF "/" C, RF "|" C, RF "_" C, RF "_" C, RF "_" C, RF "_" C, RF "_" C, RF "_" C, RF "_" C, RF "|" C, RF "\\" C, RF "|" C  },
        (char*[]) { RF "|" C, RF "/" C,    " "  ,    " "  ,    " "  ,    " "  ,    " "  ,    " "  ,    " "  ,    " "  ,    " "  , RF "\\" C, RF "|" C  },
        (char*[]) { RF "/" C,    "-"  ,    "-"  ,    "-"  ,    "-"  ,    "+"  ,    "-"  ,    "+"  ,    "-"  ,    "-"  ,    "-"  ,    "-"  ,  RF "\\" C },
        (char*[]) {    "|"  ,    " "  ,    "["  ,    "]"  ,    " "  ,    "|"  ,    " "  ,    "|"  ,    " "  ,    "["  ,    "]"  ,    " "  ,     "|"    },
        (char*[]) {    "|"  ,    "="  ,    "="  ,    "="  ,    "="  ,    "|"  ,    "_"  ,    "|"  ,    "="  ,    "="  ,    "="  ,    "="  ,  B  "|"    }
    },
    .width = 13, .height = 8,
    .anchor_x = 0, .anchor_y = 7
}));


/*
IMPL_OBJECT_PROP(WELL, Well, well, ((RenderObject) {
    .data = (char**[]) {
        (char*[]) {    " "   ,    "_"  ,    "_"  ,    "|"  ,    "_"  ,    "_"  ,    " "    },
        (char*[]) {    "/"   ,    "v"  ,    "v"  ,    "v"  ,    "v"  ,    "v"  ,    "\\"   },
        (char*[]) {    "\\"  ,    "_"  ,    "_"  ,    "_"  ,    "_"  ,    "_"  ,    "/"    },
        (char*[]) {    "|"   ,    "-"  ,    "-"  ,    "-"  ,    "-"  ,    "-"  ,    "|"    },
        (char*[]) {    "\\"  ,    "_"  ,    "_"  ,    "_"  ,    "_"  ,    "_"  ,    "/"    },
        (char*[]) {    "\\"  ,    "_"  ,    "_"  ,    "_"  ,    "_"  ,    "_"  ,    "/"    }
    },
    .width = 7, .height = 6,
    .anchor_x = 0, .anchor_y = 5
}));
*/