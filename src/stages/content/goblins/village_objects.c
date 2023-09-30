
#include "../goblins.h"
#include "../colors.h"


IMPL_OBJECT_PROP(GOBLIN_HUT, GoblinHut, goblin_hut, ((RenderObject) {
    .data = (char**[]) {
        (char*[]) { NULL, "_", "_", "_", "_", "_", "_", "_", "_", NULL },
        (char*[]) { "/",  "_", "_", "_", "_", "_", "_", "_", "_", "\\" },
        (char*[]) { "/",  " ", " ", " ", " ", "(", "_", ")", " ", "\\" },
        (char*[]) { "|",  " ", "(", "_", ")", " ", "_", " ", " ", "|"  },
        (char*[]) { "|",  " ", " ", " ", " ", "/", " ", "|", " ", "|"  },
        (char*[]) { "\\", "_", "_", "_", "_", "|", " ", "|", "_", "/"  }
    },
    .width = 10, .height = 6,
    .anchor_x = 4, .anchor_y = 5
}));

IMPL_OBJECT_PROP(GOBLIN_HUT_RUBBLE, GoblinHutRubble, goblin_hut_rubble, ((RenderObject) {
    .data = (char**[]) {
        (char*[]) { "\\", "_",  "_",  NULL, NULL, "|",  "_",  "_",  "_",  NULL, NULL, NULL, "_",  NULL },
        (char*[]) { NULL, NULL, "_",  "_",  "_",  "_",  NULL, NULL, NULL, NULL, NULL, "/",  NULL, "|"  },
        (char*[]) { NULL, "/",  NULL, NULL, NULL, NULL, NULL, NULL, "|",  NULL, "_",  "_",  NULL, NULL },
        (char*[]) { NULL, NULL, NULL, NULL, NULL, NULL, "\\", "_",  "|",  "/",  NULL, NULL, NULL, NULL }
    },
    .width = 14, .height = 4,
    .anchor_x = 6, .anchor_y = 0
}));

