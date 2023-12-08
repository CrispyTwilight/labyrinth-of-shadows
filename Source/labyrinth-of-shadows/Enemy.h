//Auth: William Brickner
//Date: 11/30/23
//Desc: Creating a the Enemy class.
#pragma once
#include "All_Includes.h"

class Enemy : private Character
{
private:
	int strength;
	int dexterity;
	int expWorth;
	int battleStyle;
	std::string description; // JPO: It's good practice to use std:: instead of using namespace std; in any header file.
};