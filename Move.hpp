//
// Created by dominik on 16.08.25.
//

#ifndef SHESS_MOVE_HPP
#define SHESS_MOVE_HPP

#include "board/Square.hpp"

class Move {
    Square * _from;
    Square * _to;

public:
    double  rating {0.0};

    Move(Square * from, Square * to) : _from(from), _to(to) {}

    [[nodiscard]] const Square * getFrom() const {
        return _from;
    }

    [[nodiscard]] const Square * getTo() const {
        return _to;
    }

    friend std::ostream& operator<<(std::ostream& os, const Move& m) {
        return os << "Move(from: " << m._from << ", to: " << m._to << ", rating: " << m.rating << ")";
    }
};


#endif //SHESS_MOVE_HPP
