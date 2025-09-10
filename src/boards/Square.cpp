//
// Created by dominik on 16.08.25.
//
#include "Square.hpp"
#include "IBoard.hpp"
#include "../pieces/Piece.hpp"

#include <algorithm>

Square::Square(const size_t x, const size_t y, IBoard *board) : _x(x), _y(y), _board(board) {
    if (!_board->hasSquare(x, y)) {
        throw std::runtime_error("Board cannot be null");
    }
}

bool Square::isProtectedFromBelowRight(const Color playerColor) const {
    return isProtectedFromDirection(
        &Square::hasSquareBelowRight,
        &Square::getSquareBelowRight,
        &Piece::canProtectDiagonal,
        playerColor
    );
}

bool Square::isProtectedFromAboveRight(const Color playerColor) const {
    return isProtectedFromDirection(
        &Square::hasSquareAboveRight,
        &Square::getSquareAboveRight,
        &Piece::canProtectDiagonal,
        playerColor
    );
}

bool Square::isProtectedFromBelowLeft(const Color playerColor) const {
    return isProtectedFromDirection(
        &Square::hasSquareBelowLeft,
        &Square::getSquareBelowLeft,
        &Piece::canProtectDiagonal,
        playerColor
    );
}

bool Square::isProtectedFromAboveLeft(const Color playerColor) const {
    return isProtectedFromDirection(
        &Square::hasSquareAboveLeft,
        &Square::getSquareAboveLeft,
        &Piece::canProtectDiagonal,
        playerColor
    );
}

bool Square::isProtectedFromBelow(const Color playerColor) const {
    return isProtectedFromDirection(
        &Square::hasSquareBelow,
        &Square::getSquareBelow,
        &Piece::canProtectStraight,
        playerColor
    );
}

bool Square::isProtectedFromAbove(const Color playerColor) const {
    return isProtectedFromDirection(
        &Square::hasSquareAbove,
        &Square::getSquareAbove,
        &Piece::canProtectStraight,
        playerColor
    );
}

bool Square::isProtectedFromLeft(const Color playerColor) const {
    return isProtectedFromDirection(
        &Square::hasSquareLeft,
        &Square::getSquareLeft,
        &Piece::canProtectStraight,
        playerColor
    );
}

bool Square::isProtectedFromRight(const Color playerColor) const {
    return isProtectedFromDirection(
        &Square::hasSquareRight,
        &Square::getSquareRight,
        &Piece::canProtectStraight,
        playerColor
    );
}

bool Square::isProtectedByKnight(const Color playerColor) const {
    std::vector<Square *> knightSquares{};
    getSurroundingKnightSquares(knightSquares);

    return std::ranges::any_of(knightSquares, [](const Square* square) {
        return square->isOccupied() && square->getPiece()->getType() == Piece::Type::Knight;
    });
}

void Square::setPiece(Piece *piece) {
    _piece = piece;
}

Piece *Square::getPiece() const {
    return _piece;
}

uint8_t Square::getX() const {
    return _x;
}

uint8_t Square::getY() const {
    return _y;
}

bool Square::isOccupied() const {
    return _piece != nullptr;
}

bool Square::hasSquareAbove() const {
    return _y < _board->getHeight() - 1;
}

bool Square::hasSquareBelow() const {
    return _y > 0;
}

bool Square::hasSquareLeft() const {
    return _x > 0;
}

bool Square::hasSquareRight() const {
    return _x < _board->getWidth() - 1;
}

bool Square::hasSquareAboveLeft() const {
    return hasSquareLeft() && hasSquareAbove();
}

bool Square::hasSquareAboveRight() const {
    return hasSquareRight() && hasSquareAbove();
}

bool Square::hasSquareBelowLeft() const {
    return hasSquareLeft() && hasSquareBelow();
}

bool Square::hasSquareBelowRight() const {
    return hasSquareRight() && hasSquareBelow();
}

Square *Square::getSquareLeft() const {
    return _board->getSquare(_x - 1, _y);
}

Square *Square::getSquareRight() const {
    return _board->getSquare(_x + 1, _y);
}

Square *Square::getSquareAbove() const {
    return _board->getSquare(_x, _y - 1);
}

