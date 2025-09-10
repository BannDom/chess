//
// Created by dominik on 17.08.25.
//

#ifndef CHESS_BOARD_HPP
#define CHESS_BOARD_HPP

#include <array>

#include "IBoard.hpp"
#include "Square.hpp"

template <std::size_t X, std::size_t Y>
class Board : public IBoard {
    std::array<std::array<std::unique_ptr<Square>, X>, Y> _squares;

public:
    Board() {
        for (size_t x{0}; x < X; ++x) {
            for (size_t y{0}; y < Y; ++y) {
                _squares[x][y] = createSquare(x, y);
            }
        }
    }

    [[nodiscard]] Square* getSquare(const size_t x, const size_t y) const override {
        if (x >= X || y >= Y) {
            throw std::out_of_range("Square coordinates out of bounds");
        }
        return _squares[x][y].get();
    }

    [[nodiscard]] bool hasSquare(const size_t x, const size_t y) const override {
        return x < X && y < Y;
    }

    [[nodiscard]] size_t getWidth() const override {
        return X;
    }

    [[nodiscard]] size_t getHeight() const override {
        return Y;
    }
};

#endif //CHESS_BOARD_HPP
