#include "init_sdl.h"

void Game::init_sdl() {
    if (!SDL_Init(SDL_FLAGS) != 0) {
        auto error = std::format("Error initializing SDL: {}", SDL_GetError());
        throw std::runtime_error(error);
    }

    this->window.reset(
        SDL_CreateWindow(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT, 0),
        SDL_DestroyWindow);
    if (!this->window) {
        auto error = std::format("Error creating window: {}", SDL_GetError());
        throw std::runtime_error(error);
    }

    this->renderer.reset(SDL_CreateRenderer(this->window.get(), NULL),
                         SDL_DestroyRenderer);
    if (!this->renderer) {
        auto error = std::format("Error creating renderer: {}", SDL_GetError());
        throw std::runtime_error(error);
    }
}
