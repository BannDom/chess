//
// Created by dominik on 16.08.25.
//

#ifndef CHESS_SQUARE_HPP
#define CHESS_SQUARE_HPP

#include <cinttypes>
#include <ostream>
#include <vector>

#include "../pieces/Piece.hpp"

class IBoard;
class Piece;
enum class Color;

class Square {
    friend class IBoard;

    size_t _x, _y {0};
    Piece * _piece {nullptr};
    IBoard * const _board;

    Square(size_t x, size_t y, IBoard * board);

    /**
     * Higher order function to check if a piece can be protected from one of the eight directions
     *
     * @tparam HasNeighbor function (Square *) -> bool
     * @tparam GetNeighbor function (Square *) -> Square *
     * @tparam CanProtect function (Square *, bool, Piece::Color) -> bool
     * @param hasNeighbor function which checks if the current square has a neighbor in the given direction
     * @param getNeighbor function which returns the neighboring square in the given direction
     * @param canProtect function which checks when the square is occupied if the pice can protect from the given direction
     * @param playerColor color of the player
     * @return if the piece can be protected from the given direction
     */
    template <typename HasNeighbor, typename GetNeighbor, typename CanProtect>
    [[nodiscard]] bool isProtectedFromDirection(HasNeighbor hasNeighbor, GetNeighbor getNeighbor,
                                                const CanProtect& canProtect, Color playerColor) const;

    [[nodiscard]] bool isProtectedFromBelowRight(Color playerColor) const;
    [[nodiscard]] bool isProtectedFromAboveRight(Color playerColor) const;
    [[nodiscard]] bool isProtectedFromBelowLeft(Color playerColor) const;
    [[nodiscard]] bool isProtectedFromAboveLeft(Color playerColor) const;

    [[nodiscard]] bool isProtectedFromBelow(Color playerColor) const;
    [[nodiscard]] bool isProtectedFromAbove(Color playerColor) const;
    [[nodiscard]] bool isProtectedFromLeft(Color playerColor) const;
    [[nodiscard]] bool isProtectedFromRight(Color playerColor) const;

    [[nodiscard]] bool isProtectedByKnight(Color playerColor) const;

public:
    Square() = delete;
    Square(const Square & other) = delete;
    Square(Square && other) noexcept = delete;
    Square & operator=(const Square & other) = delete;
    Square & operator=(Square && other) noexcept = delete;

    void setPiece(Piece * piece) ;

    [[nodiscard]] Piece * getPiece() const;
    [[nodiscard]] uint8_t getX() const;
    [[nodiscard]] uint8_t getY() const;

    [[nodiscard]] bool isOccupied() const;
    [[nodiscard]] bool isOccupiedByBishopOrQueen() const;
    [[nodiscard]] bool isOccupiedByPawnBishopQueenOrKing() const;

    [[nodiscard]] bool hasSquareAbove() const;
    [[nodiscard]] bool hasSquareBelow() const;
    [[nodiscard]] bool hasSquareLeft() const;
    [[nodiscard]] bool hasSquareRight() const;

    [[nodiscard]] bool hasSquareAboveLeft() const;
    [[nodiscard]] bool hasSquareAboveRight() const;
    [[nodiscard]] bool hasSquareBelowLeft() const;
    [[nodiscard]] bool hasSquareBelowRight() const;

    [[nodiscard]] Square * getSquareAbove() const;
    [[nodiscard]] Square * getSquareBelow() const;
    [[nodiscard]] Square * getSquareLeft() const;
    [[nodiscard]] Square * getSquareRight() const;

    [[nodiscard]] Square * getSquareAboveLeft() const;
    [[nodiscard]] Square * getSquareAboveRight() const;
    [[nodiscard]] Square * getSquareBelowLeft() const;
    [[nodiscard]] Square * getSquareBelowRight() const;

    void getSurroundingKnightSquares(std::vector<Square *> & knightSquares) const;
    void getNeighbors(std::vector<Square*> & neighbors) const;

    [[nodiscard]] bool isProtected(Color playerColor) const;

    friend std::ostream& operator<<(std::ostream& os, const Square & square) ;
};

template<typename HasNeighbor, typename GetNeighbor, typename CanProtect>
bool Square::isProtectedFromDirection(HasNeighbor hasNeighbor, GetNeighbor getNeighbor, const CanProtect &canProtect,
                                      const Color playerColor) const {
    auto square = this;
    bool distanceIsOne = true;

    while ((square->*hasNeighbor)()) {
        square = (square->*getNeighbor)();
        if (square->isOccupied() && playerColor == square->getPiece()->getColor()) {
            return (square->getPiece()->*canProtect)(distanceIsOne);
        }
        distanceIsOne = false;
    }
    return false;
}

#endif //CHESS_SQUARE_HPP
