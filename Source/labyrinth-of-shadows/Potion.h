// Auth: Christian A. Botos
// Date: 12/07/ 2023
// Desc: Header file for the Potion structure for holding data variables.
#pragma once
#include "All_Includes.h"

struct Potion : public Item
{
	enum PotionType {
		NONE, // Default value
		SMALL_HEAL,
		HALF_HEAL,
		FULL_HEAL,
		DOUBLE_HEAL,
		POTION_TYPE_COUNT, // Used to determine the number of possible potion types.
	};

	// Fields
	PotionType type;
	int heal;
	int weight;
	string material;

	// Constructor with default arguments.
	// All parameters are passed by const reference to avoid copying the arguments for efficiency.
	Potion(const bool& randomize = false, const PotionType& type = NONE, const int& heal = 10, const int& weight = 5, const int& value = 20, const string& name = "Default Name", const string& material = "Default Material")
	{
		if (randomize) {
			Dice typeDie(Potion::POTION_TYPE_COUNT - 1, 1);
			this->type = static_cast<PotionType>(typeDie.rollDice());

			Dice dmgDie(20, 1);
			this->heal = dmgDie.rollDice();

			Dice weightDie(20, 1);
			this->weight = weightDie.rollDice();

			Dice valueDie(20, 1);
			this->value = valueDie.rollDice();

			Dice nameDie(possiblePotionNames.size() - 1);
			this->name = possiblePotionNames[nameDie.rollDice()];

			Dice materialDie(possiblePotionMaterials.size() - 1);
			this->material = possiblePotionMaterials[materialDie.rollDice()];
		} else {
			this->type = type;
			this->heal = heal;
			this->weight = weight;
			this->value = value;
			this->name = name;
			this->material = material;
		}
	}
};

// Operating globally on the Potion struct. It is put in this file because it is related to the Potion struct.
string potionTypeToString(Potion::PotionType type) {
	switch (type) {
	case Potion::SMALL_HEAL: return "Small Heal";
	case Potion::HALF_HEAL: return "Half Heal";
	case Potion::FULL_HEAL: return "Full Heal";
	case Potion::DOUBLE_HEAL: return "Double Heal";
	default: return "None";
	}
}