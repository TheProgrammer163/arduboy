#include <Arduboy2.h>
#include "World.h"
#include "Images.h"
#include "Entity.h"
#include "View.h"

extern Arduboy2 arduboy;

void Entity::move(int8_t xmove, int8_t ymove) {
    int16_t xnew = x + xmove;
    int16_t ynew = y + ymove;
    xnew = max(xnew, -TILE_HALF_WIDTH);
    xnew = min(xnew, WORLD_WIDTH_IN_TILES * TILE_WIDTH-1-TILE_HALF_WIDTH);
    ynew = max(ynew, -TILE_HALF_WIDTH);
    ynew = min(ynew, WORLD_HEIGHT_IN_TILES * TILE_WIDTH-1-TILE_HALF_WIDTH);
    if(!::detect_wall_progmem(xnew, y)) {
        x = xnew;
    }
    if(!::detect_wall_progmem(x, ynew)) {
        y = ynew;
    }
}

extern View view;

uint8_t Entity::getSprite(EntityType type) {
    switch (type) {
        case EntityType::Player:
            return &spr_player;
    }
}

void Entity::draw() {
    int16_t drawx = x - view.x * view.width;
    int16_t drawy = y - view.y * view.height;
    switch(type){
        case EntityType::Player:
            Sprites::drawExternalMask(drawx, drawy, spr_player, spr_humanoid_mask, static_cast<uint8_t>(facing), 0);
            break;
        case EntityType::Knight:
            Sprites::drawExternalMask(drawx, drawy, spr_knight, spr_humanoid_mask, static_cast<uint8_t>(facing), 0);
            Sprites::drawExternalMask(drawx, drawy-8, spr_knight_feather, spr_knight_feather_mask, static_cast<uint8_t>(facing), static_cast<uint8_t>(facing));
            break;
        default:
            break;
    }
}

void Entity::updateFacing(int8_t xinput, int8_t yinput) {
    if (xinput != 0) {
        if (0 < xinput) {
            facing = Direction::Right;
        } else {
            facing = Direction::Left;
        }
    } else if (yinput != 0) {
        if (0 < yinput) {
            facing = Direction::Down;
        } else {
            facing = Direction::Up;
        }
    }
}

void Entity::update() {
    int8_t xinput = 0;
    int8_t yinput = 0;
    int8_t speed = 0;
    switch(type){
        case EntityType::Player:
            if(arduboy.pressed(LEFT_BUTTON)) {xinput--;}
            if(arduboy.pressed(RIGHT_BUTTON)) {xinput++;}
            if(arduboy.pressed(UP_BUTTON)) {yinput--;}
            if(arduboy.pressed(DOWN_BUTTON)) {yinput++;}
            updateFacing(xinput, yinput);
            speed = 1;
            break;
        default:
            break;
    }
    if (!(arduboy.pressed(A_BUTTON) || arduboy.pressed(B_BUTTON))) {
        move(xinput*speed, yinput*speed);
    }
}
