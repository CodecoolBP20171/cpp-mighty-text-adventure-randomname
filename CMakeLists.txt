cmake_minimum_required(VERSION 3.8)
project(cpp_2nd_tw_mighty_text_adventure)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp headers/Area.hpp src/Game.cpp headers/Game.h headers/InputType.h src/Parser.cpp headers/Parser.h src/Player.cpp headers/Player.h src/Inventory.cpp headers/Inventory.h src/Item.cpp headers/Item.h src/Room.cpp headers/Room.h)
add_executable(cpp_2nd_tw_mighty_text_adventure ${SOURCE_FILES})