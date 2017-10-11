//
// Created by meszi on 2017.10.10..
//

#include "../headers/Player.h"

Player::Player() :
        // Magic numbers are arbitrary
        maxHealth(10),
        currentHealth(10),
        inventory(Inventory(10)) {

}

void Player::pickUpItem() {
    //
}

void Player::move(const InputType &direction) {
    switch (direction) {
        case GO_NORTH:
            if ((*currentRoom).getNorthernRoom() != nullptr) {
                currentRoom = (*currentRoom).getNorthernRoom();
            }
            return;
        case GO_EAST:
            if ((*currentRoom).getEasternRoom() != nullptr) {
                currentRoom = (*currentRoom).getEasternRoom();
            }
            return;
        case GO_SOUTH:
            if ((*currentRoom).getSouthernRoom() != nullptr) {
                currentRoom = (*currentRoom).getSouthernRoom();
            }
            return;
        case GO_WEST:
            if ((*currentRoom).getWesternRoom() != nullptr) {
                currentRoom = (*currentRoom).getWesternRoom();
            }
            return;
    }
}

void Player::setCurrentRoom(Room& room) {
    currentRoom = &room;
}
