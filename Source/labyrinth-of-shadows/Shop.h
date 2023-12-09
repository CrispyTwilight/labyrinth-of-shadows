// Auth: John O'Neal
// Date: 12/04/2023
// Desc: The Shop class contains all code needed to build a shop. This will be access by the character entering an 'S' tile.
#pragma once
#include "All_Includes.h"

class Shop
{
private:
	// Fields
    static const int MAX_ITEMS = 3;
	static const int SIZE = 4;
    vector<Weapon> weapons;
	vector<Armor> armor;
	vector<Potion> potions;
    int goldBalance;
	int charCounter;
	Character character;

	array<string, SIZE> shopNames = {
		"General Shop",
		"Armorer",
		"Weapon Smith",
		"Alchemist Shop",
    };

    array<string, SIZE> shopOwners = {
        "Edney",
        "Alberich",
        "Ulric",
        "Tobias",
    };

    array<string, SIZE> ownerAttributes = {
        "the Honest",
        "the Greedy",
        "the Good",
        "the Blind"
    };

    array<string, SIZE> menuOptions = {
        "p) Purchase an item.",
        "s) Sell an item.",
		"i) Inventory Lists.",
        "ESC) Exit from building."
    };

public:
	// Constructor
    Shop() {
		// Fill the shop's inventory with items.
        for (int i = 0; i < MAX_ITEMS; i++) {
            weapons.push_back(Weapon(true));
        }
		for (int i = 0; i < MAX_ITEMS; i++) {
			armor.push_back(Armor(true));
		}
		for (int i = 0; i < MAX_ITEMS; i++) {
			potions.push_back(Potion(true));
		}
		goldBalance = 0; // This needs the get the current gold balance from the character.
		charCounter = 0; // Default value for the character counter.
    }

    void displayShopItems() {
        // Randomly select the shop name, owner, and attribute.
        Dice shopNameDie(shopNames.size());
        string randShopName = shopNames[shopNameDie.rollDice()];

        Dice shopOwnerDie(shopOwners.size());
        string randShopOwner = shopOwners[shopOwnerDie.rollDice()];

        Dice shopAttributeDie(ownerAttributes.size());
        string randOwnerAttribute = ownerAttributes[shopOwnerDie.rollDice()];

        // Display the shop's owner, name, and headings. Use endl to make character count easier.
        cout << right << setw(16 + 8) << randShopOwner << " " << randOwnerAttribute << setw(7 + 4) << randShopName << endl;
        cout << right << setw(4 + 3) << "Item" << setw(58) << "Asking Price" << endl;

		// Display weapons, armor, and potions.
        for (int i = 0; i < MAX_ITEMS; i++) {
            cout << char('a' + charCounter) << ") " << left << setw(55) << weapons[i].name << right << setw(4) << "$" << weapons[i].value << endl;
			charCounter++;
        }

		for (int i = 0; i < MAX_ITEMS; i++) {
			cout << char('a' + charCounter) << ") " << left << setw(55) << armor[i].name << right << setw(4) << "$" << armor[i].value << endl;
			charCounter++;
		}

		for (int i = 0; i < MAX_ITEMS; i++) {
			cout << char('a' + i) << ") " << left << setw(55) << potions[i].name << right << setw(4) << "$" << potions[i].value << endl;
			charCounter++;
		}

        // Display gold balance.
        cout << left << "\nGold Balance: " << goldBalance << endl;

        // Display the shop's menu options.
        cout << "\nYou may:\n";
        for (int i = 0; i < SIZE; i++) {
            cout << setw(35) << menuOptions[i] << endl;
        }

		menuChoice();
    }

	void menuChoice() {
		char input = _getch();
		switch (input) {
			case 'p': {
				cout << "Purchase what?";
				input = _getch();
				purchaseItem(input - 'a', character);
				break;
			}
			case 's': {
				cout << "Sell what?";
				input = _getch();
				sellItem(input - 'a', character);
				break;
			}
			// Add more cases as needed
			default: {
				cout << "Invalid input." << endl;
				break;
			}
		}
	}

	void purchaseItem(int itemIndex, Character& character) {
		// Check if the character has enough gold to purchase weapon
		if (character.getInventory().getGold() < weapons[itemIndex].value) {
			cout << "You don't have enough gold to purchase this item." << endl;
			return;
		}

		// Add the weapon to the character's inventory
		character.getInventory().addItem(weapons[itemIndex]);
		character.getInventory().deductGold(weapons[itemIndex].value);
		weapons.erase(weapons.begin() + itemIndex);
		weapons.insert(weapons.begin() + itemIndex, Weapon(true));

		// Check if the character has enough gold to purchase armor
		if (character.getInventory().getGold() < armor[itemIndex].value) {
			cout << "You don't have enough gold to purchase this item." << endl;
			return;
		}

		// Add the armor to the character's inventory
		character.getInventory().addItem(armor[itemIndex]);
		character.getInventory().deductGold(armor[itemIndex].value);
		armor.erase(armor.begin() + itemIndex);
		armor.insert(armor.begin() + itemIndex, Armor(true));

		// Check if the character has enough gold to purchase potion
		if (character.getInventory().getGold() < potions[itemIndex].value) {
			cout << "You don't have enough gold to purchase this item." << endl;
			return;
		}

		// Add the potion to the character's inventory
		character.getInventory().addItem(potions[itemIndex]);
		character.getInventory().deductGold(potions[itemIndex].value);
		potions.erase(potions.begin() + itemIndex);
		potions.insert(potions.begin() + itemIndex, Potion(true));

		cout << "You have purchased the item." << endl;
	}

	void sellItem() {
		// This does not add the item to the shop's inventory. It simply removes the item from the character's inventory and adds the gold value to the characters gold balance.
		cout << "You have sold an item.\n";
		character.GoldBalance += weapons[0].value;
		goldBalance += weapons[0].value;
		displayShopItems();
	}

	void inventoryList() {
		cout << "Inventory list.\n";
	}

	void exitShop() {
		cout << "You are exiting the shop...\n";
		// save the shop's inventory
		// call a display map function
	}
};