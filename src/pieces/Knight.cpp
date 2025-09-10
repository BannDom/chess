//
// Created by dominik on 09.09.25.
//

#include "Knight.hpp"

Knight::Knight(Square * square, const Color color) : Piece(square, Type::Queen, color){}

void Knight::getPossibleMoves(std::vector<Move> &possibleMoves) const {
    std::vector<Square * > surroundingKnightSquares{};
    _currentSquare->getSurroundingKnightSquares(surroundingKnightSquares);

    for (Square * square : surroundingKnightSquares) {
        if (!square->isOccupied() || square->getPiece()->getColor() != _color) {
            possibleMoves.emplace_back(_currentSquare, square);
        }
    }
}

