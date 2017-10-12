//
// Created by meszi on 2017.10.10..
//

#include "../headers/Parser.h"

InputType Parser::parseInput(string &input) {
    input = toLowercase(input);
    if      (input == "h" || input == "help")   return HELP;
    else if (input == "n" || input == "north")  return GO_NORTH;
    else if (input == "e" || input == "east")   return GO_EAST;
    else if (input == "s" || input == "south")  return GO_SOUTH;
    else if (input == "w" || input == "west")   return GO_WEST;
    else if (input == "p" || input == "pick")   return PICK_UP_ITEM;
    else if (input == "d" || input == "drop")   return DROP_ITEM;
    else if (input == "l" || input == "list")   return LIST_ITEMS;
    return INVALID;
}

string Parser::toLowercase(string &input) {
    int i = 0;
    while(input[i]) {
        input[i] = tolower(input[i]);
        ++i;
    }
    return input;
}
