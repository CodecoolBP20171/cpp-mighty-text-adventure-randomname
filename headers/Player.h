//
// Created by meszi on 2017.10.10..
//

#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_PLAYER_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_PLAYER_H

#include "Inventory.h"
#include "Room.h"
#include "InputType.h"

class Player {
public:
    Player();

    void pickUpItem(Item &newItem);

    Item dropItem(); // Parameter undecided

    void changeHealth(int value) { currentHealth += value; }

    bool isAlive() { return currentHealth > 0; }

    void move(const InputType &direction);

    void setCurrentRoom(Room& room);

    Room getCurrentRoom() { return *currentRoom; }
private:
    int currentHealth;
    const int maxHealth;
    Inventory inventory;
    Room *currentRoom;

};


#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_PLAYER_H
