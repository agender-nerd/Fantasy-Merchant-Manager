#include "fmm/Armor.h"
#include <iostream>

// Helper function for Armor::displayDetails()
std::string typeToString(ArmorType type) {
    switch (type) {
        case ArmorType::Cloth: return "Cloth";
        case ArmorType::Leather: return "Leather";
        case ArmorType::Padded: return "Padded";
        case ArmorType::Chainmail: return "Chainmail";
        case ArmorType::Plate: return "Plate";
        default: return "Unknown";
    }
}

Armor::Armor(const std::string& name, int value, const std::string& desc,
    ArmorType type, bool magic)
    : Item(name, value, desc),
    m_type(type), m_magic(magic) {}

/* Running Armor::displayDetails() should look something like this:
    Shimmering Breastplate (Plate armor, magic)
    Value: 300 gp
    Description: A cuirass made of shiny dragon scales. 
*/
void Armor::displayDetails() const {
    std::cout << m_name << " (" << typeToString(m_type) << " armor";
    if (m_magic) {
        std::cout << ", magic";
    }
    std::cout << ")" << std::endl;
    std::cout << "Value: " << m_value << " gp" << std::endl;
    std::cout << "Description: " << m_desc << std::endl;
}
