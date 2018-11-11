
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
    arduboy.setFrameRate(30);
    arduboy.initRandomSeed();
    player.type = EntityType::Player;
    player.x = 64 - 4;
    player.y = 32 - 4;
}


void loop() {

    //Prevent the Arduboy from running too fast
    if(!arduboy.nextFrame()) {return;}
  
    arduboy.clear();

    //arduboy.fillScreen(WHITE);
    draw_world();
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
