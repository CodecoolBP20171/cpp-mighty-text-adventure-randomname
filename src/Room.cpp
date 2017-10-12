//
// Created by meszi on 2017.10.10..
//

#include "../headers/Room.h"

Room::Room(Area &area) :
        toNorth(nullptr),
        toEast(nullptr),
        toSouth(nullptr),
        toWest(nullptr),
        areaType(&area) {

}

void Room::placeItem(Item newItem) {
    items.emplace_back(newItem);
}

void Room::printRoom() {
    cout << getDescription() << endl;
    if (!items.empty()) {
        string itemsString = "\nOn the ground, there is";
        for (Item item : items) {
            itemsString += " a(n) " + item.getName() + ",";
        }
        itemsString.replace(itemsString.rfind(','), 1, "");
        itemsString += ".";
        cout << itemsString << endl;
    }
    string movementOptions = "From this room, you can exit towards:";
    if (toNorth != nullptr) {
        movementOptions += " north,";
    }
    if (toEast != nullptr) {
        movementOptions += " east,";
    }
    if (toSouth != nullptr) {
        movementOptions += " south,";
    }
    if (toWest != nullptr) {
        movementOptions += " west";
    }
    if (movementOptions.back() == ',') {
        movementOptions.replace(movementOptions.rfind(','), 1, "");
    }
    movementOptions += ".";
    cout << movementOptions << endl;
}
