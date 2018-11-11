#include <Arduboy2.h>
#include "World.h"
#include "Images.h"

extern Arduboy2 arduboy;

constexpr uint8_t TILE_WIDTH = 8;

uint8_t level[WORLD_WIDTH*WORLD_HEIGHT] = {
    1,1,0,0,0,2,0,0,0,0,0,12,13,1,1,1,
    0,5,5,5,0,2,1,12,13,4,4,4,15,0,11,1,
    0,5,5,5,5,2,1,14,15,4,4,4,1,0,11,11,
    1,6,5,5,5,2,1,1,0,6,7,6,1,1,1,0,
    1,1,6,7,6,2,2,2,2,2,2,2,2,2,2,2,
    2,2,2,2,2,2,1,1,1,11,0,1,1,1,0,0,
    1,1,1,1,1,1,0,11,11,11,11,0,0,0,0,1,
    1,1,1,0,0,0,0,0,11,11,1,1,1,1,1,1,
};

int8_t x_on_grid(int16_t x) {
    x = (x / TILE_WIDTH);
    x = max(x, 0);
    x = min(x, WORLD_WIDTH-1);
    
    return x;
}

int8_t y_on_grid(int16_t y) {
    y = (y / TILE_WIDTH);
    y = max(y, 0);
    y = min(y, WORLD_HEIGHT-1);
    
    return y;
}

uint8_t get_tile(uint8_t xIndex, uint8_t yIndex) {
    return level[WORLD_WIDTH * yIndex + xIndex];  
}

bool is_tile_solid(int16_t x, int16_t y) {
    return (4 <= get_tile(x, y));
}

bool detect_wall(int8_t x, int8_t y) {
    int8_t x1 = x_on_grid(x);
    int8_t x2 = x_on_grid(x+TILE_WIDTH-1);
    int8_t y1 = y_on_grid(y);
    int8_t y2 = y_on_grid(y+TILE_WIDTH-1);
    
    return ((is_tile_solid(x1, y1) || is_tile_solid(x2, y1) || is_tile_solid(x2, y2) || is_tile_solid(x1, y2)));
}

void draw_walls() {
    for(uint8_t x = 0; x < WORLD_WIDTH; x++) {
        for(uint8_t y = 0; y < WORLD_HEIGHT; y++) {
            uint8_t frame = get_tile(x, y);
            Sprites::drawOverwrite (x*8, y*8, spr_world, frame); 
        }
    }
}
