//
// Created by dominik on 17.08.25.
//

#include <stdexcept>
#include "King.hpp"

King::King(Square *square, const Color color) : Piece(square, Type::King, color) {}

void King::getPossibleMoves(std::vector<Move> &possibleMoves) const {
    std::vector<Square*> neighbors{};
    neighbors.reserve(8);
    _currentSquare->getNeighbors(neighbors);

    for (Square* neighbor : neighbors) {
        if (neighbor->isOccupied() && neighbor->getPiece()->getColor() != _color || neighbor->isProtected(_color)) {
            possibleMoves.emplace_back(_currentSquare, neighbor);
        }
    }
}
