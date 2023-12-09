#pragma once
#include "All_Includes.h"

class Boss : public Character
{
private:
	int strength;
	int dexterity;
	int expWorth;
	string name;
	Sword sword;
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
		strength = 50;
	}
	void generateDexterity(int round)
	{
		// These are static and need to be tested.
		dexterity = 50;
	}

	int getDamage() const
	{
		return sword.damage + strength;
	}

	string getName() const
	{
		return name;
	}

};