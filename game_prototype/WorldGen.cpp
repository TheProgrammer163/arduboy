
#include <Arduino.h>
#include "WorldGen.h"

int8_t WorldGen::sin(int16_t n) {
    bool positive = (0 <= n);
    int16_t i = (n % (sineTableSize * 2));
    uint8_t secondQuadrant = false;
    if (sineTableSize <= i) {
        secondQuadrant = true;
    }
    i = (i % sineTableSize);

    
    int8_t result = 0;
    if (secondQuadrant) {
        i = (sineTableSize - 1 - i);
    }
    result = sineTable[i];
    if (!positive) {
        result *= -1;
    }

    return result;
};
