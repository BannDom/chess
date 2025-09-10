add_subdirectory(pieces)
add_subdirectory(boards)
add_subdirectory(moves)

add_executable(chess main.cpp)
target_link_libraries(chess PRIVATE piece_lib board_lib moves_lib)
