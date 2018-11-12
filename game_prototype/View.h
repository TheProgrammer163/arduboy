#pragma once

#include "Arduino.h"
#include "World.h"

class View {
    public:
        uint16_t x = 0;
        uint16_t y = 0;
        uint8_t width = 128;
        uint8_t height = 64;
    public:
        void setPosition(int16_t xpos, int16_t ypos);
        void draw();
};
