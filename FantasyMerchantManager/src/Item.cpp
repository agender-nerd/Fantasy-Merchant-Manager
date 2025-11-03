#include "fmm/Item.h"
#include <iostream>

Item::Item(const std::string& name, int value, const std::string& desc)
    : m_name(name), m_value(value), m_desc(desc) {}

/* Running Item::displayDetails() should look something like this:
    Trinket (Generic Item)
    Value: 10 gp
    Description: A whimsical thingamajig. 
*/
void Item::displayDetails() const {
    std::cout << m_name << " (Generic Item)" << std::endl;
    std::cout << "Value: " << m_value << " gp" << std::endl;
    std::cout << "Description: " << m_desc << std::endl;
} 