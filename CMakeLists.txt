cmake_minimum_required(VERSION 3.14)
project(GameMathLib LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Header-only library
add_library(GameMathLib INTERFACE)
target_include_directories(GameMathLib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Example
add_executable(example_basic examples/example_basic.cpp)
target_link_libraries(example_basic PRIVATE GameMathLib)

# ------------------------
# GoogleTest via FetchContent
# ------------------------
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)
# For MSVC: avoid overriding parent settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(gamemath_tests
    tests/test_math.cpp
)

target_link_libraries(gamemath_tests
    PRIVATE
        GameMathLib
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(gamemath_tests)

