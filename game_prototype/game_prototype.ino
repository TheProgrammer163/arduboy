
// Sam Sibbens
// 2018 NOVEMBER 01
// Unnamed project

#include <Arduino.h>
#include <Arduboy2.h>
Arduboy2 arduboy;

#include "Entity.h"
#include "Images.h"
#include "World.h"

constexpr uint8_t MAX_ENTITY_COUNT = 10;
Entity entities[MAX_ENTITY_COUNT];

Entity& player = entities[0];
Entity& knight = entities[1];

/* FUNCTIONS DECLARED AND DEFINED IN THIS FILE */
void draw_entities();


void setup() {
    arduboy.begin();
    arduboy.clear();
    arduboy.setFrameRate(60);
    arduboy.initRandomSeed();
    // ------------------------------ BUG HERE --------------
    player.type = EntityType::Player;
    // ------------------------- BUG END --------------
    player.x = 64 - 4;
    player.y = 16 - 4;
    
    for(uint8_t x = 0; x < WORLD_WIDTH; x++) {
        for(uint8_t y = 0; y < WORLD_HEIGHT; y++) {
            
            // clear the level
            level[x][y] = false;
            
            // make borders solid
            if (x == 0 || x == WORLD_WIDTH-1 || y == 0 || y == WORLD_HEIGHT-1) {
                level[x][y] = true;
                continue;
            }
            // randomly make some tiles solid
            if ((rand() % 5) <= 0) {level[x][y] = true;}
        }
    }
}


void loop() {

    //Prevent the Arduboy from running too fast
    if(!arduboy.nextFrame()) {return;}
  
    arduboy.clear();

    arduboy.fillScreen(WHITE);
    draw_walls();
    update_entities();
    arduboy.display();
}


/**** FUNCTIONS ****/
void update_entities() {
    for(uint8_t i = 0; i < MAX_ENTITY_COUNT; i++) {
        entities[i].update();
        entities[i].draw();
    }
}
