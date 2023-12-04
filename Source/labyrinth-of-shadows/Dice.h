#pragma once
//Auth: Hunter Kauffman
//Date: 11/30/23
//Desc: Dice class for generating random numbers based on the max and min number put in

#include <iostream>
#include <ctime>
using namespace std;

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
	}

	//Getters
	int getMax()
	{
		return max;
	}

	int getMin()
	{
		return min;
	}

	int getPrevRoll()
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
		srand(time(0));
		setPrevRoll(rand() % max + min);
		return prevRoll;
	}
};

