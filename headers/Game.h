#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_GAME_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_GAME_H

#include <vector>
#include "../src/Area.hpp"
#include "Parser.h"

using namespace std;

class Game {
public:
    void init();
    void run();

private:
    vector<Area> areas; // areas has only non-changeable information

    void loadAreas();
    bool step();
    void handleInput(string& input);
};


#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_GAME_H
