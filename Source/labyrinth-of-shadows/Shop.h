// Auth: John O'Neal
// Date: 12/04/2023
// Desc: The Shop class contains all code needed to build a shop. This will be access by the character entering an 'S' tile.
#pragma once
#include "All_Includes.h"

class Shop
{
private:
	// Fields
	static Shop* instance;
    static const int MAX_ITEMS = 3;
    static const int SIZE = 4;
    vector<Item*> shopInventory;
    vector<Weapon*> weaponsInventory;
    vector<Armor*> armorsInventory;
    vector<Potion*> potionsInventory;
    Character character;
	int charCounter;
	string randShopName;
	string randShopOwner;
	string randOwnerAttribute;

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
        "q) Exit from building."
    };

    // Private constructor so that no objects can be created.
    Shop() {
        initializeShopInformation();
        initializeInventory();
		charCounter = 0;
    }

public:
	// I need to make logic for initializing the shop. The first time a player hits the 's' tile, the shop should be constructed using the initializeInventory and initializeShopInformation. Any time afterwards, the shop should retain the data it had before and should not be reinitialized.
	 // Static access method.

    static Shop* getInstance() {
        if (instance == nullptr) {
            instance = new Shop();
        }
        return instance;
    }

	void displayFullShop() {
		displayShopInformation();
		displayShopInventory();
		displayGoldAndMenu();
	}

	void runShop() {
		displayFullShop();
		char input;
		do {
			input = _getch();
			switch (input) {
				case 'p':
					handlePurchase();
					break;
				case 's':
					handleSale();
					break;
				case 'q':
					return; // Return to the map.
				default:
					cout << "Invalid input. Please try again" << endl;
					break;
			}
		} while (input != 'q');
	}

	void initializeShopInformation() {
		// Randomly select the shop name, owner, and attribute.
        Dice shopNameDie(SIZE - 1);
        randShopName = shopNames[shopNameDie.rollDice()];

        Dice shopOwnerDie(SIZE - 1);
        randShopOwner = shopOwners[shopOwnerDie.rollDice()];

        Dice shopAttributeDie(SIZE - 1);
        randOwnerAttribute = ownerAttributes[shopOwnerDie.rollDice()];
	}

	void displayShopInformation() const {
		// Display the shop's owner, name, and headings. Use endl to make character count easier.
		stringstream ss;
		ss << randShopOwner << " " << randOwnerAttribute;
		cout << right << setw(19 + 9) << ss.str() << setw(14 + 10) << randShopName << endl;
		cout << right << setw(4 + 3) << "Item" << setw(55 + 4) << "Asking Price" << endl;
	}

	void initializeInventory() {
		// Fill the shop's inventory with items.
		for (int i = 0; i < MAX_ITEMS; i++) {
			Weapon* weapon = new Weapon(true);
			weaponsInventory.push_back(weapon); // add to the weapons inventory
			shopInventory.push_back(weapon); // add to the shop's inventory
		}

		for (int i = 0; i < MAX_ITEMS; i++) {
			Armor* armor = new Armor(true);
			armorsInventory.push_back(armor);
			shopInventory.push_back(armor);
		}

		for (int i = 0; i < MAX_ITEMS; i++) {
			Potion* potion = new Potion(true);
			potionsInventory.push_back(potion);
			shopInventory.push_back(potion);
        }
    }

    void displayShopInventory() {
		// Display weapons
		for (int i = 0; i < weaponsInventory.size(); i++) {
			stringstream ss;
			ss << weaponsInventory[i]->name << " - " << weaponsInventory[i]->material << " " << weaponTypeToString(weaponsInventory[i]->type);
			cout << char('a' + charCounter) << ") " << left << setw(55) << ss.str() << right << setw(4) << "$" << weaponsInventory[i]->value << endl;
			charCounter++;
		}

		// Display armor
		for (int i = 0; i < armorsInventory.size(); i++) {
			stringstream ss;
			ss << armorsInventory[i]->name << " - " << armorsInventory[i]->material << " " << armorTypeToString(armorsInventory[i]->type);
			cout << char('a' + charCounter) << ") " << left << setw(55) << ss.str() << right << setw(4) << "$" << armorsInventory[i]->value << endl;
			charCounter++;
		}

		// Display potions
		for (int i = 0; i < potionsInventory.size(); i++) {
			stringstream ss;
			ss << potionsInventory[i]->name << " " << potionTypeToString(potionsInventory[i]->type) << " potion of " << potionsInventory[i]->material;
			cout << char('a' + charCounter) << ") " << left << setw(55) << ss.str() << right << setw(4) << "$" << potionsInventory[i]->value << endl;
			charCounter++;
		}

		// Reset the character counter.
		charCounter = 0;
    }

	void displayGoldAndMenu() {
		// Display gold balance.
        cout << left << "\nGold Balance: " << character.getInventory().getGold() << endl;
		// Display the shop's menu options.
		cout << "\nYou may:\n";
		for (int i = 0; i < SIZE; i++) {
			cout << setw(35) << menuOptions[i] << endl;
		}
	}

	// Convert the character input to an integer index or -1 if 'q' is pressed.
	int getItemIndexFromInput() const {
		char input = _getch();
		if (input == 'q') {
			return -1;
		}
		int index = input - 'a';
		return index;
	}

	void handlePurchase() {
		cout << "Purchase what?";
		int index = getItemIndexFromInput();
		if (index == -1) {
			return; // Early return if 'q' was pressed
		}
		if (index >= 0 && index < shopInventory.size()) {
			Item* item = shopInventory[index];
			if (character.getInventory().getGold() >= item->value) {
				character.getInventory().deductGold(item->value);
				character.getInventory().addItem(item);
				removeAndReplaceFromInventories(item);
				cout << "\nPurchase successful!\n";
			} else {
				cout << "\nYou do not have enough gold!\n";
			}
			system("pause");
			system("cls");
			displayFullShop();
		} else {
			cout << "\nInvalid item index. Please try again.\n" << endl;
		}
	}

	void handleSale() {
		cout << "Sell what?";
		int index = getItemIndexFromInput();
		if (index == -1) {
			return;
    	}
		if (index >= 0 && index < character.getInventory().getSize()) {
			shopInventory.push_back(character.getInventory().getItem(index));
			character.getInventory().removeItem(index);
			cout << "\nSale successful!\n";
			system("pause");
			system("cls");
			displayFullShop();
		} else {
			cout << "\nInvalid item index. Please try again.\n" << endl;
		}
	}

	// JPO: This is in progress.
	// Seach for the index (0-8) in shopInventory and replace it with the new item. The search for the index (0-2) in each inventory (weapon, armor, potion) and replace it with the new item.
	void removeAndReplaceFromInventories(Item* item) {
		// Find the index of the item in shopInventory
		auto itemIterator = find(shopInventory.begin(), shopInventory.end(), item);
		if (itemIterator != shopInventory.end()) {
			int index = distance(shopInventory.begin(), itemIterator);

			// Create a new item
			Item* newItem = nullptr;
			if (Weapon* weapon = dynamic_cast<Weapon*>(item)) {
				newItem = new Weapon(true);
				// Calculate the index for weaponsInventory
				auto weaponIterator = find(weaponsInventory.begin(), weaponsInventory.end(), weapon);
				if (weaponIterator != weaponsInventory.end()) {
					int weaponIndex = distance(weaponsInventory.begin(), weaponIterator);
					// Remove from weaponsInventory and insert the new item
					weaponsInventory.erase(weaponsInventory.begin() + weaponIndex);
					weaponsInventory.insert(weaponsInventory.begin() + weaponIndex, dynamic_cast<Weapon*>(newItem));
				}
			}

			else if (Armor* armor = dynamic_cast<Armor*>(item)) {
				newItem = new Armor(true);
				auto armorIterator = find(armorsInventory.begin(), armorsInventory.end(), armor);
				if (armorIterator != armorsInventory.end()) {
					int armorIndex = distance(armorsInventory.begin(), armorIterator);
					armorsInventory.erase(armorsInventory.begin() + armorIndex);
					armorsInventory.insert(armorsInventory.begin() + armorIndex, dynamic_cast<Armor*>(newItem));
				}
			}

			else if (Potion* potion = dynamic_cast<Potion*>(item)) {
				newItem = new Potion(true);
				auto potionIterator = find(potionsInventory.begin(), potionsInventory.end(), potion);
				if (potionIterator != potionsInventory.end()) {
					int potionIndex = distance(potionsInventory.begin(), potionIterator);
					potionsInventory.erase(potionsInventory.begin() + potionIndex);
					potionsInventory.insert(potionsInventory.begin() + potionIndex, dynamic_cast<Potion*>(newItem));
				}
			}

			else {
				cout << "Error: Invalid item type.\n";
			}

			// Remove from shopInventory
			shopInventory.erase(itemIterator);
			// Insert the new item at the same index in shopInventory
			shopInventory.insert(shopInventory.begin() + index, newItem);
		}
	}

	// void inventoryList() {
	// 	cout << "Inventory list.\n";
	// }

	// void exitShop() {
	// 	cout << "You are exiting the shop...\n";
	// 	// save the shop's inventory
	// 	// call a display map function
	// }
};