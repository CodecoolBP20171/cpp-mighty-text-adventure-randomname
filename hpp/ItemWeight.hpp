//
// Created by meszi on 2017.10.11..
//

#ifndef CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ITEMWEIGHT_H
#define CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ITEMWEIGHT_H

class ItemWeight {
public:
    ItemWeight(const int& weight) : weight(weight) {}

    int getWeight() const { return weight; }

private:
    int weight;
};

#endif //CPP_2ND_TW_MIGHTY_TEXT_ADVENTURE_ITEMWEIGHT_H
