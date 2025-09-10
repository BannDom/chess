add_library(moves_lib
        Move.cpp
)

target_include_directories(moves_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
