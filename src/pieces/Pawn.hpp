//
// Created by dominik on 09.09.25.
//

#ifndef CHESS_PAWN_HPP
#define CHESS_PAWN_HPP

#include "Piece.hpp"

class Pawn final : public Piece {
public:
    Pawn(Square * square, Color color);
    void getPossibleMoves(std::vector<Move> &possibleMoves) const override;
};


#endif //CHESS_PAWN_HPP