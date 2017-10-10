//
// Created by meszi on 2017.10.10..
//

#include "../headers/Player.h"

Player::Player(Room &startingRoom) :
        // Magic numbers are arbitrary
        maxHealth(10),
        currentHealth(10),
        inventory(100),
        currentRoom(&startingRoom) {

}

void Player::pickUpItem(Item &newItem) {
    inventory.addItem(newItem);
}
