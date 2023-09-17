
#include <stdlib.h>
#include <limits.h>

#include "path_find.h"


typedef struct TileData {
    unsigned int parent_x;
    unsigned int parent_y;
    unsigned int g_cost; // steps from starting tile
    unsigned int f_cost; // sum of g_cost and h_cost (h_cost is computed when needed)
    enum {
        UNREACHABLE,
        REACHABLE,
        TRAVERSED
    } state;
} TileData;

char find_path(
    char* tiles_traversable_flattened,
    unsigned int area_width,
    unsigned int area_height,
    unsigned int start_x,
    unsigned int start_y,
    unsigned int end_x,
    unsigned int end_y,
    unsigned int** steps,
    unsigned int* step_count
) {
    // store tile info for each tile in the area
    TileData tiles[area_height][area_width];
    for(unsigned int y = 0; y < area_height; y += 1) {
        for(unsigned int x = 0; x < area_width; x += 1) {
            tiles[y][x].state = UNREACHABLE;
        }
    }
    // set the start tile to be reachable and set it's cost to 0
    tiles[start_y][start_x].state = REACHABLE;
    tiles[start_y][start_x].g_cost = 0;
    tiles[start_y][start_x].f_cost = 0;
    // search for the path
    for(;;) {
        // select the reachable tile with the lowest cost
        unsigned int current_x;
        unsigned int current_y;
        TileData* current = NULL;
        {
            unsigned int current_cost = UINT_MAX;
            for(unsigned int y = 0; y < area_height; y += 1) {
                for(unsigned int x = 0; x < area_width; x += 1) {
                    TileData* tile = &tiles[y][x];
                    if(tile->state != REACHABLE
                    || tile->f_cost > current_cost) { continue; }
                    current_x = x;
                    current_y = y;
                    current = tile;
                    current_cost = tile->f_cost;
                }
            }
        }
        // check for end
        if(current == NULL) { // no tile found! there is no valid path...
            return 0;
        }
        if(current_x == end_x && current_y == end_y) { // tile is at end position! we found a path!
            // figure out the amount of steps to get there
            if(step_count != NULL) {
                *step_count = 0;
                unsigned int step_x = current_x;
                unsigned int step_y = current_y;
                while(step_x != start_x || step_y != start_y) {
                    TileData* tile = &tiles[step_y][step_x];
                    step_x = tile->parent_x;
                    step_y = tile->parent_y;
                    *step_count += 1;
                }
            }
            // put the steps into a list
            if(steps != NULL) {
                *steps = malloc(sizeof(unsigned int) * 2 * *step_count);
                unsigned int step_x = current_x;
                unsigned int step_y = current_y;
                for(unsigned int s = 1; s <= *step_count; s += 1) {
                    (*steps)[(*step_count - s) * 2    ] = step_x;
                    (*steps)[(*step_count - s) * 2 + 1] = step_y;
                    TileData* tile = &tiles[step_y][step_x];
                    step_x = tile->parent_x;
                    step_y = tile->parent_y;
                }
            }
            return 1;
        }
        // mark the tile as traversed
        current->state = TRAVERSED;
        // update neighbours
        for(signed int n = 0; n < 4; n += 1) {
            // calculate neighbour position based on index
            // magical expressions save us from writing a giant switch
            signed long neighbour_x = current_x + (n / 2 == 0? (n % 2) * 2 - 1 : 0);
            signed long neighbour_y = current_y + (n / 2 == 1? (n % 2) * 2 - 1 : 0);
            TileData* neighbour = &tiles[neighbour_y][neighbour_x];
            // if the neighbour is not in bounds, not traversable or already traversed, skip it
            if(neighbour_x < 0
            || neighbour_y < 0
            || neighbour_x >= area_width
            || neighbour_y >= area_height
            || tiles_traversable_flattened[neighbour_y * area_width + neighbour_x] == 0
            || neighbour->state == TRAVERSED) { continue; }
            // if the neighbour is not reachable or the new path over the current tile would be shorter, update the cost and parent
            if(neighbour->state != REACHABLE || current->g_cost + 1 < neighbour->g_cost) {
                neighbour->g_cost = current->g_cost + 1;
                unsigned int neighbour_h_cost = (end_x > neighbour_x? end_x - neighbour_x : neighbour_x - end_x)
                        + (end_y > neighbour_y? end_y - neighbour_y : neighbour_y - end_y);
                neighbour->f_cost = neighbour->g_cost + neighbour_h_cost;
                neighbour->parent_x = current_x;
                neighbour->parent_y = current_y;
                neighbour->state = REACHABLE;
            }
        }
    }
}