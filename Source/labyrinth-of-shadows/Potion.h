// Auth: Christian A. Botos
// Date: 12/07/ 2023
// Desc: Header file for the Potion structure for holding data variables.
#pragma once
#include "All_Includes.h"

struct Potion
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
	int value;
	string name;
	string material;

	// Constructor with default arguments and initializer list.
	// All parameters are passed by const reference to avoid copying the arguments for efficiency.
	Potion(const PotionType& = NONE, const int& heal = 10, const int& weight = 5, const int& value = 20, const string& name = "Default Name", const string& material = "Default Material")
		: type(type), heal(heal), weight(weight), value(value), name(name), material(material) {}

	// Randomized constructor. The randomize parameter has no use or effect, it is just there to differentiate it from the other constructor.
	explicit Potion(bool randomize) {
		Dice typeDie(Potion::POTION_TYPE_COUNT - 1, 1);
		type = static_cast<Potion::PotionType>(typeDie.rollDice());

		Dice dmgDie(20, 1);
		heal = dmgDie.rollDice();

		Dice weightDie(20, 1);
		weight = weightDie.rollDice();

		Dice valueDie(20, 1);
		value = valueDie.rollDice();

		Dice nameDie(Item::possiblePotionNames.size() - 1);
		name = Item::possiblePotionNames[nameDie.rollDice()];

		Dice materialDie(Item::possiblePotionMaterials.size() - 1);
		material = Item::possiblePotionMaterials[materialDie.rollDice()];
	}
};