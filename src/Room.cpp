//
// Created by meszi on 2017.10.10..
//

#include "../headers/Room.h"

Room::Room(int x, int y, Area &area,
           bool connNorth=true, bool connEast=true,
           bool connSouth=true, bool connWest=true) :
        x(x), y(y),
        toNorth(nullptr),
        toEast(nullptr),
        toSouth(nullptr),
        toWest(nullptr),
        areaType(&area),
        connNorth(connNorth),
        connEast(connEast),
        connsouth(connSouth),
        connWest(connWest) {

}

void Room::placeItem(Item newItem) {
    items.emplace_back(newItem);
}

void Room::clearItem(int index) {
    items.erase(items.begin()+index);
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

void Room::removeObseleteConnections(InputType direction) {
    if (direction == InputType::GO_NORTH) {
        toNorth = nullptr;
    }
    if (direction == InputType::GO_EAST) {
        toEast = nullptr;
    }
    if (direction == InputType::GO_SOUTH) {
        toSouth = nullptr;
    }
    if (direction == InputType::GO_WEST) {
        toWest = nullptr;
    }
}
