//
// Created by meszi on 2017.10.10..
//

#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_PLAYER_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_PLAYER_H

#include "Inventory.h"
#include "Room.h"

class Player {
public:
    Player(Room &startingRoom);

    void pickUpItem(Item &newItem);

    Item dropItem(); // Parameter undecided

    void changeHealth(int value) { currentHealth += value; }

    bool isAlive() { return currentHealth > 0; }
private:
    int currentHealth;
    const int maxHealth;
    Inventory inventory;
    Room *currentRoom;

};


#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_PLAYER_H
