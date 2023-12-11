// Auth: Christian A. Botos, John O'Neal, Willam Brickner
// Date: 12/07/2023
// Desc: Inline definition of the Inventory Class for the player's inventory. It is a member of the Character Class. Inventory should be limited by weight, but our menu is limited to 9 items.
#pragma once
#include "All_Includes.h"
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"
#include "Item.h"

class Inventory
{
private:
	// fields
	vector<Item*> items;
	int maxWeight;
	int maxItems; // JPO: Added to limit the number of items in the inventory to 9.
	int gold;
	string selectedCharacter;
	Armor* equippedArmor;
	Weapon* equippedWeapon;
	//Since we need linked pairs of Armor for their armorType so the player can equip more than one type of armor at a time.
	//This is what I found that would allow us to keep track of it just inside of Inventory instead of having to call whatever character they are playing.
	//It uses map which does require a header file but it seems to be the best way of storing these so that we could also easily save/load them later which is important.
	map<Armor::ArmorType, Armor*> equippedArmorSlots;

	static Inventory* instance; // Singleton instance

	// Private constructor so that only the singleton instance can be created
    Inventory(int maxWeight = 0, int maxItems = 9, int gold = 100, string selectedCharacter = "", Armor* equippedArmor = nullptr, Weapon* equippedWeapon = nullptr)
    : maxWeight(maxWeight), maxItems(maxItems), gold(gold), selectedCharacter(selectedCharacter), equippedArmor(equippedArmor), equippedWeapon(equippedWeapon) {
        setMaxWeight(selectedCharacter);
    }

public:
	static Inventory* getInstance() {
        if (instance == nullptr) {
            instance = new Inventory();
        }
        return instance;
    }

	// Destructor
	~Inventory() {
		for (Item* item : items) {
			delete item;
		}
	}

	// getters
	const vector<Item*>& getItems() const {
		return items;
	}

	Item* getItem(int index) const {
		if (index >= 0 && index < items.size()) {
			return items[index];
		}
		return nullptr;
	}

	int getSize() const {
		return items.size();
	}

	int getItemWeight(int index) const {
		if (index < 0 || index >= items.size()) {
			cout << "\nInvalid index. Cannot find item weight.\n";
			return -1; // Return -1 if the index is out of bounds
		}

		const Item* item = items[index];
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

		return itemWeight;
	}

	int getCurrentWeight() const {
		int totalWeight = 0;

		for (int i = 0; i < items.size(); i++) {
			int itemWeight = getItemWeight(i);
			if (itemWeight != -1) {
				totalWeight += itemWeight;
			}
		}
		return totalWeight;
	}

	int getMaxWeight() const {
		return maxWeight;
	}

	int getMaxItems() const {
		return maxItems;
	}

	int getGold() const {
		return gold;
	}

	string getSelectedCharacter() const {
		return selectedCharacter;
	}

	Armor* getEquippedArmorByType(Armor::ArmorType type) {
		return equippedArmorSlots[type];
	}

	const map<Armor::ArmorType, Armor*>& getEquippedArmorSlots() const {
		return equippedArmorSlots;
	}

	Weapon* getEquippedWeapon() const {
		return equippedWeapon;
	}

	int getEquippedWeaponDamage() const {
		if (equippedWeapon) {
			return equippedWeapon->damage;
		}
		else {
			// Return a default value or handle the case when no weapon is equipped
			return 2; // For example, returning 0 if no weapon is equipped
		}
	}

	int getTotalEquippedDefense() const {
		int totalDefense = 0;

		for (const auto& armorSlot : equippedArmorSlots) {
			Armor* armor = armorSlot.second;
			if (armor) {
				totalDefense += armor->defense;
			}
		}
		return totalDefense;
	}

	// setters
	void addItem(Item* item) {
		items.push_back(item);
	}

	void removeItem(int index) {
		items.erase(items.begin() + index);
	}

	void setMaxWeight(string& selectedCharacter) {
		if (selectedCharacter == "Ranger") {
			maxWeight = 225;
		}
		else if (selectedCharacter == "Rogue") {
			maxWeight = 300;
		}
		else if (selectedCharacter == "Wizard") {
			maxWeight = 200;
		}
		else {
			maxWeight = 500; // JPO: Default value for testing only.
		}
	}

	void setMaxItems(int value) {
		maxItems = value;
	}

	void setGold(int value) {
		gold = value;
	}

	void addGold(int g) {
		gold += g;
	}

	void deductGold(int g) {
		gold -= g;
	}

	void setEquippedArmorByType(Armor::ArmorType type, Armor* armor) {
		equippedArmorSlots[type] = armor;
	}

	void setEquippedWeapon(Weapon* weapon) {
		equippedWeapon = weapon;
	}

