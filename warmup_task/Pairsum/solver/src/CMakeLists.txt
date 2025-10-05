cmake_minimum_required(VERSION 3.10)

project(EqualSumPairs
    VERSION 1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(main main.cpp io.cpp)

# include direcotry for json.hpp
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS main
    RUNTIME DESTINATION bin
)
