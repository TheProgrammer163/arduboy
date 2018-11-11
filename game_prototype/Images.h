#pragma once

/**** WORLD TILES ****/
// Humanoid (general sprites) //
const uint8_t spr_world[] PROGMEM  = {
    // Dimensions
    8, 8,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xef, 0xfd, 0xbf, 0xff, 0xf7, 0xff, 0xaf, 0xf5, 0xbe, 0xef, 0x5b, 0xf6, 0xdf, 0x7b, 0xff, 0xb7, 0xfd, 0xdf, 0xfb, 0xbf, 0xed, 0xff, 0x00, 0x22, 0x8, 0xa2, 0xa2, 0x8, 0x22, 0x00, 0x00, 0x2a, 0x54, 0xaa, 0xaa, 0x54, 0x2a, 0x00, 0x00, 0x7c, 0x62, 0x4a, 0x4a, 0x62, 0x7c, 0x00, 0x7c, 0x6, 0x2, 0x2, 0x2, 0x2, 0x6, 0x7c, 0x00, 0x52, 0xac, 0x92, 0x4a, 0xb4, 0x4a, 0x00, 0x00, 0x32, 0x48, 0x2a, 0x32, 0x48, 0x6a, 0x00, 0x00, 0x56, 0xb6, 0xb8, 0xc6, 0xb6, 0x7a, 0x00, 0xff, 0xe9, 0x96, 0xe9, 0xff, 0xd3, 0x2d, 0xd3, 0xbf, 0x47, 0x3b, 0x65, 0xf2, 0x4c, 0xee, 0xde, 0x9e, 0xee, 0x4c, 0xf2, 0x65, 0xbb, 0x47, 0xbf, 0xff, 0xfc, 0xfb, 0xf6, 0xac, 0x4a, 0x2d, 0x49, 0x2c, 0x49, 0xe, 0xac, 0xf6, 0xfb, 0xfc, 0xff, 
};


/*** HUMANOID SPRITES ***/
// Humanoid (general sprites) //
const uint8_t spr_human_outline[] PROGMEM  = {
    0x3f, 0xe1, 0xad, 0xa1, 0xa1, 0xad, 0xe1, 0x3f,
};
const uint8_t spr_human[] PROGMEM  = {
    0x00, 0x1e, 0x5e, 0x5e, 0x5e, 0x5e, 0x1e, 0x00,
};

// Player Faces //
const uint8_t spr_player_down[] PROGMEM  = {
    0x3f, 0xe1, 0xad, 0xa1, 0xa1, 0xad, 0xe1, 0x3f,
};
const uint8_t spr_player_right[] PROGMEM  = {
    0x00, 0x1e, 0x5e, 0x52, 0x5e, 0x52, 0x1e, 0x00, 
};
const uint8_t spr_player_left[] PROGMEM  = {
    0x00, 0x1e, 0x52, 0x5e, 0x52, 0x5e, 0x1e, 0x00, 
};


/*** WORLD SPRITES ***/
const uint8_t spr_wall[] PROGMEM  = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
};
