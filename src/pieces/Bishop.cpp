//
// Created by dominik on 09.09.25.
//

#include "Bishop.hpp"

Bishop::Bishop(Square *square, const Color color) : Piece(square , Type::Bishop, color) {}

void Bishop::getPossibleMoves(std::vector<Move> &possibleMoves) const {
    getPossibleMovesInDiagonalDirections(possibleMoves);
}
