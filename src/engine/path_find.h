
#pragma once


// finds a path
// -> returns if a path was found
char find_path(
    char* tiles_traversable_flattened, // flattened 1D array (i = y * width + x) of tiles, where 0 means not traversable
    unsigned int area_width, // width of the searched area
    unsigned int area_height, // height of the searched area
    unsigned int start_x, // start position x, must be less than area_width
    unsigned int start_y, // start position y, must be less than area_height
    unsigned int end_x, // end position x, must be less than area_width
    unsigned int end_y, // end position y, must be less than area_height
    unsigned int** steps, // pointer to the variable to store the resulting step array in (x = s * 2, y = s * 2 + 1) (must be freed after usage), may be null
    unsigned int* step_count // pointer to the variable to store the step count in, may be null
);