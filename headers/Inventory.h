//
// Created by meszi on 2017.10.10..
//

#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_INVERNTORY_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_INVERNTORY_H

#include <iostream>
#include <vector>
#include "Item.h"

class Inventory {
public:
    Inventory(int capacity);
    void addItem(Item &newItem);
    void removeItem(int index); // Parameter is undecided
    vector<Item> getItems();
    bool isOverEncumbered();


private:
    const int capacity;
    int currentWeight;
    std::vector<Item> items;
};


#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_INVERNTORY_H
