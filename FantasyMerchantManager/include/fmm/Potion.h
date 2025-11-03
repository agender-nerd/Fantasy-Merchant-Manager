#ifndef FMM_POTION_H
#define FMM_POTION_H

#include "fmm/Item.h"
#include <string>

class Potion : public Item {
public:
    Potion(const std::string& name, int value, const std::string& desc, const std::string& effect);
    void displayDetails() const override;
    const std::string& getEffect() const { return m_effect; }

private:
    std::string m_effect;
};

#endif