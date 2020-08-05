#pragma once


constexpr uint8_t TILE_WIDTH = 8;
constexpr uint8_t TILE_HALF_WIDTH = 4;
constexpr uint8_t WORLD_WIDTH_IN_TILES = 48;
constexpr uint8_t WORLD_HEIGHT_IN_TILES = 32;
extern const uint8_t world[WORLD_WIDTH_IN_TILES*WORLD_HEIGHT_IN_TILES] PROGMEM;

constexpr uint8_t SECTION_WIDTH_IN_TILES = 16;
constexpr uint8_t SECTION_HEIGHT_IN_TILES = 8;
extern uint8_t loaded_world_section[SECTION_WIDTH_IN_TILES*SECTION_HEIGHT_IN_TILES];

int8_t x_on_grid(int16_t x);
int8_t y_on_grid(int16_t y);
uint8_t get_tile(uint8_t xIndex, uint8_t yIndex);
void set_tile(uint8_t xIndex, uint8_t yIndex, uint8_t value);
bool is_tile_solid(int16_t x, int16_t y);
bool detect_wall(int16_t x, int16_t y);
void draw_world();

int8_t x_on_grid_progmem(int16_t x);
int8_t y_on_grid_progmem(int16_t y);
uint8_t get_tile_progmem(uint8_t xIndex, uint8_t yIndex);
bool is_tile_solid_progmem(int16_t x, int16_t y);
bool detect_wall_progmem(int16_t x, int16_t y);
