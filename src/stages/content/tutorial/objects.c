
#include <string.h>

#include "../tutorial.h"
#include "../../../engine/sequences.h"


#define HOLOGRAM_HEIGHT 5

IMPL_OBJECT(HOLOGRAM, Hologram, hologram, {
    size_t text_style_length = strlen(self->text_style);
    size_t text_length = strlen(self->text);
    write_line_onto_buffer(buffer, self->x + scene->camera_ox - (text_length / 2), self->y + scene->camera_oy - HOLOGRAM_HEIGHT, self->text_style, self->text, text_style_length == 0? "" : S_RESET, text_length, self->y + scene->camera_oy);
}, {}, (Scene* scene, int x, int y, const char* text_style, const char* text), {
    self.x = x;
    self.y = y;
    self.text_style = text_style;
    self.text = text;
});