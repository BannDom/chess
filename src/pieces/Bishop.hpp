//
// Created by dominik on 09.09.25.
//

#ifndef CHESS_BISHOP_HPP
#define CHESS_BISHOP_HPP

#include "Piece.hpp"

class Bishop final : public Piece {
public:
    Bishop(Square * square, Color color);
    void getPossibleMoves(std::vector<Move> &possibleMoves) const override;
};


#endif //CHESS_BISHOP_HPP