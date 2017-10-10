//
// Created by meszi on 2017.10.10..
//

#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_PARSER_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_PARSER_H


#include <iostream>
#include "InputType.h"

using namespace std;

class Parser {
public:
    static InputType parseInput(string &input);

private:
    static string toLowercase(string &input);
};


#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_PARSER_H
