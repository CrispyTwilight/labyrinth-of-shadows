// Auth: Christian A. Botos, John O'Neal
// Date: 12/07/2023
// Desc: Header file for the Armor struct.
#pragma once
#include "All_Includes.h"

struct Armor {
	// Define enumerated data type for Armor types that can be used to determine what kind of Armor it is. It is defined inside the struct and can be accessed as Armor::ArmorType.
	enum ArmorType {
		NONE, // Default value
		BREASTPLATE,
		HELMET,
		CAP,
		GAUNTLETS,
		GREAVES,
		SHIELD,
		GLOVES,
		ARMOR_TYPE_COUNT // Used to determine the number of Armor types
	};

	// Other fields
	ArmorType type;
	int defense;
	int weight;
	int value;
	string name;
	string material;

	// Constructor with default arguments and initializer list.
	// All parameters are pass by const reference to avoid copying the arguments for efficiency.
	Armor(const ArmorType& type = NONE, const int& defense = 0, const int& weight = 0, const int& value = 0, const string& name = "Default Name", const string& material = "Default Material")
		: type(type), defense(defense), weight(weight), value(value), name(name), material(material) {}

	// Random armor generator
	explicit Armor(bool randomize) {
		Dice typeDie(Armor::ARMOR_TYPE_COUNT - 1, 1);
		type = static_cast<Armor::ArmorType>(typeDie.rollDice());

		Dice defDie(20, 1);
		defense = defDie.rollDice();

		Dice weightDie(20, 1);
		weight = weightDie.rollDice();

		Dice valueDie(20, 1);
		value = valueDie.rollDice();

		Dice nameDie(Item::possibleArmorNames.size() - 1);
		name = Item::possibleArmorNames[nameDie.rollDice()];

		Dice materialDie(Item::possibleArmorMaterials.size() - 1);
		material = Item::possibleArmorMaterials[materialDie.rollDice()];
	}
};