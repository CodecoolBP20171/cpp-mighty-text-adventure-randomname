//
// Created by meszi on 2017.10.10..
//

#include "../headers/Inventory.h"

Inventory::Inventory(int capacity):
        capacity(capacity),
        currentWeight(0) {

}

void Inventory::addItem(Item &newItem) {
    items.emplace_back(newItem);
    currentWeight += newItem.getWeight();
    if (currentWeight > capacity) {
        std::cout << "You are over encumbered and can't move.\nDrop some item to continue!\n";
        std::cout << "Current weight: " << currentWeight << "/" << capacity << std::endl;
    }
}

bool Inventory::isOverEncumbered() {
    return currentWeight > capacity;
}

vector<Item> Inventory::getItems() {
    return items;
}

void Inventory::removeItem(int index) {
    currentWeight -= items[index].getWeight();
    items.erase(items.begin()+index);
}
