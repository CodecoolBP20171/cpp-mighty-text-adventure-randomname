//
// Created by meszi on 2017.10.10..
//

#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ROOM_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ROOM_H

#include <iostream>
#include <string>
#include <vector>
#include "../hpp/Area.hpp"
#include "Item.h"

using namespace std;

class Room {
public:
    Room(Area &area);

    string getDescription() { return (*areaType).getDescription();}

    void printRoom();

    void placeItem(Item newItem);

    void clearItem(int index);

    vector<Item> getItems() { return items; }

    void setNorthernRoom(Room& room) { toNorth = &room; }
    void setEasternRoom(Room& room) { toEast = &room; }
    void setSouthernRoom(Room& room) { toSouth = &room; }
    void setWesternRoom(Room& room) { toWest = &room; }

    Room* getNorthernRoom() { return toNorth; }
    Room* getEasternRoom() { return toEast; }
    Room* getSouthernRoom() { return toSouth; }
    Room* getWesternRoom() { return toWest; }

private:
    Room *toNorth;
    Room *toEast;
    Room *toSouth;
    Room *toWest;
    const Area *areaType;
    vector<Item> items;

};


#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ROOM_H
