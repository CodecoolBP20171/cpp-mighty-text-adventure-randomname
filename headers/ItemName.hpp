//
// Created by meszi on 2017.10.11..
//

#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ITEMNAME_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ITEMNAME_H

#include <string>

using namespace std;

class ItemName {
public:
    ItemName(const string& name) : name(name) {}

    string getName() { return name; }

private:
    string name;
};

#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ITEMNAME_H
