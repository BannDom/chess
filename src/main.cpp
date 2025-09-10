#include <iostream>
#include "boards/ChessBoard.hpp"
#include "pieces/King.hpp"
#include "moves/Move.hpp"

int main() {
    try {
        const ChessBoard board{};
        const King king(board.getSquare(1,2), Color::White);
        std::vector<Move> possibleMoves{};
        king.getPossibleMoves(possibleMoves);

        for (const auto & move : possibleMoves) {
            std::cout << move << std::endl;
        }
    } catch (std::runtime_error &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (std::out_of_range &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}