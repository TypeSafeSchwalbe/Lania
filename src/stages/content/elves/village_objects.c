
#include "../elves.h"
#include "../colors.h"

/*
      _
    _/_\_
  _/_/_\_\_
 /_/_/|\_\_\
 /_/||_||\_\
 /|||||||||\
| ||_|||| | |
| |||||||_| |
+-----------+
 |    |    |
*/

IMPL_OBJECT_PROP(ELVEN_HUT, ElvenHut, elven_hut, ((RenderObject) {
    .data = (char**[]) {
        (char*[]) { NULL    , NULL    , NULL    , NULL    , NULL    , NULL    , MF "_" C, NULL     , NULL    , NULL     , NULL    , NULL     , NULL     },
        (char*[]) { NULL    , NULL    , NULL    , NULL    , MF "_" C, MF "/" C, MF "_" C, MF "\\" C, MF "_" C, NULL     , NULL    , NULL     , NULL     },
        (char*[]) { NULL    , NULL    , MF "_" C, MF "/" C, MF "_" C, MF "/" C, MF "_" C, MF "\\" C, MF "_" C, MF "\\" C, MF "_" C, NULL     , NULL     },
        (char*[]) { NULL    , MF "/" C, MF "_" C, MF "/" C, MF "_" C, MF "/" C, YF "|" C, MF "\\" C, MF "_" C, MF "\\" C, MF "_" C, MF "\\" C, NULL     },
        (char*[]) { NULL    , MF "/" C, MF "_" C, MF "/" C, YF "|" C, YF "|" C, YF "_" C, YF "|"  C, YF "|" C, MF "\\" C, MF "_" C, MF "\\" C, NULL     },
        (char*[]) { NULL    , MF "/" C, YF "|" C, YF "|" C, YF "|" C, YF "|" C, YF "|" C, YF "|"  C, YF "|" C, YF "|"  C, YF "|" C, MF "\\" C, NULL     },
        (char*[]) { YF "|" C,    " "  , YF "|" C, YF "|" C, YF "_" C, YF "|" C, YF "|" C, YF "|"  C, YF "|" C,    " "   , YF "|" C,    " "   , YF "|" C },
        (char*[]) { YF "|" C,    " "  , YF "|" C, YF "|" C, YF "|" C, YF "|" C, YF "|" C, YF "|"  C, YF "|" C, YF "_"  C, YF "|" C,    " "   , YF "|" C },
        (char*[]) { YF "+" C, YF "-" C, YF "-" C, YF "-" C, YF "-" C, YF "-" C, YF "-" C, YF "-"  C, YF "-" C, YF "-"  C, YF "-" C, YF "-"  C, YF "+" C },
        (char*[]) { NULL    , YF "|" C, NULL    , NULL    , NULL    , NULL    , YF "|" C, NULL     , NULL    , NULL     , NULL    , YF "|"  C, NULL     }
    },
    .width = 13, .height = 10,
    .anchor_x = 6, .anchor_y = 9
}));