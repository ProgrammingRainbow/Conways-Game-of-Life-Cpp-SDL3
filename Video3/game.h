#ifndef GAME_H
#define GAME_H

#include "main.h"
#include "board.h"

class Game {
    public:
        Game()
            : window{nullptr, SDL_DestroyWindow},
              renderer{nullptr, SDL_DestroyRenderer},
              board{nullptr},
              event{},
              is_running{true} {}
        ~Game();

        void init_sdl();
        void init();
        void run();

    private:
        void events();
        void draw() const;

        std::shared_ptr<SDL_Window> window;
        std::shared_ptr<SDL_Renderer> renderer;
        std::unique_ptr<Board> board;
        SDL_Event event;
        bool is_running;
};

#endif
