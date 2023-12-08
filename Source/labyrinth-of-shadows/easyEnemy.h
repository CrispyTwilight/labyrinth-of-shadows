//Auth: William Brickner
// Date: 12/8/23
// Desc: The easy enemy class that will show the players the basics of combat without killing them outright.
#pragma once
#include <iostream>
#include <string>
#include "Character.h"


class easyEnemy : public Character
{
private:
	int strength;
	int dexterity;
	int expWorth;
	std ::string name;

public:
	easyEnemy()
	{
		setHealth(5);
		strength = 2;
		dexterity = 2;
		expWorth = 5;
		name = "Slurgle the Reviving Slime";
	}

	int attack()
	{
		return strength;
	}

	void takeDamage(int d)
	{
		setHealth(getHealth()-d);
	}

	int giveEXP()
	{
		return expWorth;
	}

	std ::string getName()
	{
		return name;
	}

};

