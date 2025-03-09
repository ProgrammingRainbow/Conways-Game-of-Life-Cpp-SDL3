#ifndef GAME_H
#define GAME_H

#include "main.h"
#include "board.h"
#include "fps.h"
#include "message.h"

class Game {
    public:
        Game()
            : window{nullptr, SDL_DestroyWindow},
              renderer{nullptr, SDL_DestroyRenderer},
              board{nullptr},
              fps{nullptr},
              message{nullptr},
              event{},
              is_running{true},
              is_paused{false} {}
        ~Game();

        void init_sdl();
        void init();
        void run();

    private:
        void togglePause();
        void increaseSpeed();
        void decreaseSpeed();
        void events();
        void update();
        void draw() const;

        std::shared_ptr<SDL_Window> window;
        std::shared_ptr<SDL_Renderer> renderer;
        std::unique_ptr<Board> board;
        std::unique_ptr<Fps> fps;
        std::unique_ptr<Message> message;
        SDL_Event event;
        bool is_running;
        bool is_paused;
};

#endif
