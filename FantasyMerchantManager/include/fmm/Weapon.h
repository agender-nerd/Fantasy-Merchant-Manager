#ifndef FMM_WEAPON_H
#define FMM_WEAPON_H

#include "fmm/Item.h"
#include <string>

enum class WeaponType {
    Sword,
    Dagger,
    Bow,
    Crossbow,
    Mace,
    Hammer,
    Spear
};

enum class MaterialType {
    Wood,
    Stone,
    Copper,
    Iron,
    Steel,
    Exotic
};

class Weapon : public Item {
public:
    Weapon(const std::string& name, int value, const std::string& desc, 
    WeaponType type, MaterialType material, bool magic);

    void displayDetails() const override;

    WeaponType getType() const { return m_type; }
    MaterialType getMaterial() const { return m_material; }
    bool isMagic() const { return m_magic; }

private:
    WeaponType m_type;
    MaterialType m_material;
    bool m_magic;
};

#endif