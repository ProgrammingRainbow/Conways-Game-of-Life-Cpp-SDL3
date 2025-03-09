#include "board.h"

void Board::init() { reset(); }

void Board::reset() {
    for (std::size_t row = 0; row < this->rows; ++row) {
        for (std::size_t column = 0; column < this->columns; ++column) {
            this->board[row][column] = rand_cell(this->gen);
        }
    }
}

void Board::clear() {
    for (std::size_t row = 0; row < this->rows; ++row) {
        for (std::size_t column = 0; column < this->columns; ++column) {
            this->board[row][column] = 0;
        }
    }
}

void Board::draw() const {
    SDL_SetRenderDrawColor(this->renderer.get(), CELL_COLOR);
    SDL_FRect rect{0, 0, SIZE - 1, SIZE - 1};
    for (std::size_t row = 0; row < this->rows; ++row) {
        rect.y = static_cast<float>(row) * SIZE;
        for (std::size_t column = 0; column < this->columns; ++column) {
            rect.x = static_cast<float>(column * SIZE);
            if (board[row][column] == 1) {
                SDL_RenderFillRect(this->renderer.get(), &rect);
            }
        }
    }
}
