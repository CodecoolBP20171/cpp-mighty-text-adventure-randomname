cmake_minimum_required(VERSION 3.8)
project(cpp_2nd_tw_mighty_text_adventure)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp src/Area.hpp src/Game.cpp src/Game.h src/InputType.h src/Parser.cpp src/Parser.h)
add_executable(cpp_2nd_tw_mighty_text_adventure ${SOURCE_FILES})