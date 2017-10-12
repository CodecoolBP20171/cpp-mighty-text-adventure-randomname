//
// Created by meszi on 2017.10.10..
//

#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ITEM_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ITEM_H

#include <string>
#include "../hpp/ItemName.hpp"
#include "../hpp/ItemWeight.hpp"

using namespace std;

class Item {
public:
    Item(ItemName &name, ItemWeight &weight);
    const string getName() { return name->getName(); }
    const int getWeight() { return weight->getWeight(); }

private:
    const ItemName *name;
    const ItemWeight *weight;
};


#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ITEM_H
