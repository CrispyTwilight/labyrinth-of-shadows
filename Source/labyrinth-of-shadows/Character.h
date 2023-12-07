//Auth: Will Brickner
//Date: 11/30/2023
//Desc: Creating a superclass for the player, npcs, and enemies
#pragma once
#include <iostream>
#include "Utility.h"


class Character
{
private:
    //Fields
    int health;
    std ::string name;

public:
    Character()
    {
        health = 0;
        name = "";
    }

    Character(int hea, std ::string n)
    {
        health = hea;
        name = n;
    }
    //Setters
    void setHealth(int value)
    {
        health = value;
    }

    void setName(std ::string n)
    {
        name = n;
    }

    //Getters
    int getHealth() const
    {
        return health;
    }

    std ::string getName() const
    {
        return name;
    }
};