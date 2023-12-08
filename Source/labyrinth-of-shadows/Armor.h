// Auth: John O'Neal
// Date: 12/01/2023
// Desc: Header file for the Armor struct.
#pragma once
#include "All_Includes.h"

struct Armor {
	// Define enum for Armor types that can be used to determine what kind of Armor it is. It is defined inside the struct so that it can be accessed as Armor::ArmorType
	enum ArmorType {
		NONE, // Default value
		BREASTPLATE,
		HELMET,
		CAP,
		GAUNTLETS,
		SHIELD,
		GLOVES,
		ARMOR_TYPE_COUNT // Used to determine the number of Armor types
	};

	// Other fields
	ArmorType type;
	int defense;
	int weight;
	int value;
	std::string name;
	std::string material;
	// There are two static fields that will be initialized in the initializer.cpp file
	static std::vector<std::string> possibleNames;
	static std::vector<std::string> possibleMaterials;

	// Constructor with default arguments and initializer list
	// All params are pass by const reference to avoid copying the arguments for efficiency
	Armor(const ArmorType& type = NONE, const int& defense = 0, const int& weight = 0, const int& value = 0, const std::string& name = "Default Name", const std::string& material = "Default Material")
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

		Dice nameDie(Item::possibleNames.size() - 1);
		name = Item::possibleNames[nameDie.rollDice()];

		Dice materialDie(Item::possibleMaterials.size() - 1);
		material = Item::possibleMaterials[materialDie.rollDice()];
	}
};