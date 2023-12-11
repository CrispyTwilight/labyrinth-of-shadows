// Auth: John O'Neal
// Date: 12/04/2023
// Desc: The Shop class contains all code needed to build a shop. This will be accessed by the character entering an 'S' tile.
#pragma once
#include "All_Includes.h"

class Shop
{
private:
	// Fields
	static Shop* instance;
    static const int MAX_ITEMS = 3;
    static const int SIZE = 4;
	static const int MENU_SIZE = 5;
    vector<Item*> shopInventory;
    vector<Weapon*> weaponsInventory;
    vector<Armor*> armorsInventory;
    vector<Potion*> potionsInventory;
	int itemNumCounter;
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

    array<string, MENU_SIZE> menuOptions = {
        "1) Purchase an item.",
        "2) Sell an item.",
		"3) Inspect an item.",
		"4) See your inventory.",
        "ESC) Exit shop."
    };

    // Private constructor so that only one instance of Shop can exist.
    Shop() {
        initializeShopInformation();
        initializeInventory();
		itemNumCounter = 0;
    }

public:
	// Static access method. Call to create a shop instance if one does not exist.
    static Shop* getInstance() {
        if (instance == nullptr) {
            instance = new Shop();
        }
        return instance;
    }

	void displayFullShop() {
		system("cls");
		displayShopInformation();
		displayShopInventory();
		displayGoldAndMenu();
	}

	void runShop() {
		char input;
		do {
			displayFullShop();
			input = _getch();
			if (input == 27) { // Escape key
				return; // Return to the map.
			}
			int numInput = input - '0';
			switch (numInput) {
				case 1:
					handlePurchase();
					break;
				case 2:
					handleSale();
					break;
				case 3:
					inspectItem();
					break;
				case 4:
					Inventory::getInstance()->openInventory();
					break;
				default:
					cout << "Invalid input. Select a valid menu option.\n";
					system("pause");
					break;
			}
		} while (true); // There is a return statement in the switch statement, so this loop will never be infinite.
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
			cout << itemNumCounter + 1 << ") " << left << setw(55) << ss.str() << right << setw(4) << "$" << weaponsInventory[i]->value << endl;
			itemNumCounter++;
		}

		// Display armor
		for (int i = 0; i < armorsInventory.size(); i++) {
			stringstream ss;
			ss << armorsInventory[i]->name << " - " << armorsInventory[i]->material << " " << armorTypeToString(armorsInventory[i]->type);
			cout << itemNumCounter + 1 << ") " << left << setw(55) << ss.str() << right << setw(4) << "$" << armorsInventory[i]->value << endl;
			itemNumCounter++;
		}

		// Display potions
		for (int i = 0; i < potionsInventory.size(); i++) {
			stringstream ss;
			ss << potionsInventory[i]->name << " " << potionTypeToString(potionsInventory[i]->type) << " potion of " << potionsInventory[i]->material;
			cout << itemNumCounter + 1 << ") " << left << setw(55) << ss.str() << right << setw(4) << "$" << potionsInventory[i]->value << endl;
			itemNumCounter++;
		}

