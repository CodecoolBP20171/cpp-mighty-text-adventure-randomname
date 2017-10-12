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
        connSouth(connSouth),
        connWest(connWest) {

}

void Room::placeItem(Item newItem) {
    items.emplace_back(newItem);
}

void Room::clearItem(int index) {
    items.erase(items.begin()+index);
}

void Room::printRoom() {
    cout << endl << getDescription() << endl;
    if (!items.empty()) {
        string itemsString = "On the ground, there is";
        for (Item item : items) {
            itemsString += " a(n) " + item.getName() + ",";
        }
        itemsString.replace(itemsString.rfind(','), 1, "");
        itemsString += ".";
        cout << itemsString << endl;
    }
    string movementOptions = "From here, you can exit towards:";
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

void Room::removeObseleteConnections() {
    if (!connNorth) {
        toNorth = nullptr;
    }
    if (!connEast) {
        toEast = nullptr;
    }
    if (!connSouth) {
        toSouth = nullptr;
    }
    if (!connWest) {
        toWest = nullptr;
    }
}
