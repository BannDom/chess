#ifndef CHESS_PIECE_IPP
#define CHESS_PIECE_IPP

#include "../boards/Square.hpp"
#include "../moves/Move.hpp"

template <typename HasNeighbor, typename GetNeighbor>
void Piece::getPossibleMovesInDirection(HasNeighbor hasNeighbor, GetNeighbor getNeighbor,
                                        const Color playerColor, std::vector<Move> & possibleMoves) const {
    Square * beginSquare = _currentSquare;
    Square * square = _currentSquare;

    while ((square->*hasNeighbor)()) {
        square = (square->*getNeighbor)();
        if (square->isOccupied()) {
            if (playerColor != square->getPiece()->getColor()) {
                possibleMoves.emplace_back(beginSquare, square);
                return;
            }
            return;
        }
    }
}

#endif //CHESS_PIECE_IPP