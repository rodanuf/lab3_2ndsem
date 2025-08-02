cmake_minimum_required(VERSION 3.10)
project(lab3_2ndsem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(gtest_force_shared_crt ON CACHE BOOL "Use shared CRT for GoogleTest" FORCE)

file(GLOB HEADERS "headers/*.hpp")
file(GLOB TEMPLATES "templates/*.tpp")
file(GLOB UI_HEADERS "ui_headers/*.hpp")
file(GLOB UI_SOURCES "ui_sources/*.cpp") 
file(GLOB TYPES_HEADERS "types_headers/*.hpp")
file(GLOB TYPES_SOURCES "types_sources/*.cpp")
file(GLOB MONAD_HEADER "monad_header/*.hpp")

option(BUILD_GMOCK "Build gmock" OFF)
add_subdirectory(googletest EXCLUDE_FROM_ALL)

add_executable(lab3_2ndsem
    ui_sources/lab.cpp
    ${UI_SOURCES}
    ${TYPES_SOURCES}
    ${TEMPLATES}
)

add_executable(tests 
    tests/main_tests.cpp 
    ${TYPES_SOURCES}
    ui_sources/io_functions.cpp
)

target_include_directories(tests PRIVATE 
    ${CMAKE_SOURCE_DIR}/headers
    ${CMAKE_SOURCE_DIR}/googletest/googletest/include
    ${CMAKE_SOURCE_DIR}/tests
    ${CMAKE_SOURCE_DIR}/types_headers
    ${CMAKE_SOURCE_DIR}/ui_headers
    ${CMAKE_SOURCE_DIR}/monad_header
)

target_include_directories(lab3_2ndsem PRIVATE
    ${CMAKE_SOURCE_DIR}/headers
    ${CMAKE_SOURCE_DIR}/types_headers
    ${CMAKE_SOURCE_DIR}/ui_headers
)

target_link_libraries(tests PRIVATE gtest gtest_main)

enable_testing()
add_test(NAME AllTests COMMAND tests)