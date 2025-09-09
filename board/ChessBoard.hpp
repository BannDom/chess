//
// Created by dominik on 17.08.25.
//

#ifndef CHESS_CHESSBOARD_HPP
#define CHESS_CHESSBOARD_HPP

#include "Board.hpp"

class ChessBoard : public Board<8, 8> {
public:
    ChessBoard() : Board<8, 8>() {}
};


#endif //CHESS_CHESSBOARD_HPP
