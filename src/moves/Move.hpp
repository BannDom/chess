//
// Created by dominik on 16.08.25.
//

#ifndef SHESS_MOVE_HPP
#define SHESS_MOVE_HPP

#include <iostream>

class Square;

class Move {
    Square * _from;
    Square * _to;

public:
    double  rating {0.0};

    Move(Square * from, Square * to);

    [[nodiscard]] const Square * getFrom() const;
    [[nodiscard]] const Square * getTo() const;

    friend std::ostream& operator<<(std::ostream& os, const Move& m);
};


#endif //SHESS_MOVE_HPP
