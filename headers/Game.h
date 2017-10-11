#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_GAME_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_GAME_H

#include <vector>
#include "Area.hpp"
#include "Parser.h"
#include "Room.h"
#include "Player.h"

using namespace std;

class Game {
public:
    Game(): player(Player()) {}
    void init();
    void run();

private:
    vector<Area> areas; // areas has only non-changeable information
    vector<Room> rooms;
    Room *firstRoom;
    Room *lastRoom;
    Player player;

    void loadAreas();
    void loadRooms();
    bool step();
    void handleInput(string& input);
};


#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_GAME_H
