
#include <string.h>

#include "../nature.h"
#include "../colors.h"


#define DO_NOT_SHIFT 0
#define SHIFT_WITH_Y 1
#define SHIFT_WITH_INVERSE_Y 2

void generate_cliff(char**** cliff_data_v, char*** cliff_data_h, char** cliff_data_f, char shift_start_x, char shift_end_x) {
    const unsigned int CHAR_BUFFER_SIZE = 12;
    const char* CHAR_COLORING = YF "_" C;
    const unsigned int DISPLAYED_CHAR_OFFSET = 5; 

    char*** cliff_data_vertical = malloc(sizeof(char**) * SCENE_TILE_HEIGHT);
    char** cliff_data_horizontal = malloc(sizeof(char*) * SCENE_TILE_HEIGHT * SCENE_TILE_WIDTH);
    char* cliff_data = malloc(sizeof(char) * SCENE_TILE_HEIGHT * SCENE_TILE_WIDTH * CHAR_BUFFER_SIZE);
    for(int y = 0; y < SCENE_TILE_HEIGHT; y += 1) {
        cliff_data_vertical[y] = cliff_data_horizontal + y * SCENE_TILE_WIDTH;
        for(int x = 0; x < SCENE_TILE_WIDTH; x += 1) {
            cliff_data_horizontal[y * SCENE_TILE_WIDTH + x] = NULL;
        }
    }
    for(int y = 0; y < SCENE_TILE_HEIGHT; y += 1) {
        for(
            int x = (int) ((double) (shift_start_x == SHIFT_WITH_Y? y : (shift_start_x == SHIFT_WITH_INVERSE_Y? SCENE_TILE_HEIGHT - y : 0)) / SCENE_TILE_HEIGHT * SCENE_TILE_WIDTH);
            x < (int) ((double) (shift_end_x == SHIFT_WITH_Y? SCENE_TILE_HEIGHT - y : (shift_end_x == SHIFT_WITH_INVERSE_Y? y : SCENE_TILE_HEIGHT)) / SCENE_TILE_HEIGHT * SCENE_TILE_WIDTH);
            x += 1
        ) {
            char* char_buffer = cliff_data + (y * SCENE_TILE_WIDTH + x) * CHAR_BUFFER_SIZE;
            strcpy(char_buffer, CHAR_COLORING);
            char_buffer[DISPLAYED_CHAR_OFFSET] = rand() % 2 == 0? (rand() % 2 == 0? 'O' : 'o') : (rand() % 2 == 0? '.' : '|');
            cliff_data_horizontal[y * SCENE_TILE_WIDTH + x] = char_buffer;
        }
    }
    *cliff_data_v = cliff_data_vertical;
    *cliff_data_h = cliff_data_horizontal;
    *cliff_data_f = cliff_data;
}

static RenderObject CLIFF_RENDER_OBJECT = (RenderObject) {
    .data = NULL,
    .width = SCENE_TILE_WIDTH, .height = SCENE_TILE_HEIGHT,
    .anchor_x = 0, .anchor_y = -1
};

void render_cliff(RenderBuffer* buffer, char*** cliff_data_v, signed int x, signed int y) {
    CLIFF_RENDER_OBJECT.data = cliff_data_v;
    render_object(buffer, &CLIFF_RENDER_OBJECT, x, y);
}

IMPL_OBJECT(CLIFF_FULL, CliffFull, cliff_full, {
    render_cliff(buffer, self->cliff_data_v, self->x + scene->camera_ox, self->y + scene->camera_oy);
}, {
    free(self->cliff_data_v);
    free(self->cliff_data_h);
    free(self->cliff_data_f);
}, (Scene* scene, int x, int y), {
    self.x = x;
    self.y = y - 1;
    generate_cliff(&self.cliff_data_v, &self.cliff_data_h, &self.cliff_data_f, DO_NOT_SHIFT, DO_NOT_SHIFT);
});

IMPL_OBJECT(CLIFF_UP_LEFT, CliffUpLeft, cliff_up_left, {
    render_cliff(buffer, self->cliff_data_v, self->x + scene->camera_ox, self->y + scene->camera_oy);
}, {
    free(self->cliff_data_v);
    free(self->cliff_data_h);
    free(self->cliff_data_f);
}, (Scene* scene, int x, int y), {
    self.x = x;
    self.y = y - 1;
    generate_cliff(&self.cliff_data_v, &self.cliff_data_h, &self.cliff_data_f, SHIFT_WITH_Y, DO_NOT_SHIFT);
});

IMPL_OBJECT(CLIFF_UP_RIGHT, CliffUpRight, cliff_up_right, {
    render_cliff(buffer, self->cliff_data_v, self->x + scene->camera_ox, self->y + scene->camera_oy);
}, {
    free(self->cliff_data_v);
    free(self->cliff_data_h);
    free(self->cliff_data_f);
}, (Scene* scene, int x, int y), {
    self.x = x;
    self.y = y - 1;
    generate_cliff(&self.cliff_data_v, &self.cliff_data_h, &self.cliff_data_f, DO_NOT_SHIFT, SHIFT_WITH_Y);
});

IMPL_OBJECT(CLIFF_DOWN_LEFT, CliffDownLeft, cliff_down_left, {
    render_cliff(buffer, self->cliff_data_v, self->x + scene->camera_ox, self->y + scene->camera_oy);
}, {
    free(self->cliff_data_v);
    free(self->cliff_data_h);
    free(self->cliff_data_f);
}, (Scene* scene, int x, int y), {
    self.x = x;
    self.y = y - 1;
    generate_cliff(&self.cliff_data_v, &self.cliff_data_h, &self.cliff_data_f, SHIFT_WITH_INVERSE_Y, DO_NOT_SHIFT);
});

IMPL_OBJECT(CLIFF_DOWN_RIGHT, CliffDownRight, cliff_down_right, {
    render_cliff(buffer, self->cliff_data_v, self->x + scene->camera_ox, self->y + scene->camera_oy);
}, {
    free(self->cliff_data_v);
    free(self->cliff_data_h);
    free(self->cliff_data_f);
}, (Scene* scene, int x, int y), {
    self.x = x;
    self.y = y - 1;
    generate_cliff(&self.cliff_data_v, &self.cliff_data_h, &self.cliff_data_f, DO_NOT_SHIFT, SHIFT_WITH_INVERSE_Y);
});


IMPL_OBJECT(WATER, Water, water, {
    for(unsigned int y = 0; y < SCENE_TILE_HEIGHT; y += 1) {
        for(unsigned int x = 0; x < SCENE_TILE_WIDTH; x += 1) {
            write_onto_buffer(buffer, self->x + x + scene->camera_ox, self->y + y + scene->camera_oy, (rand() % 3 == 0? BB DF "~" C : BB DF " " C), self->y + y + scene->camera_oy - 1);
        }
    }
}, {}, (Scene* scene, int x, int y), {
    self.x = x;
    self.y = y;
});