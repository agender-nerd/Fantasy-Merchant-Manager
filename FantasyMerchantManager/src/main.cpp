#include "fmm/Inventory.h"
#include "fmm/Item.h"
#include "fmm/Weapon.h"
#include "fmm/Armor.h"
#include "fmm/Potion.h"

#include <iostream>
#include <memory>
#include <vector>
#include <limits>
#include <iomanip>

// Helper functions
void itemCreation();
void itemRemoval();
void itemList();

Inventory merchantInv;

int main() {
    int userInput;

    std::cout << "Welcome to the Fantasy Merchant Manager program! What would you like to do?" << std::endl;

    while (true) {
        do {
            std::cout << "1: Add Item" << 
            std::endl << "2: Remove Items" << 
            std::endl << "3: List Items" << 
            std::endl << "4: Exit" << std::endl;
            std::cin >> userInput;

            if (userInput < 1 || userInput > 4) {
                std::cout << "Invalid input. Please try again.";
            }
        } while (userInput < 1 || userInput > 4);

        std::cout << std::setfill('-') << std::setw(50) << "" << std::endl;

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
                return 0;
        }
    }
}

void itemCreation() {
    int userInput;
    std::string name;
    int value;
    std::string desc;

    std::cout << "ADDING ITEM TO INVENTORY" << std::endl;

    do {
        std::cout << "What kind of item would you like to add?" <<
        std::endl << "1: Generic" <<
        std::endl << "2: Weapon" <<
        std::endl << "3: Armor" <<
        std::endl << "4: Potion" <<
        std::endl;

        std::cin >> userInput;

        if (userInput < 1 || userInput > 4) {
            std::cout << "Invalid input. Please try again.";
        }
    } while (userInput < 1 || userInput > 4);

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter the name of the item." << std::endl;
    std::getline(std::cin, name);

    std::cout << "Enter the value of the item (in gp)." << std::endl;
    std::cin >> value;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Write a short description of the item." << std::endl;
    std::getline(std::cin, desc);

    switch (userInput) {
        case 1: {
            auto newItem = std::make_shared<Item>(name, value, desc);
            merchantInv.addItem(newItem);
            break;}

        case 2: {
            int type;
            int material;
            int magic;

            std::cout << "What type of weapon is it?\n0: Sword\n1: Dagger\n2: Bow\n3: Crossbow\n4: Mace\n5: Hammer\n6: Spear" << std::endl;
            std::cin >> type;
            std::cout << "What is your weapon made of?\n0: Wood\n1: Stone\n2: Copper\n3: Iron\n4: Steel\n5: Exotic" << std::endl;
            std::cin >> material;
            std::cout << "Is it magic?\n0: No\n1: Yes" << std::endl;
            std::cin >> magic;
            auto newItem = std::make_shared<Weapon>(name, value, desc, static_cast<WeaponType>(type), static_cast<MaterialType>(material), magic);
            merchantInv.addItem(newItem);
            break;}

        case 3: {
            int type;
            int magic;

            std::cout << "What type of armor is it?\n0: Cloth\n1: Leather\n2: Padded\n3: Chainmail\n4: Plate" << std::endl;
            std::cin >> type;
            std::cout << "Is it magic?\n0: No\n1: Yes" << std::endl;
            std::cin >> magic;
            auto newItem = std::make_shared<Armor>(name, value, desc, static_cast<ArmorType>(type), magic);
            merchantInv.addItem(newItem);
            break;}

        case 4: {
            std::string effect;

            std::cout << "What is the potion's effect?" << std::endl;
            std::cin >> effect;
            auto newItem = std::make_shared<Potion>(name, value, desc, effect);
            merchantInv.addItem(newItem);
            break;}
    }

    std::cout << "Item successfully added!" << std::endl;
    std::cout << std::setfill('-') << std::setw(50) << "" << std::endl;
}

void itemRemoval() {
    std::cout << "REMOVING ITEM FROM INVENTORY" << std::endl;
    std::cout << "Please enter the ID for the item you want to remove. (-1 to exit)" << std::endl;
    std::cout << "Tip: If you don't know what items you have, go back and look at your list!" << std::endl;

    int userInput;


    while (true) {
        std::cin >> userInput;

        if (userInput == -1) {
            break;
        }

        if (merchantInv.removeItem(userInput)) {
            std::cout << "Item successfully removed." << std::endl;
        } else {
            std::cout << "Oops! That's not a valid item ID." << std::endl;
        }
    }
    std::cout << "Returning to menu..." << std::endl;
    std::cout << std::setfill('-') << std::setw(50) << "" << std::endl;
}

void itemList() {
    std::cout << "LIST OF ITEMS IN INVENTORY" << std::endl;
    int userInput;
    merchantInv.listAllItems();
    std::cout << "Select an item # to see details. (-1 to exit)" << std::endl;

    while (true) {
        std::cin >> userInput;
        if (userInput == -1) {
            break;
        }
        std::cout << "Item #" << userInput << ": ";
        merchantInv.items[userInput]->displayDetails();
    }
    std::cout << "Returning to menu..." << std::endl;
    std::cout << std::setfill('-') << std::setw(50) << "" << std::endl;
}

