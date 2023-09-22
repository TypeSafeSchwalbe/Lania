
#include "../nature.h"
#include "../colors.h"


/*
 / /  \ \  
| |  /|/| \ \  
| | | | |  | |   \__/
| | | | |  | |  /  / \
 \ \ X X  / /  | <> <>|
*/

IMPL_OBJECT_PROP(GIANT_BONES, GiantBones, giant_bones, ((RenderObject) {
    .data = (char**[]) {
        (char*[]) { NULL, "/",  NULL, "/",  NULL, NULL, "\\", NULL, "\\", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
        (char*[]) { "|",  NULL, "|",  NULL, NULL, "/",  "|",  "/",  "|",  NULL, "\\", NULL, "\\", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL },
        (char*[]) { "|",  NULL, "|",  NULL, "|",  NULL, "|",  NULL, "|",  NULL, NULL, "|",  NULL, "|",  NULL, NULL, NULL, "\\", "_",  "_",  "/",  NULL, NULL },
        (char*[]) { "|",  NULL, "|",  NULL, "|",  NULL, "|",  NULL, "|",  NULL, NULL, "|",  NULL, "|",  NULL, NULL, "/",  NULL, NULL, "/",  NULL, "\\", NULL },
        (char*[]) { NULL, "\\", NULL, "\\", NULL, "X",  NULL, "X",  NULL, NULL, "/",  NULL, "/",  NULL, NULL, "|",  NULL, "<",  ">",  NULL, "<",  ">",  "|"  }
    },
    .width = 23, .height = 5,
    .anchor_x = 11, .anchor_y = 4
}));


/*
 _\   \_  
  _\__  \/_/
_  /  \ /  _/
 \__   |__/ \  
 /  \ /  \_
     |
    /_\
*/

IMPL_OBJECT_PROP(DEAD_TREE, DeadTree, dead_tree, ((RenderObject) {
    .data = (char**[]) {
        (char*[]) { NULL    , YF "_"  C, YF "\\" C, NULL     , NULL     , NULL     , YF "\\" C, YF "_" C, NULL     , NULL     , NULL    , NULL    , NULL      },
        (char*[]) { NULL    , NULL     , YF "_"  C, YF "\\" C, YF "_"  C, YF "_"  C, NULL     , NULL    , YF "\\" C, YF "/"  C, YF "_" C, YF "/" C, NULL      },
        (char*[]) { YF "_" C, NULL     , NULL     , YF "/"  C, NULL     , NULL     , YF "\\" C, NULL    , YF "/"  C, NULL     , NULL    , YF "_" C, YF "/"  C },
        (char*[]) { NULL    , YF "\\" C, YF "_"  C, YF "_"  C, NULL     , NULL     , NULL     , YF "|" C, YF "_"  C, YF "_"  C, YF "/" C, NULL    , YF "\\" C },
        (char*[]) { NULL    , YF "/"  C, NULL     , NULL     , YF "\\" C, NULL     , YF "/"  C, NULL    , NULL     , YF "\\" C, YF "_" C, NULL    , NULL      },
        (char*[]) { NULL    , NULL     , NULL     , NULL     , NULL     , YF "|"  C, NULL     , NULL    , NULL     , NULL     , NULL    , NULL    , NULL      },
        (char*[]) { NULL    , NULL     , NULL     , NULL     , YF "/"  C, YF "_"  C, YF "\\" C, NULL    , NULL     , NULL     , NULL    , NULL    , NULL      }
    },
    .width = 13, .height = 7,
    .anchor_x = 6, .anchor_y = 6
}));

