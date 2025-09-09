//
// Created by dominik on 09.09.25.
//

#ifndef CHESS_KNIGHT_HPP
#define CHESS_KNIGHT_HPP


#include "Piece.hpp"

class Knight final : public Piece {
public:
    Knight(Square * square, Color color);
    void getPossibleMoves(std::vector<Move> &possibleMoves) const override;
};


#endif //CHESS_KNIGHT_HPP