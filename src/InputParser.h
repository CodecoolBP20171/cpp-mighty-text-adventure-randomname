//
// Created by meszi on 2017.10.10..
//

#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_INPUTPARSER_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_INPUTPARSER_H

#include <string>
#include "InputType.h"


class InputParser {
public:
    InputParser();
    InputType parseInput(std::string input);

private:
    std::string lowercase(std::string input);
};


#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_INPUTPARSER_H
