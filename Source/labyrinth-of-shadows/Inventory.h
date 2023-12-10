// Auth: Christian A. Botos
// Date: 12/07/2023
// Desc: header file for the Inventory class for the player's inventory
#pragma once
<<<<<<< Updated upstream
#include "All_Includes.h"
#include "Item.h" //JPO: For some reason, this is needed here again?
=======
#include "Headers.h"
>>>>>>> Stashed changes

class Inventory
{
private:
	// fields
	int gold;
	vector<Item*> items;

public:
	// constructor
<<<<<<< Updated upstream
	Inventory(int initialGold = 100) : gold(initialGold) {}

	// getters
	int getGold() const {
		return gold;
	}

	const vector<Item*>& getItems() const {
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
=======
	Inventory(int initialGold = 0) : gold(initialGold) {}

	// getters
	int getGold() const
	{
		return gold;
	}

	const vector<Item*>& getItems() const
	{
		return items;
	}

	// setters
	template <typename T>
	void addItem(T* item)
	{
		items.push_back(static_cast<Item*>(item));
	}

	void removeItem(int index)
	{
		if (index >= 0 && index < items.size())
		{
			items.erase(items.begin() + index);
		}
	}

	void addGold(int g)
	{
		gold += g;
	}

	void deductGold(int g)
	{
		gold -= g;
	}
};
>>>>>>> Stashed changes

	void removeItem(int index) {
		items.erase(items.begin() + index);
	}

	void addGold(int g) {
		gold += g;
	}

	void deductGold(int g) {
		gold -= g;
	}
};