Square *Square::getSquareBelow() const {
    return _board->getSquare(_x, _y + 1);
}

Square *Square::getSquareAboveLeft() const {
    return _board->getSquare(_x - 1, _y - 1);
}

Square *Square::getSquareAboveRight() const {
    return _board->getSquare(_x + 1, _y - 1);
}

Square *Square::getSquareBelowLeft() const {
    return _board->getSquare(_x - 1, _y + 1);
}

Square *Square::getSquareBelowRight() const {
    return _board->getSquare(_x + 1, _y + 1);
}

void Square::getSurroundingKnightSquares(std::vector<Square *> & knightSquares) const {
    if (hasSquareLeft()) {
        const Square * currentSquare = getSquareLeft();
        if (currentSquare->hasSquareAboveLeft()) knightSquares.push_back(currentSquare->getSquareAboveLeft());
        if (currentSquare->hasSquareBelowLeft()) knightSquares.push_back(currentSquare->getSquareBelowLeft());
    }
    if (hasSquareRight()) {
        const Square * currentSquare = getSquareRight();
        if (currentSquare->hasSquareAboveRight()) knightSquares.push_back(currentSquare->getSquareAboveRight());
        if (currentSquare->hasSquareBelowRight()) knightSquares.push_back(currentSquare->getSquareBelowRight());
    }
    if (hasSquareAbove()) {
        const Square * currentSquare = getSquareAbove();
        if (currentSquare->hasSquareAboveLeft()) knightSquares.push_back(currentSquare->getSquareAboveLeft());
        if (currentSquare->hasSquareAboveRight()) knightSquares.push_back(currentSquare->getSquareAboveRight());
    }
    if (hasSquareBelow()) {
        const Square * currentSquare = getSquareBelow();
        if (currentSquare->hasSquareBelowLeft()) knightSquares.push_back(currentSquare->getSquareBelowLeft());
        if (currentSquare->hasSquareBelowRight()) knightSquares.push_back(currentSquare->getSquareBelowRight());
    }
}

std::ostream &operator<<(std::ostream &os, const Square & square) {
    return os << "Square(" << static_cast<int>(square._x) << ", " << static_cast<int>(square._y) << ")";
}

void Square::getNeighbors(std::vector<Square *> & neighbors) const {
    if (hasSquareAbove())  neighbors.push_back(getSquareAbove());
    if (hasSquareBelow())  neighbors.push_back(getSquareBelow());
    if (hasSquareLeft())  neighbors.push_back(getSquareLeft());
    if (hasSquareRight())  neighbors.push_back(getSquareRight());
    if (hasSquareAboveLeft())  neighbors.push_back(getSquareAboveLeft());
    if (hasSquareAboveRight())  neighbors.push_back(getSquareAboveRight());
    if (hasSquareBelowLeft())  neighbors.push_back(getSquareBelowLeft());
    if (hasSquareBelowRight())  neighbors.push_back(getSquareBelowRight());
}

bool Square::isProtected(const Color playerColor) const {
    if (isProtectedFromAboveRight(playerColor)) return true;
    if (isProtectedFromAboveLeft(playerColor)) return true;
    if (isProtectedFromBelowRight(playerColor)) return true;
    if (isProtectedFromBelowLeft(playerColor)) return true;

    if (isProtectedFromAbove(playerColor)) return true;
    if (isProtectedFromBelow(playerColor)) return true;
    if (isProtectedFromLeft(playerColor)) return true;
    if (isProtectedFromRight(playerColor)) return true;

    if (isProtectedByKnight(playerColor)) return true;

    return false;
}

bool Square::isOccupiedByPawnBishopQueenOrKing() const {
    if (!isOccupied()) return false;
    return (_piece->getType() == Piece::Type::Pawn ||
            _piece->getType() == Piece::Type::Bishop ||
            _piece->getType() == Piece::Type::Queen ||
            _piece->getType() == Piece::Type::King);
}

bool Square::isOccupiedByBishopOrQueen() const {
    if (!isOccupied()) return false;
    return (_piece->getType() == Piece::Type::Bishop ||
            _piece->getType() == Piece::Type::Queen);

}
