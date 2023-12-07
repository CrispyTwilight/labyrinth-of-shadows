#pragma once
#include "Character.h"
#include "Sword.h"

class Boss : public Character
{
private:
	int strength;
	int dexterity;
	int expWorth;
	std ::string name;
	Sword sword;

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
		setHealth(round * 3);
	}
	void generateStrength(int round)
	{
		strength = round * 2;
	}
	void generateDexterity(int round)
	{
		int minDexterity = round;
		int maxDexterity = round * 2;
		dexterity = rand() % (maxDexterity - minDexterity + 1) + minDexterity;
	}



	int getDamage()
	{
		return sword.damage + strength;
	}

	std ::string getName()
	{
		return name;
	}

	
};

