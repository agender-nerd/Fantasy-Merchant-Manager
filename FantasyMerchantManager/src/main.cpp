#include "fmm/Inventory.h"
#include "fmm/Item.h"
#include "fmm/Weapon.h"
#include "fmm/Armor.h"
#include "fmm/Potion.h"

#include <iostream>
#include <memory>
#include <vector>
#include <limits>

// Helper functions
void itemCreation();
void itemRemoval();
void itemList();

Inventory merchantInv;

int main() {
    int userInput;

    do {
        std::cout << "Welcome to the Fantasy Merchant Manager program! What would you like to do?" << std::endl;
        std::cout << "1: Add Item" << 
        std::endl << "2: Remove Item" << 
        std::endl << "3: List Items" << 
        std::endl << "4: Exit" << std::endl;
        std::cin >> userInput;

        if (userInput < 1 || userInput > 4) {
            std::cout << "Invalid input. Please try again.";
        }
    } while (userInput < 1 || userInput > 4);

    switch (userInput) {
        case 1:
            itemCreation();
            break;
        case 2:
            itemRemoval();
            break;
        case 3:
            itemList();
            break;
        case 4:
            std::cout << "Bye!" << std::endl;
            return 1;
    }

    return 0;
}

void itemCreation() {
    int userInput2;
    std::string name;
    int value;
    std::string desc;

    do {
        std::cout << "What kind of item would you like to add?" <<
        std::endl << "1: Generic" <<
        std::endl << "2: Weapon" <<
        std::endl << "3: Armor" <<
        std::endl << "4: Potion" <<
        std::endl;

        std::cin >> userInput2;

        if (userInput2 < 1 || userInput2 > 4) {
            std::cout << "Invalid input. Please try again.";
        }
    } while (userInput2 < 1 || userInput2 > 4);

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter the name of the item." << std::endl;
    std::getline(std::cin, name);

    std::cout << "Enter the value of the item (in gp)." << std::endl;
    std::cin >> value;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Write a short description of the item." << std::endl;
    std::getline(std::cin, desc);

    switch (userInput2) {
        case 1: {
            auto newItem = std::make_shared<Item>(name, value, desc);
            merchantInv.addItem(newItem);
            std::cout << "Item successfully added!" << std::endl;
            break;}
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
    }
}

void itemRemoval() {
    std::string userInput2;
}

void itemList() {
    std::string userInput2;
}

