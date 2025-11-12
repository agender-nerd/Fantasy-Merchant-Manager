#ifndef FMM_INVENTORY_H
#define FMM_INVENTORY_H

#include "fmm/Item.h"
#include <vector>
#include <memory>
#include <nlohmann/json.hpp>

using ItemPointer = std::shared_ptr<Item>;
using json = nlohman::json;


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