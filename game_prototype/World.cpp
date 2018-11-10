#include <Arduboy2.h>
#include "World.h"
#include "Images.h"

extern Arduboy2 arduboy;

constexpr uint8_t TILE_WIDTH = 8;

bool level[WORLD_WIDTH][WORLD_HEIGHT];

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

bool is_tile_solid(int16_t x, int16_t y) {
    return level[x][y];
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
            if (is_tile_solid(x, y)) {
                arduboy.drawBitmap(x*TILE_WIDTH, y*TILE_WIDTH, spr_wall, 8, 8, BLACK);
            }
        }
    }
}
