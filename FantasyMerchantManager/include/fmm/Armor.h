#ifndef FMM_ARMOR_H
#define FMM_ARMOR_H

#include "fmm/Item.h"
#include <string>

enum class ArmorType {
    Cloth,
    Leather,
    Padded,
    Chainmail,
    Plate
};

class Armor : public Item {
public:
    Armor(const std::string& name, int value, const std::string& desc,
    ArmorType type, bool magic);

    void displayDetails() const override;

    ArmorType getType() const { return m_type; }
    bool isMagic() const { return m_magic; }

private:
    ArmorType m_type;
    bool m_magic;
};

#endif