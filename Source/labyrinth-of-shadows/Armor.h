// Auth: Christian A. Botos, John O'Neal
// Date: 12/07/2023
// Desc: Header file for the Armor struct.
#pragma once
#include "All_Includes.h"

struct Armor : public Item {
	// Define enumerated data type for Armor types that can be used to determine what kind of Armor it is.
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
	Armor(const bool& randomize = false, const ArmorType& type = NONE, const int& defense = 0, const int& weight = 0, const int& value = 0, const string& name = "Default Name", const string& material = "Default Material") {
		if (randomize) {
			Dice typeDie(Armor::ARMOR_TYPE_COUNT - 1, 1);
			this->type = static_cast<ArmorType>(typeDie.rollDice());

			Dice defDie(20, 1);
			this->defense = defDie.rollDice();

			Dice weightDie(20, 1);
			this->weight = weightDie.rollDice();

			Dice valueDie(20, 1);
			this->value = valueDie.rollDice();

			Dice nameDie(possibleArmorNames.size() - 1);
			this->name = possibleArmorNames[nameDie.rollDice()];

			Dice materialDie(possibleArmorMaterials.size() - 1);
			this->material = possibleArmorMaterials[materialDie.rollDice()];
		}
		else {
			this->type = type;
			this->defense = defense;
			this->weight = weight;
			this->value = value;
			this->name = name;
			this->material = material;
		}
	}

	//Armor constructor for the load file

	Armor(string armorType, int def, int wei, int val, const string& nm, const string& mat)
	{
		type = stringToArmorType(armorType);
		defense = def;
		weight = wei;
		value = val;
		name = nm;
		material = mat;
	}

	ArmorType getArmorType()
	{
		return type;
	}

};

//Armor constructor for the load file


// Operating globally on the Armor struct. It is put in this file because it is related to the Armor struct.
string armorTypeToString(Armor::ArmorType type) {
	switch (type) {
	case Armor::BREASTPLATE: return "Breastplate";
	case Armor::HELMET: return "Helmet";
	case Armor::CAP: return "Cap";
	case Armor::GAUNTLETS: return "Gauntlets";
	case Armor::GREAVES: return "Greaves";
	case Armor::SHIELD: return "Shield";
	case Armor::GLOVES: return "Gloves";
	default: return "None";
	}
}

Armor::ArmorType stringToArmorType(const string& armorTypeStr) 
{
	if (armorTypeStr == "Breastplate") {
		return Armor::BREASTPLATE;
	}
	else if (armorTypeStr == "Helmet") {
		return Armor::HELMET;
	}
	else if (armorTypeStr == "Cap") {
		return Armor::CAP;
	}
	else if (armorTypeStr == "Gauntlets") {
		return Armor::GAUNTLETS;
	}
	else if (armorTypeStr == "Greaves") {
		return Armor::GREAVES;
	}
	else if (armorTypeStr == "Shield") {
		return Armor::SHIELD;
	}
	else if (armorTypeStr == "Gloves") {
		return Armor::GLOVES;
	}

	// Return a default value in case of an unknown string
	return Armor::NONE;
}
