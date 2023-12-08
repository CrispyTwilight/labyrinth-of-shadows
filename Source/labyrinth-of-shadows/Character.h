//Auth: Will Brickner
//Date: 11/30/2023
//Desc: Creating a superclass for the player, npcs, and enemies
#pragma once
#include "All_Includes.h"


class Character
{
private:
    //Fields
    int health;
    string name;

public:
    Character()
    {
        health = 0;
        name = "";
    }

    Character(int hea, string n)
    {
        health = hea;
        name = n;
    }
    //Setters
    void setHealth(int value)
    {
        health = value;
    }

    void setName(string n)
    {
        name = n;
    }

    //Getters
    int getHealth() const
    {
        return health;
    }

    string getName() const
    {
        return name;
    }
};