cmake_minimum_required(VERSION 3.14)
project(GameMathLib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Header-only library
add_library(GameMathLib INTERFACE)
target_include_directories(GameMathLib INTERFACE include)

# Examples
add_executable(example_basic examples/example_basic.cpp)
target_link_libraries(example_basic GameMathLib)

# Tests (simple assert-based for speed)
enable_testing()
add_executable(run_tests tests/test_all.cpp)
target_link_libraries(run_tests GameMathLib)
add_test(NAME AllTests COMMAND run_tests)