		// Reset the character counter.
		itemNumCounter = 0;
    }

	void displayGoldAndMenu() {
		// Display gold balance.
        cout << left << "\nGold Balance: " << Inventory::getInstance()->getGold() << endl;
		// Display the shop's menu options.
		cout << "\nYou may:\n";
		for (int i = 0; i < MENU_SIZE; i++) {
			cout << setw(35) << menuOptions[i] << endl;
		}
	}

	void handlePurchase() {
		cout << "Purchase what?";
		int index = getZeroBasedIntOrQuit();
		if (index == -1) {
			return; // Early return if 'ESC' was pressed
		}

		if (index < 0 || index >= shopInventory.size()) {
			cout << "\nInvalid item index. Please try again.\n";
			system("pause");
			return;
		}

		Item* item = shopInventory[index];

		if (Inventory::getInstance()->getGold() < item->value) {
			cout << "\nYou do not have enough gold!\n";
			system("pause");
			return;
		}

		int itemWeight = 0;
		if (const auto* weapon = dynamic_cast<const Weapon*>(item)) {
			itemWeight = weapon->weight;
		}
		else if (const auto* armor = dynamic_cast<const Armor*>(item)) {
			itemWeight = armor->weight;
		}
		else if (const auto* potion = dynamic_cast<const Potion*>(item)) {
			itemWeight = potion->weight;
		}

		if (Inventory::getInstance()->getCurrentWeight() + itemWeight > Inventory::getInstance()->getMaxWeight()) {
			cout << "\nYou do not have enough carrying capacity!\n";
			system("pause");
			return;
		}

		if (Inventory::getInstance()->getSize() >= Inventory::getInstance()->getMaxItems()) {
			cout << "\nYou do not have enough inventory space!\n";
			system("pause");
			return;
		}

		Inventory::getInstance()->deductGold(item->value);
		Inventory::getInstance()->addItem(item);
		removeAndReplaceFromInventories(item);
		cout << "\nPurchase successful! Item added to inventory.\n";
		system("pause");
	}

	void handleSale() {
		cout << "Sell what?";
		int index = getZeroBasedIntOrQuit();
		if (index == -1) {
			return; // Early return if 'ESC' was pressed
		}

		if (index < 0 || index >= Inventory::getInstance()->getSize()) {
			cout << "\nInvalid item index. Please try again.\n";
			system("pause");
			return;
		}

		Item* item = Inventory::getInstance()->getItem(index);

		Inventory::getInstance()->addGold(item->value / 2); // Intentional integer division
		cout << "\nSale successful! You made " << item->value/2 << " gold.\n"; // Intentional integer division
		shopInventory.push_back(item);
		Inventory::getInstance()->removeItem(index);
		system("pause");
	}

	// Search for the index (0-8) in shopInventory and replace it with the new item. The search for the index (0-2) in each inventory (weapon, armor, potion) and replace it with the new item.
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

			// Remove from shopInventory.
			shopInventory.erase(itemIterator);
			// Insert the new item at the same index in shopInventory.
			shopInventory.insert(shopInventory.begin() + index, newItem);
		}
	}

	// Module to inspect a given inventory item.
	void inspectItem() {
		cout << "Inspect what?";
		int index = getZeroBasedIntOrQuit();
		if (index == -1) {
			return;
		}
		if (index >= 0 && index < shopInventory.size()) {
			Item* item = shopInventory[index];
			if (item != nullptr) {
				if (auto* weapon = dynamic_cast<Weapon*>(item)) {
					cout << "\nName: " << weapon->name << endl
						<< "Type: " << weapon->type << endl
						<< "Material: " << weapon->material << endl
						<< "Damage: " << weapon->damage << endl
						<< "Weight: " << weapon->weight << endl
						<< "Value: " << weapon->value << endl;
				} else if (auto* armor = dynamic_cast<Armor*>(item)) {
					cout << "\nName: " << armor->name << endl
						<< "Type: " << armor->type << endl
						<< "Material: " << armor->material << endl
						<< "Defense: " << armor->defense << endl
						<< "Weight: " << armor->weight << endl
						<< "Value: " << armor->value << endl;
				} else if (auto* potion = dynamic_cast<Potion*>(item)) {
					cout << "\nName: " << potion->name << endl
						<< "Type: " << potion->type << endl
						<< "Material: " << potion->material << endl
						<< "Heal: " << potion->heal << endl
						<< "Weight: " << potion->weight << endl
						<< "Value: " << potion->value << endl;
				}
			} else {
				cout << "\nInvalid item. Please try again.\n";
			}
		}
		system("pause");
	}
};

// Initialize the static instance to nullptr.
Shop* Shop::instance = nullptr;