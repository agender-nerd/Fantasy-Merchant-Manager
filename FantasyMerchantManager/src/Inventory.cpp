#include "fmm/Inventory.h"
#include <iostream>

Inventory::Inventory() {}

void Inventory::listAllItems() const {
    for(int i = 0; i < items.size(); i++) {
        std::cout << i << ": " << items[i]->getName() << std::endl;
    }
}

bool Inventory::removeItem(int index) {
    if (index >= 0 && index < items.size()) {
        items.erase(items.begin() + index);
        return true;
    }
    return false;
}