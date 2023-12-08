// Auth: Christian A. Botos
// Date: 12/07/ 2023
// Desc: Header file for the Potion structure for holding data variables. Can be used as a template for other structures 

#pragma once
#include <string>
#include <vector>

struct Potion
{
	enum PotionType {
		NONE, // Default value
		SMALL_HEAL,
		HALF_HEAL,
		FULL_HEAL,
		DOUBLE_HEAL,
		POTION_TYPE_COUNT,
	};

	// Fields
	int heal;
	int weight;
	int value;
	std::string name;
	std::string material;
	// There are two static fields that will be initialized in the Initializer.cpp file
	static std::vector<std::string> possiblePotionNames;
	static std::vector<std::string> possiblePotionMaterials;

	// Constructor with default arguments and initializer list
	// All params are pass by const reference to avoid copying the arguments for efficiency
	Potion(const int& heal = 10, const int& weight = 5, const int& value = 20, const std::string& name = "Default Name", const std::string& material = "Default Material")
		: heal(heal), weight(weight), value(value), name(name), material(material) {}
};

