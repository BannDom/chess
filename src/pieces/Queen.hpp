//
// Created by dominik on 09.09.25.
//

#ifndef CHESS_QUEEN_HPP
#define CHESS_QUEEN_HPP

#include "Piece.hpp"

class Queen final : public Piece {

public:
    Queen(Square * square, Color color);
    void getPossibleMoves(std::vector<Move> &possibleMoves) const override;
};


#endif //CHESS_QUEEN_HPP