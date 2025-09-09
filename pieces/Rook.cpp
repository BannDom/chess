//
// Created by dominik on 09.09.25.
//

#include "Rook.hpp"

Rook::Rook(Square *square, const Color color) : Piece(square, Type::Rook, color) {}

void Rook::getPossibleMoves(std::vector<Move> &possibleMoves) const {
    getPossibleMovesInStraightDirections(possibleMoves);
}
