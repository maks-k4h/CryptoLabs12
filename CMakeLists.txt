cmake_minimum_required(VERSION 3.6)

project(cryptolab LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)

message(STATUS "GTest include dirs: ${GTEST_INCLUDE_DIRS}")
message(STATUS "GTest libraries: ${GTEST_LIBRARIES}")


enable_testing()
add_executable(
    cryptolab
    lab1.cpp  # comment out to run test
    src/operations.cpp
    src/myrand.cpp
    src/prime.cpp
    src/format.cpp
    tests/ut_operations.cpp
    tests/ut_prime.cpp
)

target_link_libraries(
    cryptolab
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(cryptolab)

