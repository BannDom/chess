//
// Created by dominik on 17.08.25.
//

#ifndef CHESS_KING_HPP
#define CHESS_KING_HPP

#include "Piece.hpp"

class King final : public Piece {
public:
    /**
     * Constructs a King piece on the given square with the specified color and checks before if the square is occupied.
     * @param square the square where the King will be placed
     * @param color the color of the King piece (White or Black)
     * @throws std::runtime_error if the square is already occupied by another piece
     */
    King(Square * square, Color color) ;

    /**
     * Calculates all possible moves for the King piece and stores them in the provided vector.
     * The King can move one square in any direction (horizontally, vertically, or diagonally).
     * If the target square is occupied by a piece of the same color or if it is out of bounds,
     * the move is not added. If the target square is occupied by a piece of the opposite color,
     * the move is only added, if the piece is not protected by any other piece.
     * @param possibleMoves a vector to store the possible moves
     */
    void getPossibleMoves(std::vector<Move> &possibleMoves) const override;
};


#endif //CHESS_KING_HPP
