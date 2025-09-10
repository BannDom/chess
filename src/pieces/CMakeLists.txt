add_library(piece_lib
        Bishop.cpp
        King.cpp
        Knight.cpp
        Pawn.cpp
        Piece.cpp
        Queen.cpp
        Rook.cpp
)

target_include_directories(piece_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
