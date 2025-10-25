cmake_minimum_required(VERSION 4.1)

project(TestLib)

add_executable(TestLib src/main.cpp)

target_link_directories(TestLib PRIVATE ${CMAKE_SOURCE_DIR}/../staticLibrary/build/)
target_link_libraries(TestLib libstaticLibrary.a)
