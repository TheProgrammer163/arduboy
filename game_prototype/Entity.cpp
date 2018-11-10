#include <Arduboy2.h>
#include "World.h"
#include "Images.h"

extern Arduboy2 arduboy;

enum class EntityType : uint8_t {
    None,
    Player,
    Knight,
    Sword,
};

enum class Direction : uint8_t {
    Down,
    Right,
    Left,
    Up,
};

struct Entity {
    public:
        int8_t x = 0;
        int8_t y = 0;
        EntityType type = EntityType::None;
        uint8_t damage_taken = 0;
        uint8_t state = 0;
        Direction facing = Direction::Down;
    public:
        void move(int8_t xmove, int8_t ymove);
        void update();
        void draw();
};

void Entity::move(int8_t xmove, int8_t ymove) {
    int8_t xnew = x + xmove;
    int8_t ynew = y + ymove;
    if(!::detect_wall(xnew, y)) {
        x = xnew;
    }
    if(!::detect_wall(x, ynew)) {
        y = ynew;
    }
}

void Entity::draw() {
    switch(type){
        case EntityType::Player:
            extern Arduboy2 arduboy;
            arduboy.drawBitmap(x, y, spr_human_outline, 8, 8, BLACK);
            arduboy.drawBitmap(x, y, spr_human, 8, 8, WHITE);
            break;
        default:
            break;
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
            speed = 2;
            break;
        default:
            break;
    }
    move(xinput*speed, yinput*speed);
}
