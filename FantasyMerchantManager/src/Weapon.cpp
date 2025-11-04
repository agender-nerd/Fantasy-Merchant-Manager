#include "fmm/Weapon.h"
#include <iostream>

// Helper functions for displayDetails()
std::string typeToString(WeaponType type) {
    switch (type) {
        case WeaponType::Sword: return "sword";
        case WeaponType::Dagger: return "dagger";
        case WeaponType::Bow: return "bow";
        case WeaponType::Crossbow: return "crossbow";
        case WeaponType::Mace: return "mace";
        case WeaponType::Hammer: return "hammer";
        case WeaponType::Spear: return "spear";
        default: return "weapon";
    }
}

std::string materialToString(MaterialType material) {
    switch (material) {
        case MaterialType::Wood: return "Wood";
        case MaterialType::Stone: return "Stone";
        case MaterialType::Copper: return "Copper";
        case MaterialType::Iron: return "Iron";
        case MaterialType::Steel: return "Steel";
        case MaterialType::Exotic: return "Exotic";
        default: return "Unknown";
    }
}

Weapon::Weapon(const std::string& name, int value, const std::string& desc, 
    WeaponType type, MaterialType material, bool magic)
    : Item(name, value, desc),
    m_type(type), m_material(material), m_magic(magic) {}

/* Running Weapon::displayDetails() should look something like this:
    Firebrand (Steel sword, magic)
    Value: 150 gp
    Description: A blade that glows red-hot. 
*/
void Weapon::displayDetails() const {
    std::cout << m_name << " (" << materialToString(m_material) << " " << typeToString(m_type);
    if (m_magic) {
        std::cout << ", magic";
    }
    std::cout << ")" << std::endl;
    std::cout << "Value: " << m_value << " gp" << std::endl;
    std::cout << "Description: " << m_desc << std::endl;
}