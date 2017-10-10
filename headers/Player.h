//
// Created by meszi on 2017.10.10..
//

#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_PLAYER_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_PLAYER_H

#include "Inventory.h"

class Player {
public:
    Player();
private:
    int currentHealth;
    int maxHealth;
    Inventory inventory;

};


#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_PLAYER_H
