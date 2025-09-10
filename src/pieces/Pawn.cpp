//
// Created by dominik on 09.09.25.
//

#include "Pawn.hpp"

Pawn::Pawn(Square *square, const Color color) : Piece(square, Type::Pawn, color) {}

void Pawn::getPossibleMoves(std::vector<Move> &possibleMoves) const {
    if (_color == Color::White) {
        if (_currentSquare->hasSquareAbove() && !_currentSquare->getSquareAbove()->isOccupied()) {
            Square * squareAbove = _currentSquare->getSquareAbove();
            possibleMoves.emplace_back(_currentSquare,  squareAbove);
            if (_currentSquare->getY() == 1 && squareAbove->hasSquareAbove() && !squareAbove->getSquareAbove()->isOccupied()) {
                possibleMoves.emplace_back(_currentSquare,  squareAbove->getSquareAbove());
            }
        }
        if (_currentSquare->hasSquareAboveLeft() && _currentSquare->getSquareAboveLeft()->isOccupied() &&
            _currentSquare->getSquareAboveLeft()->getPiece()->getColor() != _color) {
            possibleMoves.emplace_back(_currentSquare,  _currentSquare->getSquareAboveLeft());
        }
        if (_currentSquare->hasSquareAboveRight() && _currentSquare->getSquareAboveRight()->isOccupied() &&
            _currentSquare->getSquareAboveRight()->getPiece()->getColor() != _color) {
            possibleMoves.emplace_back(_currentSquare,  _currentSquare->getSquareAboveRight());
        }
    } else {
        if (_currentSquare->hasSquareBelow() && !_currentSquare->getSquareBelow()->isOccupied()) {
            Square * squareBelow = _currentSquare->getSquareBelow();
            possibleMoves.emplace_back(_currentSquare,  squareBelow);
            if (_currentSquare->getY() == 6 && squareBelow->hasSquareBelow() && !squareBelow->getSquareBelow()->isOccupied()) {
                possibleMoves.emplace_back(_currentSquare,  squareBelow->getSquareBelow());
            }
        }
        if (_currentSquare->hasSquareBelowLeft() && _currentSquare->getSquareBelowLeft()->isOccupied() &&
            _currentSquare->getSquareBelowLeft()->getPiece()->getColor() != _color) {
            possibleMoves.emplace_back(_currentSquare,  _currentSquare->getSquareBelowLeft());
        }
        if (_currentSquare->hasSquareBelowRight() && _currentSquare->getSquareBelowRight()->isOccupied() &&
            _currentSquare->getSquareBelowRight()->getPiece()->getColor() != _color) {
            possibleMoves.emplace_back(_currentSquare,  _currentSquare->getSquareBelowRight());
        }
    }
    ////TODO: En Passant
    ////TODO: Promotion
    ////TODO: Check if move would put own king in check
}