// Auth: William Brickner
// Date: 11/30/23
// Desc: Creating a the Boss class.
#pragma once
#include "All_Includes.h"

class Boss : public Character
{
private:
	int strength;
	int dexterity;
	int expWorth;
	string name;
	Dice enemyDice;

public:
	Boss(int round)
	{
		generateHealth(round);
		generateStrength(round);
		generateDexterity(round);
		name = "The Dark Lord";
		expWorth = round * 5;
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
		setHealth(350);
	}

	void generateStrength(int round)
	{
		strength = 70;
	}

	void generateDexterity(int round)
	{
		dexterity = 50; // These are static and need to be tested.
	}

	int getDamage() const
	{
		return strength;
	}

	string getName() const
	{
		return name;
	}
};