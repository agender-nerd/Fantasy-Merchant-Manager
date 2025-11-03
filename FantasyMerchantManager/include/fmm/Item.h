#ifndef FMM_ITEM_H
#define FMM_ITEM_H

#include <string>

class Item {
public:
    Item(const std::string& name, int value, const std::string& desc);   // Constructor
    virtual ~Item() = default;   // Destructor
    
    virtual void displayDetails() const;
    const std::string& getName() const { return m_name; }
    int getValue() const { return m_value; }

protected:
    std::string m_name;
    int m_value;
    std::string m_desc;
};

#endif