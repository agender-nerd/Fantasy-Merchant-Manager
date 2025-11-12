#ifndef FMM_INVENTORY_H
#define FMM_INVENTORY_H

#include "fmm/Item.h"
#include <vector>
#include <memory>

using ItemPointer = std::shared_ptr<Item>;

class Inventory {
public:
    Inventory();

    void listAllItems() const;
    bool removeItem(int index);

    void addItem(const ItemPointer& item) { items.push_back(item); }
    const ItemPointer& getItem(int index) const { return items.at(index); }

    std::vector<ItemPointer> items;
};

#endif