	// Other functions
	void displayCurrentInventory() const {
		cout << "Current Inventory:\n"
			<< "-------------------------------\n"
			<< "Gold: " << setw(10) << getGold() << "Weight: " << getCurrentWeight() << "/" << maxWeight << endl
			<< "-------------------------------\n";

		if (items.empty()) {
			cout << "Inventory is empty!\n\n";
			return; // JPO: Added to early exit the function.
		}

		for (size_t i = 0; i < items.size(); ++i) {
			cout << i + 1 << ") ";
			const Item* currentItem = items[i];

			if (const auto* weapon = dynamic_cast<const Weapon*>(currentItem)) {
				cout << weapon->name << " - " << weapon->material << " " << weaponTypeToString(weapon->type) << endl
					<< "      " << "Value: " << setw(2) << weapon->value << " Weight: " << setw(2) << weapon->weight << " Damage:  " << setw(2) << weapon->damage << endl << endl;
			}
			else if (const auto* armor = dynamic_cast<const Armor*>(currentItem)) {
				cout << armor->name << " - " << armor->material << " " << armorTypeToString(armor->type) << endl
					<< "      " << "Value: " << setw(2) << armor->value << " Weight: " << setw(2) << armor->weight << " Defense: " << setw(2) << armor->defense << endl << endl;
			}
			else if (const auto* potion = dynamic_cast<const Potion*>(currentItem)) {
				cout << potion->name << " " << potionTypeToString(potion->type) << " potion of " << potion->material << endl
					<< "      " << "Value: " << setw(2) << potion->value << " Weight: " << setw(2) << potion->weight << " Healing: " << setw(2) << potion->heal << endl << endl;
			}
		}
	}

	void equipItem() {
		 cout << "Equip what?";
		int index = getZeroBasedIntOrQuit();
		if (index == -1 || index < 0 || index >= items.size()) {
			cout << "\nInvalid index. Please try again\n";
			return;
		}
		Item* item = items[index];

		auto* armor = dynamic_cast<Armor*>(item);
		auto* weapon = dynamic_cast<Weapon*>(item);

		if (armor != nullptr) {
			if (equippedArmorSlots.find(armor->type) != equippedArmorSlots.end()) {
				// An armor of this type is already equipped, so unequip it first.
				auto* previousArmor = equippedArmorSlots[armor->type];
				cout << "\nUnequipped previous " << armorTypeToString(armor->type) << " armor: " << previousArmor->name;
			}
			// Armor slot for this type doesn't exist, so create one and equip the armor.
			equippedArmorSlots[armor->type] = armor;
			cout << "\nEquipped armor: " << armor->name << endl;
			return;
		}

		if (weapon != nullptr) {
			equippedWeapon = weapon;
			cout << "\nEquipped weapon: " << weapon->name << endl;
			return;
		}
		// Not a valid item to equip
		cout << "\nCannot equip a potion." << endl;
	}

	void discardItem() {
		if (items.empty()) {
			cout << "\nNothing to discard! Inventory is empty!\n\n";
			return;
		}
		cout << "Discard what?";
		int index = getZeroBasedIntOrQuit();
		if (index == -1 || index < 0 || index >= items.size()) {
			cout << "\nInvalid index. Please try again\n";
			return;
		}
		delete items[index]; // Free memory
		items.erase(items.begin() + index);
		cout << "\nItem discarded.\n";
	}

	void takePotion() {
		bool hasPotion = false;
		for (Item* item : items) {
			if (dynamic_cast<Potion*>(item) != nullptr) {
				hasPotion = true;
				break;
			}
		}
		if (!hasPotion) {
			cout << "You don't have any health potions.\n";
			return;
		}
		cout << "Take which potion?";
		int index = getZeroBasedIntOrQuit();
		if (index == -1 || index < 0 || index >= items.size()) {
			cout << "\nInvalid index. Please try again\n";
			return;
		}
		if (dynamic_cast<Potion*>(items[index]) != nullptr) {
			// Code to consume health potion goes here
		} else {
			cout << "\nThat item is not a health potion.\n";
		}
	}

	void openInventory() {
		system("cls");
		char choice;
		do {
			displayCurrentInventory();
			cout << "You may:\n"
				<< "1) Equip item.\n"
				<< "2) Discard item.\n"
				<< "3) Take health potion.\n"
				<< "ESC) Exit inventory.\n";
			choice = _getch();

			if (choice == 27) { // Escape key
				return; // Return to the shop.
			}

			switch (choice) {
				case '1':
					equipItem();
					break;
				case '2':
					discardItem();
					break;
				case '3':
					takePotion();
					break;
				default:
					cout << "Invalid choice. Please try again.\n";
					break;
			}
			system("pause");
			system("cls");
		} while (true);
	}
};

// Initialize the singleton instance to nullptr
Inventory* Inventory::instance = nullptr;