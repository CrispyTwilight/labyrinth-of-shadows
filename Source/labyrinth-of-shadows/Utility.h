//Auth: William Brickner (Should be everyone else as well.)
//Date: 11/30/23
//Desc: All of the utility function and modules that are used most or all classes that will free up space and get rid of clutter.
#pragma once
#include "Ranger.h"
#include "Wizard.h"
#include "Rogue.h"
class Utility
{
public:
    
    bool checkForLevelUp(int &exp, int &expNeeded)
    {
        if (exp >= expNeeded)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
 
};