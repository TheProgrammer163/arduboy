#pragma once

#include <Arduboy2.h>
#include "World.h"
#include "Images.h"

bool detect_wall(int8_t x, int8_t y);
void draw_walls();


constexpr uint8_t EntityWidth = 8;

enum class EntityType : uint8_t {
    None,
    Player,
    Knight,
    Sword,
};

enum class Direction : uint8_t {
    Right,
    Down,
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
