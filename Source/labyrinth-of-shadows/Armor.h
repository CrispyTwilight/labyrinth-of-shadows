// Auth: Christian A. Botos
// Date: 12/07/2023
// Desc: Header file for the Armor structure for holding data variables. Can be used as a template for other structures.

#pragma once // Ensures this file is only included once during compilation.
#include "Headers.h"

struct Armor {
	// Define enumerated data type for Armor types that can be used to determine what kind of Armor it is. It is defined inside the struct so that it can be accessed as Armor::ArmorType
	enum ArmorType {
		NONE, // Default value
		BREASTPLATE,
		HELMET,
		CAP,
		GAUNTLETS,
		GREAVES,
		SHIELD,
		GLOVES,
		ARMOR_TYPE_COUNT, // Used to determine the amount of possible armor pieces
	};

	// Other fields
	ArmorType type;
	int defense;
	int weight;
	int value;
	std::string name;
	std::string material;
	// There are two static fields that will be initialized in the initializer.cpp file
	static std::vector<std::string> possibleArmorNames;
	static std::vector<std::string> possibleArmorMaterials;

	// Constructor with default arguments and initializer list
	// All params are pass by const reference to avoid copying the arguments for efficiency
	Armor(const ArmorType& type = NONE, const int& defense = 0, const int& weight = 0, const int& value = 0, const std::string& name = "Default Name", const std::string& material = "Default Material")
		: type(type), defense(defense), weight(weight), value(value), name(name), material(material) {}
};