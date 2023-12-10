// Auth: Christian A. Botos
// Date: 12/07/2023
// Desc: header file for the Inventory class for the player's inventory
#pragma once
#include "All_Includes.h"
#include "Item.h"

class Inventory
{
private:
	// fields
	vector<Item> items;
	int healthPotion;
	int maxWeight;
	string selectedCharacter;
	int gold;

public:
	// constructor
	Inventory(string& character, int& max)
	{
		selectedCharacter = character;
		maxWeight = max;
		gold = 100;

	}
	// getters
	int getItemWeight()
	{

	}
	int getHealthPotion()
	{
		return healthPotion;
	}
	

		// getters
	int getGold() const {
		return gold;
	}

	const vector<Item>& getItems() const {
		return items;
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

		// setters
	void addItem(Item* item) {
			items.push_back(item);
	}

	void removeItem(int index) {
		items.erase(items.begin() + index);
	}

	void addGold(int g) {
		gold += g;
	}

	void deductGold(int g) {
		gold -= g;
	}
	
	// setters
	//These are for loading the game.
	void setHealthPotion(int &health)
	{
		healthPotion += health;
	}

	
	void setItems(vector <Item> item)
	{
		items = item;
	}

	void equip()
	{

	}
	

	//Other Functions

	void openInventory(Ranger playerRanger, Wizard playerWizard, Rogue playerRogue)
	{
		cout << "Inventory Menu:\n"
			<< "1. Equip Item\n"
			<< "2. Discard Item\n"
			<< "3. Take Health Potion\n"
			<< "Enter your choice: \n";

		int choice;
		choice = _getch();

		switch (choice) {
		case 1:
		{
			// Equip Item
			// Add your code here to handle equipping an item
			// Example: 
			// item = getItem(index);
			// if (item != nullptr) {
			//     item->equip();
			// }
			break;
		}

		case 2:
		{
			// Discard Item
			cout << "Enter index of item to discard: ";
			int index;

			index = _getch();
			index += 1;
			if (index >= 1 && index < items.size() + 1) {
				// Remove item from the inventory
				delete items*[index + 1]; // Free memory
				items.erase(items.begin() + index);
				cout << "Item discarded.\n";
			}
			else {
				cout << "Invalid index.\n";
			}
			break;
		}

		default:
			cout << "Invalid choice.\n";
			break;
		}
	}
};

