add_library(board_lib
        ChessBoard.cpp
        Square.cpp
)

target_include_directories(board_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
