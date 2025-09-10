//
// Created by dominik on 09.09.25.
//

#include "Piece.hpp"

Piece::Piece(Square *square, const Type type, const Color color) : _currentSquare(square), _type(type), _color(color) {
    if (square->isOccupied()) {
        throw std::runtime_error("Square is already occupied by another piece.");
    }

    square->setPiece(this);
}

void Piece::getPossibleMovesInStraightDirections(std::vector<Move> &possibleMoves) const {
    getPossibleMovesInDirection(&Square::hasSquareAbove, &Square::getSquareAbove, _color, possibleMoves);
    getPossibleMovesInDirection(&Square::hasSquareBelow, &Square::getSquareBelow, _color, possibleMoves);
    getPossibleMovesInDirection(&Square::hasSquareLeft, &Square::getSquareLeft, _color, possibleMoves);
    getPossibleMovesInDirection(&Square::hasSquareRight, &Square::getSquareRight, _color, possibleMoves);
}

void Piece::getPossibleMovesInDiagonalDirections(std::vector<Move> &possibleMoves) const {
    getPossibleMovesInDirection(&Square::hasSquareAboveLeft, &Square::getSquareAboveLeft, _color, possibleMoves);
    getPossibleMovesInDirection(&Square::hasSquareAboveRight, &Square::getSquareAboveRight, _color, possibleMoves);
    getPossibleMovesInDirection(&Square::hasSquareBelowLeft, &Square::getSquareBelowLeft, _color, possibleMoves);
    getPossibleMovesInDirection(&Square::hasSquareBelowRight, &Square::getSquareBelowRight, _color, possibleMoves);
}

Square * Piece::getCurrentSquare() const {
    return _currentSquare;
}

Piece::Type Piece::getType() const {
    return _type;
}

Color Piece::getColor() const {
    return _color;
}

void Piece::setCurrentSquare(Square *square) {
    if (square->isOccupied()) {
        throw std::runtime_error("Square is already occupied by another piece.");
    }

    _currentSquare = square;
    _currentSquare->setPiece(this);
}

bool Piece::canProtectDiagonal(const bool distanceIsOne) const {
    return  distanceIsOne && (_type == Type::Pawn || _type == Type::King) ||
        _type == Type::Bishop || _type == Type::Queen;
}

bool Piece::canProtectStraight(const bool distanceIsOne) const {
    return  distanceIsOne && _type == Type::King ||
        _type == Type::Rook || _type == Type::Queen;
}

std::ostream& operator<<(std::ostream& os, const Piece::Type type) {
    switch (type) {
        case Piece::Type::King: return os << "King";
        case Piece::Type::Queen:  return os << "Queen";
        case Piece::Type::Rook:   return os << "Rook";
        case Piece::Type::Bishop: return os << "Bishop";
        case Piece::Type::Knight: return os << "Knight";
        case Piece::Type::Pawn:   return os << "Pawn";
    }
    return os << "Unknown";
}

std::ostream& operator<<(std::ostream& os, const Color color) {
    switch (color) {
        case Color::White: return os << "White";
        case Color::Black: return os << "Black";
    }
    return os << "Unknown";
}

std::ostream & operator<<(std::ostream &os, const Piece &p) {
    return os << "Piece(type: " << p._type
              << ", color: " << p._color
              << ", currentSquare: " << p._currentSquare
              << ")";
}