// Auth: Christian A. Botos
// Date: 12/07/2023
// Desc: header file for the Inventory class for the player's inventory
#pragma once
#include "All_Includes.h"
#include "Item.h"
#include <map>

class Inventory
{
private:
	// fields
	vector<Item*> items;

	//Since we need linked pairs of Armor for their armorType so the player can equip more than one type of armor at a time.
	//This is what I found that would allow us to keep track of it just inside of Inventory instead of having to call whatever character they are playing.
	//It uses map which does require a header file but it seems to be the best way of storing these so that we could also easily save/load them later which is important.
	map<Armor::ArmorType, Armor*> equippedArmorSlots;
	int healthPotion;
	int maxWeight;
	Armor* equippedArmor;
	Weapon* equippedWeapon;
	string selectedCharacter;
	int currentWeight;
	int gold;
	bool hasPotion;

public:
	// constructor
	Inventory(string& character, int& max)
	{
		selectedCharacter = character;
		maxWeight = max;
		gold = 100;
		hasPotion = false;
	}
	// getters
	int getItemWeight()
	{
		if (selectedCharacter == "Ranger")
		{
			maxWeight = 225;
		}
		else if (selectedCharacter == "Rogue")
		{
			maxWeight = 300;
		}
		else if (selectedCharacter == "Wizard")
		{
			maxWeight = 200;
		}
		else
		{
			maxWeight = 500;
		}
	}

	int getHealthPotion() const 
	{
		return healthPotion;
	}
	
	int	getCurrentWeight() const {
		

		for (const Item* item : items) 
		{
			//currentWeight += item->weight; Not done.
		}

		return currentWeight;
	}
		// getters
	int getGold() const {
		return gold;
	}

	const vector<Item*>& getItems() const {
		return items;
	}

	Armor* getEquippedArmorByType(Armor::ArmorType type) 
	{
		return equippedArmorSlots[type];
	}

	const map<Armor::ArmorType, Armor*>& getEquippedArmorSlots() const 
	{
		return equippedArmorSlots;
	}

	int getSize() const {
		return items.size();
	}

	Item* getItem(int index) const {
		if (index >= 0 && index < items.size()) {
			return items[index];
		}
		return nullptr;
	}


	Weapon* getEquippedWeapon() const 
	{
		return equippedWeapon;
	}

	void displayItemsInfo() const {
		for (size_t i = 0; i < items.size(); ++i) {
			cout << "Index: " << i + 1 << ", ";
			const Item* currentItem = items[i];

			if (const Weapon* weapon = dynamic_cast<const Weapon*>(currentItem)) {
				cout << "Name: " << weapon->name << ", Value: " << weapon->value << ", Damage: " << weapon->damage << endl;
			}
			else if (const Armor* armor = dynamic_cast<const Armor*>(currentItem)) {
				cout << "Name: " << armor->name << ", Value: " << armor->value << ", Defense: " << armor->defense << endl;
			}
			else {
				cout << "Name: " << currentItem->name << ", Value: " << currentItem->value << endl;
			}
		}
	}
		// setters
	void addItem(Item* item) {
			items.push_back(item);
	}

	

	void setEquippedArmorByType(Armor::ArmorType type, Armor* armor) 
	{
		equippedArmorSlots[type] = armor;
	}

	void setEquippedWeapon(Weapon* weapon) 
	{
		equippedWeapon = weapon;
	}
	
	void setGold(int value) 
	{
		gold = value;
	}

	void removeItem(int index) {
		items.erase(items.begin() + index);
	}

	void addGold(int g) 
	{
		gold += g;
	}

	void deductGold(int g) 
	{
		gold -= g;
	}
	
	// setters
	//These are for loading the game.
	void setHealthPotion(int &health)
	{
		healthPotion += health;
	}

	void equip(Item* item) 
	{
		Armor* armor = dynamic_cast<Armor*>(item);
		Weapon* weapon = dynamic_cast<Weapon*>(item);

		if (armor != nullptr) 
		{
			if (equippedArmorSlots.find(armor->type) == equippedArmorSlots.end()) 
			{
				// Armor slot for this type doesn't exist, so create one and equip the armor
				equippedArmorSlots[armor->type] = armor;
				cout << "Equipped armor: " << armor->name << endl;
			}
			else 
			{
				// An armor of this type is already equipped, unequip it first
				Armor* previousArmor = equippedArmorSlots[armor->type];
				cout << "Unequipped previous " << armorTypeToString(armor->type) << " armor: " << previousArmor->name << endl;
				equippedArmorSlots[armor->type] = armor;
				cout << "Equipped new " << armorTypeToString(armor->type) << " armor: " << armor->name << endl;
			}
		}
		else if (weapon != nullptr) {
			equippedWeapon = weapon;
			cout << "Equipped weapon: " << weapon->name << endl;
		}
		else {
			// Not a valid item to equip
			cout << "Cannot equip this item." << endl;
		}
	}
	

	//Other Functions

	void openInventory(Ranger playerRanger, Wizard playerWizard, Rogue playerRogue)
	{
		if (healthPotion > 0)
		{
			hasPotion = true;
		}
		int choice = -1;
		do {
			cout << "Inventory Menu:\n"
				<< "1. Equip Item\n"
				<< "2. Discard Item\n"
				<< "3. Take Health Potion\n"
				<< "4. Exit Inventory\n"
				<< "Enter your choice: ";

			 choice = _getch() - '0'; // Convert char input to integer
		

			switch (choice) {
			case 1:
				displayItemsInfo();
				cout << "Enter index of item to equip: ";
				int indexToEquip = _getch() - '0'; // Convert char input to integer
				indexToEquip -= 1; // Adjust index to start from 0

				if (indexToEquip >= 0 && indexToEquip < items.size()) {
					Item* itemToEquip = items[indexToEquip];
					equip(itemToEquip); // Equip the selected item
				}
				else {
					cout << "Invalid index.\n";
				}
				break;

			case 2:
				displayItemsInfo();
				cout << "Enter index of item to discard: ";
				int index = _getch() - '0'; // Convert char input to integer
				index -= 1; // Adjust index to start from 0

				if (index >= 0 && index < items.size()) {
					// Remove item from the inventory
					delete items[index]; // Free memory
					items.erase(items.begin() + index);
					cout << "Item discarded.\n";
				}
				else {
					cout << "Invalid index.\n";
				}
				break;

			case 3:

				if (hasPotion) {
					// Logic to consume a health potion
					if (selectedCharacter == "Ranger") 
					{
						playerRanger.takePotion();
					}
					if (selectedCharacter == "Wizard")
					{
						playerWizard.takePotion();
					}
					if (selectedCharacter == "Rogue")
					{
						playerRogue.takePotion();
					}
				}
				else {
					cout << "You don't have any health potions.\n";
				}

			case 4:
				cout << "Exiting Inventory.\n";
				break;

			default:
				cout << "Invalid choice.\n";
				break;
			}
		} while (choice != 4); 
	}
};

