#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_GAME_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_GAME_H

#include <vector>
#include "../hpp/Area.hpp"
#include "Parser.h"
#include "Room.h"
#include "Player.h"
#include "Inventory.h"
#include "../hpp/ItemName.hpp"
#include "../hpp/ItemWeight.hpp"

using namespace std;

class Game {
public:
    Game(): player(Player()) {}
    void init();
    void run();
private:

    vector<Area> areas; // areas has only non-changeable information
    vector<ItemName> itemNames;
    vector<ItemWeight> itemWeights;
    vector<Room> rooms;
    Room *firstRoom;
    Room *lastRoom;
    Room *deathRoom;
    Player player;
    bool isGameWon = false;

    void loadAreas();
    void loadItemNames();
    void loadItemWeights();
    void loadRooms();
    bool step();
    void handleInput(string& input);
    void connectRooms();
    void printWinMessage();
    void printLoseMessage();
    void removeObseleteConnections();
    void placeInitialItems();
};


#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_GAME_H
