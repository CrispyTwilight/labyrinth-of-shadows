//Auth: William Brickner
//Date: 11/30/23
//Desc: Creating a the Enemy class.
#pragma once
// #include "All_Includes.h"
// JPO: Temp fix for the issue with the compiler not finding the files

#include <iterator>
#include <string>
#include <iostream>

#include "Sword.h"
#include "Bow.h"
#include "Staff.h"
#include "Dice.h"


class Enemy : public Character
{
private:
	int strength;
	int dexterity;
	int expWorth;
	int battleStyle;
	string description;
	Bow bow;
	Sword sword;
	Staff staff;
	Dice enemyDice;



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
		enemyDice.setMin(1);
		enemyDice.setMax((maxStrength - minStrength + 1) + minStrength);
	}
	void generateDexterity(int round)
	{
		int minDexterity = round;
		int maxDexterity = round * 2;
		enemyDice.setMin(1);
		enemyDice.setMax((maxDexterity - minDexterity + 1) + minDexterity);
	}

	void generateBattleStyle() {
		enemyDice.setMin(0);
		enemyDice.setMax(2);
		battleStyle = enemyDice.rollDice(); // Randomly choose battle style (0, 1, or 2)
	}

	void generateNameAndDescription() {
		string names[] = { "Garkle", "Snarflark ", "Zog", "Blarg", "Gruk" };
		string creatureTypes[] = { "Bandit", "Goblin", "Gremlin", "Skeleton" };

		enemyDice.setMax(size(names));
		enemyDice.setMin(0);
		int nameIndex = enemyDice.rollDice();
		enemyDice.setMax(size(creatureTypes));
		int typeIndex = enemyDice.rollDice();

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