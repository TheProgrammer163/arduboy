#pragma once

constexpr uint8_t WORLD_WIDTH = 16;
constexpr uint8_t WORLD_HEIGHT = 8;
bool level[WORLD_WIDTH][WORLD_HEIGHT];

inline int8_t x_on_grid(int16_t x);
inline int8_t y_on_grid(int16_t y);
inline bool is_tile_solid(int16_t x, int16_t y);
inline void draw_walls();
inline bool detect_wall(int8_t x, int8_t y);
