struct Weapon : public Item {
	// Define enum for weapon types that can be used to determine what kind of weapon it is.
	enum WeaponType {
		NONE, // Default value
		AXE,
		BOW,
		DAGGER,
		SPEAR,
		STAFF,
		SWORD,
		WEAPON_TYPE_COUNT // Used to determine the number of possible weapon types.0.
	};

	// Other fields
	WeaponType type;
	int damage;
	int weight;
	int value;
	string name;
	string material;

	// Constructor with default arguments and initializer list.
	// All parameters are passed by const reference to avoid copying the arguments for efficiency.
	Weapon(const bool& randomize = false, const WeaponType& type = NONE, const int& damage = 0, const int& weight = 0, const int& value = 0, const string& name = "Default Name", const string& material = "Default Material") {
		if (randomize) {
			Dice typeDie(Weapon::WEAPON_TYPE_COUNT - 1, 1);
			this->type = static_cast<WeaponType>(typeDie.rollDice());

			Dice dmgDie(20, 1);
			this->damage = dmgDie.rollDice();

			Dice weightDie(20, 1);
			this->weight = weightDie.rollDice();

			Dice valueDie(20, 1);
			this->value = valueDie.rollDice();

			Dice nameDie(possibleWeaponNames.size() - 1);
			this->name = possibleWeaponNames[nameDie.rollDice()];

			Dice materialDie(possibleWeaponMaterials.size() - 1);
			this->material = possibleWeaponMaterials[materialDie.rollDice()];
		}
		else {
			this->type = type;
			this->damage = damage;
			this->weight = weight;
			this->value = value;
			this->name = name;
			this->material = material;
		}
	}
};

// Operating globally on the Weapon struct. It is put in this file because it is related to the Weapon struct.
string weaponTypeToString(Weapon::WeaponType type) {
	switch (type) {
	case Weapon::AXE: return "Axe";
	case Weapon::BOW: return "Bow";
	case Weapon::DAGGER: return "Dagger";
	case Weapon::SPEAR: return "Spear";
	case Weapon::STAFF: return "Staff";
	case Weapon::SWORD: return "Sword";
	default: return "None";
	}
}