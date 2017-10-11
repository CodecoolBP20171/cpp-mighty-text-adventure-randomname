//
// Created by meszi on 2017.10.10..
//

#include "../headers/Item.h"

Item::Item(ItemName &name, ItemDescription &desc, ItemWeight &weight) :
        name(&name),
        description(&desc),
        weight(&weight){

}
