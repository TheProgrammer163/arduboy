#pragma once

constexpr uint8_t WORLD_WIDTH = 16;
constexpr uint8_t WORLD_HEIGHT = 8;
extern uint8_t level[WORLD_WIDTH*WORLD_HEIGHT];

int8_t x_on_grid(int16_t x);
int8_t y_on_grid(int16_t y);
uint8_t get_tile(uint8_t xIndex, uint8_t yIndex);
bool is_tile_solid(int16_t x, int16_t y);
void draw_walls();
bool detect_wall(int8_t x, int8_t y);
