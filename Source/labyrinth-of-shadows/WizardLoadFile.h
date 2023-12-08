//Auth:William Brickner
//Date: 12/8/2023
//Desc: A structure that will hold all of the variables when we load the game.
#pragma once
#include "All_Includes.h"

struct WizardLoadFile
{
    int max,
        health,
        strength,
        intelligence,
        dexterity,
        level,
        numTurns,
        healthPotions,
        exp,
        expNeed,
        fireballLvl,
        iceWallLvl,
        round,
        score;
};