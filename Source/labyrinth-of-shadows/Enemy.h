//Auth: William Brickner
//Date: 11/30/23
//Desc: Creating a the Enemy class.
#pragma once
// #include "All_Includes.h"
// JPO: Temp fix for the issue with the compiler not finding the files

#include <iterator>
#include <string>
#include <iostream>
#include <vector>
#include <random>
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
		generateName();

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

	
	void generateName() 
	{
			vector<string> names = { "Garkle", "Snarflark", "Zog", "Blarg", "Gruk" };
			vector<string> creatureTypes = { "Bandit", "Goblin", "Gremlin", "Skeleton" };

			// Randomly select indices for name and creature type
			enemyDice.setMax(names.size() - 1);
			int nameIndex = enemyDice.rollDice();

			enemyDice.setMax(creatureTypes.size() - 1);
			int typeIndex = enemyDice.rollDice();

			// Construct the name and description based on the randomly chosen indices
			setName(names[nameIndex] + " the " + creatureTypes[typeIndex]);
			
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