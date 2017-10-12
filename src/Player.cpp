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

void Player::pickUpItems() {
    vector<Item> newItems = currentRoom->getItems();
    currentRoom->clearItems();
    for (Item item : newItems) {
        inventory.addItem(item);
    }
    inventory.printOutWeigth();
}

void Player::dropItem() {
    cout << "What do you want to drop?" << endl;
    vector<Item> items = inventory.getItems();
    int itemsNumber = items.size();
    for (int i = 0; i < itemsNumber ; ++i) {
        cout << i+1 << ". " << items[i].getName() << "\n\tWeight: " << items[i].getWeight() << endl;
    }
    cout << "Type the index of an item you wat to drop." << endl;
    int itemToDropIndex;
    cin >> itemToDropIndex;
    if (cin.fail() || itemToDropIndex < 1 || itemToDropIndex > itemsNumber) {
        cout << "Incorrect input" << endl;
        cin.clear();
        cin.ignore(255, '\n');
    } else {
        Item itemToDrop = items[itemToDropIndex-1];
        currentRoom->placeItem(itemToDrop);
        inventory.removeItem(itemToDropIndex-1);
        cin.clear();
        cin.ignore(255, '\n');
    }
    inventory.printOutWeigth();
}

void Player::move(const InputType &direction) {
    if (inventory.isOverEncumbered()) {
        return;
    }
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
