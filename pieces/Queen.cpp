//
// Created by dominik on 09.09.25.
//

#include "Queen.hpp"

#include "Piece.hpp"

Queen::Queen(Square * square, const Color color) : Piece(square, Type::Queen, color){}

void Queen::getPossibleMoves(std::vector<Move> &possibleMoves) const {
    getPossibleMovesInStraightDirections(possibleMoves);
    getPossibleMovesInDiagonalDirections(possibleMoves);
}
