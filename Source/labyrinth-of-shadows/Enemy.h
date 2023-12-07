//Auth: William Brickner
//Date: 11/30/23
//Desc: Creating a the Enemy class.
#pragma once
#include "Character.h"
#include "Bow.h"
#include "Sword.h"
#include "Staff.h"
class Enemy : public Character
{
private:
	int strength;
	int dexterity;
	int expWorth;
	int battleStyle;
	std::string description; 
	Bow bow;
	Sword sword;
	Staff staff;

public:
	Enemy(int round)
	{
		generateHealth(round);
		generateStrength(round);
		generateDexterity(round);
		generateBattleStyle();
		expWorth = round * 2;
		generateNameAndDescription();
	}

	int attack()
	{
		return strength;
	}

	void takeDamage(int d)
	{
		setHealth(getHealth() - d);
	}

	int giveEXP()
	{
		return expWorth;
	}
	void generateHealth(int round)
	{
		setHealth(round * 3);
	}
	void generateStrength(int round)
	{
		int minStrength = round;
		int maxStrength = round * 2;
		strength = rand() % (maxStrength - minStrength + 1) + minStrength;
	}
	void generateDexterity(int round)
	{
		int minDexterity = round;
		int maxDexterity = round * 2;
		dexterity = rand() % (maxDexterity - minDexterity + 1) + minDexterity;
	}
	void generateBattleStyle() {
		battleStyle = rand() % 3; // Randomly choose battle style (0, 1, or 2)
	}

	void generateNameAndDescription() {
		std ::string names[] = { "Garkle", "Snarflark ", "Zog", "Blarg", "Gruk" };
		std ::string creatureTypes[] = { "Bandit", "Goblin", "Gremlin", "Skeleton" };

		int nameIndex = rand() % std::size(names);
		int typeIndex = rand() % std::size(creatureTypes);

		setName(names[nameIndex] + " the " + creatureTypes[typeIndex]);
		description = " a fearsome creature";

		if (creatureTypes[typeIndex] == "Bandit") {
			description = " a cunning bandit";
		}
		else if (creatureTypes[typeIndex] == "Goblin") {
			description = " a mischievous goblin";
		}
		else if (creatureTypes[typeIndex] == "Gremlin") {
			description = " a tricky gremlin";
		}
		else if (creatureTypes[typeIndex] == "Skeleton") {
			description = " an eerie skeleton";
		}
	}
	int getDamage()
	{
		switch (battleStyle)
		{
		case 0: // Ranger (Bow)
			return bow.damage + dexterity;
		case 1: // Warrior (Sword)
			return sword.damage + strength;
		case 2: // Monk (Staff)
			return staff.damage + strength;
		default:
			return 0;
		}
	}
};