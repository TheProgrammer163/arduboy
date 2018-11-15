#pragma once

#include <Arduino.h>


class WorldGen {
    public:
        static int8_t sin(int16_t n);
    private:
        static const uint8_t sineTableSize = 22;
        static const constexpr uint8_t sineTable[22] = {
            0, 7, 14, 21,
            28, 34, 41, 47,
            53, 59, 64, 69,
            
            74, 79, 83, 87,
            90, 93, 95, 97,
            98, 99, 
        };
};
