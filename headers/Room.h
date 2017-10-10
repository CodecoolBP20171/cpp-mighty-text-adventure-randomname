//
// Created by meszi on 2017.10.10..
//

#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ROOM_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ROOM_H

#include <iostream>
#include <string>
#include <vector>
#include "Area.hpp"
#include "Item.h"

using namespace std;

class Room {
public:
    Room(Area &area);

    string getDescription() { return (*areaType).getDescription();}

    void printRoom();

    void placeItem(Item newItem);

    Item pickUpItem(); // Parameter is undecided

private:
    const Room *toNorth;
    const Room *toEast;
    const Room *toSouth;
    const Room *toWest;
    const Area *areaType;
    vector<Item> items;

};


#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ROOM_H
