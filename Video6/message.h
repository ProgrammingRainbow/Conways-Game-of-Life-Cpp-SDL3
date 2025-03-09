#ifndef TEXT_H
#define TEXT_H

#include "main.h"

class Message {
    public:
        Message(std::shared_ptr<SDL_Renderer> ren)
            : renderer{ren},
              font{nullptr, TTF_CloseFont},
              surface{nullptr, SDL_DestroySurface},
              image{nullptr, SDL_DestroyTexture},
              rect{10, 10, 0, 0},
              color{FONT_COLOR} {}

        void init(bool paused, double delay);
        void update(bool paused, double delay);
        void draw() const;

    private:
        std::shared_ptr<SDL_Renderer> renderer;
        std::unique_ptr<TTF_Font, decltype(&TTF_CloseFont)> font;
        std::unique_ptr<SDL_Surface, decltype(&SDL_DestroySurface)> surface;
        std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> image;
        SDL_FRect rect;
        SDL_Color color;
};

#endif
