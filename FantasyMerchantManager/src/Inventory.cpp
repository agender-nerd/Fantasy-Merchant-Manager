#include "fmm/Inventory.h"
#include <iostream>

Inventory::Inventory() {}

void Inventory::listAllItems() const {
    for(int i = 0; i < m_items.size(); i++) {
        std::cout << i << ": " << m_items[i]->getName() << std::endl;
    }
}

bool Inventory::removeItem(int index) {
    if (index >= 0 && index < m_items.size()) {
        m_items.erase(m_items.begin() + index);
        return true;
    }
    return false;
}