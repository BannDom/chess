include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(chess_tests
        test_piece.cpp
)

target_link_libraries(chess_tests
        PRIVATE
        piece_lib
        moves_lib
        board_lib
        GTest::gtest_main
)