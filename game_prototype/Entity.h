#pragma once

#include <Arduboy2.h>
#include "World.h"
#include "Images.h"

inline bool detect_wall(int8_t x, int8_t y);
inline void draw_walls();


constexpr uint8_t EntityWidth = 8;

enum class EntityType : uint8_t;;
enum class Direction : uint8_t;

struct Entity {
    public:
        int8_t x;
        int8_t y;
        EntityType type;
        uint8_t damage_taken;
        uint8_t state;
        Direction facing;
    public:
        void move(int8_t xmove, int8_t ymove);
        void update();
        void draw();
}

/*
extern Arduboy2 arduboy;

inline void draw_entity(Entity& ent) {
    uint8_t x = ent.x;
    uint8_t y = ent.y;
    switch(ent.type){
        case EntityType::Player:
            arduboy.drawBitmap(x, y, spr_human_outline, 8, 8, BLACK);
            arduboy.drawBitmap(x, y, spr_human, 8, 8, WHITE);
            break;
        default:
            break;
    }
}

inline void move_entity(Entity& ent, int8_t xmove, int8_t ymove) {
    int8_t xnew = ent.x + xmove;
    int8_t ynew = ent.y + ymove;
    if(!detect_wall(xnew, ent.y)) {
        ent.x = xnew;
    }
    if(!detect_wall(ent.x, ynew)) {
        ent.y = ynew;
    }
}

inline void update_entity(Entity& ent) {
    switch(ent.type){
        case EntityType::Player:
            int8_t xinput = 0;
            int8_t yinput = 0;
            int8_t playerspeed = 2;
            if(arduboy.pressed(LEFT_BUTTON)) {xinput--;}
            if(arduboy.pressed(RIGHT_BUTTON)) {xinput++;}
            if(arduboy.pressed(UP_BUTTON)) {yinput--;}
            if(arduboy.pressed(DOWN_BUTTON)) {yinput++;}
            move_entity(ent, xinput*playerspeed, yinput*playerspeed);
            break;
        default:
            break;
    }
}
*/
