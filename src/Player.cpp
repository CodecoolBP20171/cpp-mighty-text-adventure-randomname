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

void Player::move(InputType &direction) {
    switch (direction) {
        case GO_NORTH:
            currentRoom = (*currentRoom).getNorthernRoom();
            return;
        case GO_EAST:
            currentRoom = (*currentRoom).getEasternRoom();
            return;
        case GO_SOUTH:
            currentRoom = (*currentRoom).getSouthernRoom();
            return;
        case GO_WEST:
            currentRoom = (*currentRoom).getWesternRoom();
            return;
    }
}
