//
// Created by meszi on 2017.10.11..
//

#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ITEMDESCRIPTION_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ITEMDESCRIPTION_H

#include <string>

using namespace std;

class ItemDescription {
public:
    ItemDescription(const string& desc) : desc(desc) {}

    string getDescription() const { return desc; }

private:
    string desc;
};

#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ITEMDESCRIPTION_H
