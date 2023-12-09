// Auth: Christian A. Botos
// Date: 12/07/2023
// Desc: header file for the Inventory class for the player's inventory
#pragma once
#include "All_Includes.h"

class Inventory
{
private:
	// fields
	int gold;
	vector<Item*> items;

public:
	// constructor
	Inventory(int initialGold = 0) : gold(initialGold) {}

	// getters
	int getGold() const {
		return gold;
	}

	const vector<Item*>& getItems() const {
		return items;
	}

	// setters
	template <typename T>
	void addItem(T* item) {
		items.push_back(static_cast<Item*>(item));  // Assumes Item is a base class for T
	}

	void removeItem(int index) {
		if (index >= 0 && index < items.size()) {
			items.erase(items.begin() + index);
		}
	}

	void addGold(int g) {
		gold += g;
	}

	void deductGold(int g) {
		gold -= g;
	}
};