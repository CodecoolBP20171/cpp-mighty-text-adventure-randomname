//
// Created by meszi on 2017.10.10..
//

#include "InputParser.h"

InputParser::InputParser() {}

InputType InputParser::parseInput(std::string input) {
    input = lowercase(input);
    if(input == "n" || input == "north") {
        return GO_NORTH;
    } else if(input == "e" || input == "east") {
        return GO_EAST;
    } else if(input == "s" || input == "south") {
        return GO_SOUTH;
    } else if(input == "w" || input == "west") {
        return GO_WEST;
    } else if(input == "h" || input == "help") {
        return HELP;
    }
    return INVALID;
}

std::string InputParser::lowercase(std::string input) {
    for(char character : input) {
        character = tolower(character);
    }
    return input;
}

