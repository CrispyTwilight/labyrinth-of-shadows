// Auth: Christian A. Botos, John O'Neal
// Date: 12/07/2023
// Desc: Header file for the Weapon structure to hold data variables. Can be used as a template for other structuress.
#pragma once
#include "All_Includes.h"

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
		WEAPON_TYPE_COUNT // Used to determine the number of possible weapon types
	};

	// Other fields
	WeaponType type;
	int damage;
	int weight;
	int value;
	string name;
	string material;

	// Constructor with default arguments and initializer list
	// All params are pass by const reference to avoid copying the arguments for efficiency
    Weapon(const WeaponType& type = NONE, const int& damage = 0, const int& weight = 0, const int& value = 0, const string& name = "Default Name", const string& material = "Default Material")
		: type(type), damage(damage), weight(weight), value(value), name(name), material(material) {}

	// Randomized constructor. The randomize parameter is defaulted to true so that it can be called with no arguments to generate a random weapon. It has no effect on the constructor, it is just there to differentiate it from the other constructor.
	explicit Weapon(bool randomize) {
		Dice typeDie(Weapon::WEAPON_TYPE_COUNT - 1, 1);
        type = static_cast<Weapon::WeaponType>(typeDie.rollDice());

        Dice dmgDie(20, 1);
        damage = dmgDie.rollDice();

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