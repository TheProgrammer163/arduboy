

#include <Arduboy2.h>
#include "View.h"
#include "World.h"
#include "Images.h"

// Move the view
void View::setPosition(int16_t xpos, int16_t ypos) {
    int16_t xtarget = xpos;
    int16_t ytarget = ypos;
    
    xtarget = max(xtarget, 0);
    xtarget = min(xtarget, (WORLD_WIDTH_IN_TILES * width) - 1);

    ytarget = max(ytarget, 0);
    ytarget = min(ytarget, (WORLD_HEIGHT_IN_TILES * height) - 1);
    
    x = xtarget / width;
    y = ytarget / height;
}

// draw the world
void View::draw() {
    for(uint8_t i = 0; i < SECTION_WIDTH_IN_TILES; i++) {
        for(uint8_t j = 0; j < SECTION_HEIGHT_IN_TILES; j++) {
            uint8_t tile = get_tile_progmem(i+x*SECTION_WIDTH_IN_TILES, j+y*SECTION_HEIGHT_IN_TILES);
            Sprites::drawSelfMasked(i*TILE_WIDTH, j*TILE_WIDTH, spr_world, tile);
        }
    }
}
