//
// Created by meszi on 2017.10.10..
//

#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ITEM_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ITEM_H

#include <string>

class Item {
public:
    Item(std::string name, std::string description, int weight);
    std::string getName() { return name; }
    std::string getDescription() { return description; }
    int getWeight() { return weight; }

private:
    const std::string name;
    const std::string description;
    const int weight;
};


#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ITEM_H
