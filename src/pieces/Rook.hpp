//
// Created by dominik on 09.09.25.
//

#ifndef CHESS_ROOK_HPP
#define CHESS_ROOK_HPP

#include "Piece.hpp"

class Rook final : public Piece {
public:
    Rook(Square * square, Color color);
    void getPossibleMoves(std::vector<Move> &possibleMoves) const override;
};


#endif //CHESS_ROOK_HPP