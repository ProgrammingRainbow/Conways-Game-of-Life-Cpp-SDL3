#ifndef MAIN_H
#define MAIN_H

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <chrono>
#include <format>
#include <iostream>
#include <memory>
#include <random>
#include <thread>
#include <vector>

constexpr int SDL_FLAGS = SDL_INIT_VIDEO;

constexpr const char *WINDOW_TITLE = "Conway's Game of Life";
constexpr int WINDOW_WIDTH = 1280;
constexpr int WINDOW_HEIGHT = 720;

constexpr int SIZE = 10;
#define RENDERER_COLOR 0, 0, 0, 255
#define CELL_COLOR 128, 128, 128, 255

constexpr int TARGET_DELAY = 128;

#endif
