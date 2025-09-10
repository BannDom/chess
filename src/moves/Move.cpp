//
// Created by dominik on 16.08.25.
//

#include "Move.hpp"
#include "../boards/Square.hpp"

Move::Move(Square *from, Square *to) : _from(from), _to(to) {}

const Square * Move::getFrom() const {
    return _from;
}

const Square * Move::getTo() const {
    return _to;
}

std::ostream& operator<<(std::ostream& os, const Move& m) {
    return os << "Move(from: " << m._from << ", to: " << m._to << ", rating: " << m.rating << ")";
}

