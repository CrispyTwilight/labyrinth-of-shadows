// Auth: Christian A. Botos
// Date: 12/07/2023
// Desc: Header file for the Weapon structure to hold data variables. Can be used as a template for other structuress.

#pragma once // Ensures the file is only included once during compilation.
#include <string> // Include the string library for the name and material fields
#include <vector> // Include the vector library for the random weapon generation

struct Weapon {
	// Define enum for weapon types that can be used to determine what kind of weapon it is. It is defined inside the struct so that it can be accessed as Weapon::WeaponType
	enum WeaponType {
		NONE, // Default value
		AXE,
		BOW,
		DAGGER,
		SPEAR,
		STAFF,
		SWORD,
		WEAPON_TYPE_COUNT // Used to determine the amount of possible weapon types
	};

	// Other fields
	WeaponType type;
	int damage;
	int weight;
	int value;
	std::string name;
	std::string material;
	// There are two static fields that will be initialized in the initializer.cpp file
	static std::vector<std::string> possibleWeaponNames;
	static std::vector<std::string> possibleWeaponMaterials;

	// Constructor with default arguments and initializer list
	// All params are pass by const reference to avoid copying the arguments for efficiency
	Weapon(const WeaponType& type = NONE, const int& damage = 0, const int& weight = 0, const int& value = 0, const std::string& name = "Default Name", const std::string& material = "Default Material")
		: type(type), damage(damage), weight(weight), value(value), name(name), material(material) {}
};

