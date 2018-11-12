
// Sam Sibbens
// 2018 NOVEMBER 01
// Unnamed project

#include <Arduino.h>
#include <Arduboy2.h>
Arduboy2 arduboy;

#include "Entity.h"
#include "Images.h"
#include "World.h"
#include "View.h"
View view;

constexpr uint8_t MAX_ENTITY_COUNT = 10;
Entity entities[MAX_ENTITY_COUNT];

Entity& player = entities[0];
Entity& knight = entities[1];

/* FUNCTIONS DECLARED AND DEFINED IN THIS FILE */
void draw_entities();


void setup() {
    arduboy.begin();
    arduboy.clear();
    arduboy.setFrameRate(30);
    arduboy.initRandomSeed();
    player.type = EntityType::Player;
    //player.x = 64;
    //player.y = 32;
    player.x = 22 * 8;
    player.y = 5 * 8;
}


void loop() {

    //Prevent the Arduboy from running too fast
    if(!arduboy.nextFrame()) {return;}
  
    arduboy.clear();

    //draw_world();
    update_entities();
    view.setPosition(player.x+TILE_HALF_WIDTH, player.y+(TILE_HALF_WIDTH/2));
    view.draw();
    draw_entities();
    arduboy.display();
}

void update_section() {
    for(uint8_t i = 0; i < SECTION_WIDTH_IN_TILES; i++) {
        for(uint8_t j = 0; j < SECTION_HEIGHT_IN_TILES; j++) {
            uint8_t tile = get_tile_progmem(i+view.x, j+view.y);
            set_tile(i, j, tile);
        }
    }
}


/**** FUNCTIONS ****/
void update_entities() {
    for(uint8_t i = 0; i < MAX_ENTITY_COUNT; i++) {
        entities[i].update();
    }
}
void draw_entities() {
    for(uint8_t i = 0; i < MAX_ENTITY_COUNT; i++) {
        entities[i].draw();
    }
}
