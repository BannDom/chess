//
// Created by dominik on 17.08.25.
//

#ifndef CHESS_IBOARD_HPP
#define CHESS_IBOARD_HPP

#include <memory>

#include "Square.hpp"

class IBoard {
protected:
    std::unique_ptr<Square> createSquare(size_t x, size_t y) {
        return std::unique_ptr<Square>(new Square(x, y, this));
    }

public:
    [[nodiscard]] virtual Square* getSquare(size_t x, size_t y) const = 0;
    [[nodiscard]] virtual bool hasSquare(size_t x, size_t y) const = 0;

    [[nodiscard]] virtual size_t getWidth() const = 0;
    [[nodiscard]] virtual size_t getHeight() const = 0;

    virtual ~IBoard() = default;
};

#endif //CHESS_IBOARD_HPP
