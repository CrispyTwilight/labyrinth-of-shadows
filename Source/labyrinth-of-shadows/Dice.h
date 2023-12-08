//Auth: Hunter Kauffman
//Date: 11/30/23
//Desc: Dice class for generating random numbers based on the max and min number put in
#pragma once
#include "All_Includes.h"

class Dice
{
private:
	//Fields
	int max;
	int min;
	int prevRoll;

public:
	//Constructor
	Dice(int mx = 0, int mn = 0, int pr = 0)
	{
		setMax(mx);
		setMin(mn);
		setPrevRoll(pr);
		int srand(time(0)); // JPO: Moved to constructor
	}

	//Getters
	int getMax() const
	{
		return max;
	}

	int getMin() const
	{
		return min;
	}

	int getPrevRoll() const
	{
		return prevRoll;
	}

	//Setters
	void setMax(int mx)
	{
		max = mx;
	}

	void setMin(int mn)
	{
		min = mn;
	}

	void setPrevRoll(int pr)
	{
		prevRoll = pr;
	}

	//Methods
	int rollDice() //Rolls the dice with the given max and min and returns it as an integer
	{
		setPrevRoll(rand() % (max - min + 1) + min); // JPO: Changed to use correct formula
		return prevRoll;
	}
};