// Auth: John O'Neal
// Date: 12/04/2023
// Desc: shop class driver function.
#pragma once
#include "All_Includes.h"

class Shop {
private:
    static const int MAX_ITEMS = 3;
	static const int SIZE = 4;
    vector<Weapon> weapons;
	vector<Armor> armor;
	//vector<Potion> potions;
    int goldBalance;
	int charCounter = 0;

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
    Shop() : goldBalance(0) {
        for (int i = 0; i < MAX_ITEMS; i++) {
            weapons.push_back(Weapon(true));
        }
    }

    void printShopItems() {
        // Randomly select the shop name, owner, attribute, and race
        Dice shopNameDie(shopNames.size());
        string randShopName = shopNames[shopNameDie.rollDice()];

        Dice shopOwnerDie(shopOwners.size());
        string randShopOwner = shopOwners[shopOwnerDie.rollDice()];

        Dice shopAttributeDie(ownerAttributes.size());
        string randOwnerAttribute = ownerAttributes[shopOwnerDie.rollDice()];

        // Display the shop's owner, name, and headings. Use endl to make character count easier.
        cout << right << setw(16 + 8) << randShopOwner << " " << randOwnerAttribute << setw(7 + 4) << randShopName << endl;
        cout << right << setw(4 + 3) << "Item" << setw(58) << "Asking Price" << endl;

        for (int i = 0; i < MAX_ITEMS; i++) {
            cout << char('a' + charCounter) << ") " << left << setw(55) << weapons[i].name << right << setw(4) << "$" << weapons[i].value << endl;
			charCounter++;
        }

		for (int i = 0; i < MAX_ITEMS; i++) {
			cout << char('a' + charCounter) << ") " << left << setw(55) << armor[i].name << right << setw(4) << "$" << armor[i].value << endl;
			charCounter++;
		}

		//for (int i = 0; i < MAX_ITEMS; i++) {
		//	cout << char('a' + i) << ") " << left << setw(55) << potions[i].name << right << setw(4) << "$" << potions[i].value << endl;
		//  charCounter++;
		//}

        // Display gold left.
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
				// purchaseItem(input - 'a', player);
				break;
			}
			case 's': {
				cout << "Sell what?";
				input = _getch();
				// sellItem(input - 'a', player);
				break;
			}
			// Add more cases as needed
			default: {
				cout << "Invalid input." << endl;
				break;
			}
		}
	}

	// When the player selects a menu option, the item needs to be copied to the player's inventory. Then the item needs to be removed from the shop's inventory. A new item should be created to take the place of the removed on. The letters should stay the same. The gold balance needs to be updated.
	//void purchaseItem(int itemIndex, Player& player) {
	//	// Check if the player has enough gold
	//	if (player.getGold() < weapons[itemIndex].value) {
	//		cout << "You don't have enough gold to purchase this item." << endl;
	//		return;
	//	}

	//	// Add the item to the player's inventory
	//	player.addItem(weapons[itemIndex]);

	//	// Deduct the cost of the item from the player's gold
	//	player.deductGold(weapons[itemIndex].value);

	//	// Remove the item from the shop's inventory
	//	weapons.erase(weapons.begin() + itemIndex);

	//	// Add a new item to the shop's inventory at the same index
	//	weapons.insert(weapons.begin() + itemIndex, Weapon(true));

	//	cout << "You have purchased the item." << endl;
	//}

	void sellItem() {
		cout << "You have sold an item.\n";
		goldBalance += weapons[0].value;
		printShopItems();
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