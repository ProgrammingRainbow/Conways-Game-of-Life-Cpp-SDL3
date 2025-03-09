#ifndef BOARD_H
#define BOARD_H

#include "main.h"

class Board {
    public:
        Board(std::shared_ptr<SDL_Renderer> ren)
            : renderer{ren},
              rows{WINDOW_HEIGHT / SIZE},
              columns{WINDOW_WIDTH / SIZE},
              board{(unsigned)rows, std::vector<int>((unsigned)columns, 0)},
              next_board{(unsigned)rows,
                         std::vector<int>((unsigned)columns, 0)},
              rd{},
              gen{rd()},
              rand_cell{0, 1} {}

        void init();
        void reset();
        void clear();
        void draw() const;

    private:
        std::shared_ptr<SDL_Renderer> renderer;
        const std::size_t rows;
        const std::size_t columns;
        std::vector<std::vector<int>> board;
        std::vector<std::vector<int>> next_board;
        std::random_device rd;
        std::mt19937 gen;
        std::uniform_int_distribution<int> rand_cell;
};

#endif
