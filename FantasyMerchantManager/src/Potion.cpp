#include "fmm/Potion.h"
#include <iostream>

Potion::Potion(const std::string& name, int value, const std::string& desc, const std::string& effect)
    : Item(name, value, desc),
      m_effect(effect) {}

/* Running Potion::displayDetails() should look something like this:
    Small Red Vial (Potion)
    Value: 25 gp
    Effect: Heals minor wounds.
    Description: A mysterious red liquid. 
*/
void Potion::displayDetails() const {
    std::cout << m_name << " (Potion)" << std::endl;
    std::cout << "Value: " << m_value << " gp" << std::endl;
    std::cout << "Potion Effect: " << m_effect << std::endl;
    std::cout << "Description: " << m_desc << std::endl;
}