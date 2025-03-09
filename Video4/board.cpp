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

void Board::edit(float x, float y) {
    auto column = static_cast<std::size_t>(x / SIZE);
    auto row = static_cast<std::size_t>(y / SIZE);
    if (row < rows && column < this->columns) {
        this->board[row][column] = 1 - this->board[row][column];
    }
}

void Board::update() {
    const int int_rows = static_cast<int>(this->rows);
    const int int_columns = static_cast<int>(this->columns);
    for (int row = 0; row < int_rows; ++row) {
        for (int column = 0; column < int_columns; ++column) {
            int count = 0;
            for (int y = row - 1; y <= row + 1; ++y) {
                for (int x = column - 1; x <= column + 1; ++x) {
                    if (y == row && x == column)
                        continue;
                    auto wrapped_row =
                        static_cast<std::size_t>((y + int_rows) % int_rows);
                    auto wrapped_column = static_cast<std::size_t>(
                        (x + int_columns) % int_columns);
                    count += this->board[wrapped_row][wrapped_column];
                }
            }
            auto uint_row = static_cast<std::size_t>(row);
            auto uint_column = static_cast<std::size_t>(column);
            if (this->board[uint_row][uint_column] == 1 &&
                (count > 1 && count < 4)) {
                this->next_board[uint_row][uint_column] = 1;
            } else if (this->board[uint_row][uint_column] == 0 && count == 3) {
                this->next_board[uint_row][uint_column] = 1;
            } else {
                this->next_board[uint_row][uint_column] = 0;
            }
        }
    }
    this->board.swap(this->next_board);
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
