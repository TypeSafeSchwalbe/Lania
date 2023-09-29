
#pragma once

#include "definitions.h"
#include "../../scene.h"


DEF_OBJECT(HOLOGRAM, Hologram, hologram, { int x; int y; const char* text_style; const char* text; }, (Scene* scene, int x, int y, const char* text_style, const char* text));

DEF_TILE(EMPTY);