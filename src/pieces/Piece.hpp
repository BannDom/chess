//
// Created by dominik on 16.08.25.
//

#ifndef CHESS_PIECE_HPP
#define CHESS_PIECE_HPP

#include <vector>
#include <iostream>

#include "../moves/Move.hpp"

class Square;

enum class Color { White, Black };

class Piece {
public:
    enum class Type { Pawn, Knight, Bishop, Rook, Queen, King };

protected:
    Piece(Square* square, Type type, Color color);

    Square * _currentSquare;
    Type _type;
    Color _color;

    template <typename HasNeighbor, typename GetNeighbor>
    void getPossibleMovesInDirection(HasNeighbor hasNeighbor, GetNeighbor getNeighbor,
                                     Color playerColor, std::vector<Move> & possibleMoves) const;

    void getPossibleMovesInStraightDirections(std::vector<Move> & possibleMoves) const;
    void getPossibleMovesInDiagonalDirections(std::vector<Move> & possibleMoves) const;

public:
    virtual ~Piece() = default;
    virtual void getPossibleMoves(std::vector<Move> &possibleMoves) const = 0;

    [[nodiscard]]  Square * getCurrentSquare() const;
    [[nodiscard]] Type getType() const;
    [[nodiscard]] Color getColor() const;

    void setCurrentSquare(Square * square);

    [[nodiscard]] bool canProtectDiagonal(bool distanceIsOne) const;
    [[nodiscard]] bool canProtectStraight(bool distanceIsOne) const;

    friend std::ostream& operator<<(std::ostream& os, Type type);
    friend std::ostream& operator<<(std::ostream& os, Color color);
    friend std::ostream& operator<<(std::ostream& os, const Piece & p);
};

#include "Piece.ipp"

#endif //CHESS_PIECE_HPP
