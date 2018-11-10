#pragma once

#include <Arduboy2.h>
#include "World.h"
#include "Images.h"

bool detect_wall(int8_t x, int8_t y);
void draw_walls();


constexpr uint8_t EntityWidth = 8;

enum class EntityType : uint8_t;
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
};
