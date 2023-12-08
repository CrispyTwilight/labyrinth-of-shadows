//Auth: William Brickner
//Date: 11/30/23
//Desc: Creating the subclass Wizard for the player.
#pragma once
#include "All_Includes.h"

class Wizard : private Character
{
private:
    int maxHealth;
    int strength;
    int intelligence;
    int dexterity;
    int healthPotions;
    int level;
    int exp;
    int expNeeded;
    int fireballLvl;
    int iceWallLvl;
    int numberTurns;
    int fireballCooldown;
    int iceWallCooldown;
    int iceWallEffect;
    bool isRepulsionActivated;
    bool isBlocking;
    bool isStunned;
    bool isEnemyStunned;

public:
    Wizard(int max, int hea, int  str, int intel, int  dex, int lev, int ex, int need, int ice, int fire, int potion, int turns)
    {
        maxHealth = max;
        setHealth(hea);
        strength = str;
        intelligence = intel;
        dexterity = dex;
        level = lev;
        numberTurns = turns;
        healthPotions = potion;
        exp = ex;
        expNeeded = need;
        fireballLvl = fire;
        iceWallLvl = ice;
        // Since this an combat ability it will only be able to activated during combat so it starts off false
        isBlocking = false;
        isStunned = false;
        fireballCooldown = 0;
        iceWallCooldown = 0;
    }

    //Setters
    void setMaxHealth(int value)
    {
        maxHealth = value;
    }

    void setStrength(int value)
    {
        strength = value;
    }

    void setIntelligence(int value)
    {
        intelligence = value;
    }

    void setDexterity(int value)
    {
        dexterity = value;
    }

    void setLevel(int value)
    {
        level = value;
    }

    void setNumTurns(int value)
    {
        numberTurns = value;
    }

    void setHealthPotions(int value)
    {
        healthPotions = value;
    }

    void setExp(int value)
    {
        exp = value;
    }

    void setExpNeeded(int value)
    {
        expNeeded = value;
    }

    void setFirballLvl(int value)
    {
        fireballLvl = value;
    }
    void setIceWallLvl(int value)
    {
        iceWallLvl = value;
    }

    //Getters
    int getMaxHealth() const
    {
        return maxHealth;
    }

    int getStrength() const
    {
        return strength;
    }

    int getIntelligence() const
    {
        return intelligence;
    }

    int getDexterity() const
    {
        return dexterity;
    }

    int getLevel() const
    {
        return level;
    }

    int getNumturns() const
    {
        return numberTurns;
    }

    int getHealthPotions() const
    {
        return healthPotions;
    }

    int getExp() const
    {
        return exp;
    }

    int getExpNeeded() const
    {
        return expNeeded;
    }

    int getFireball() const
    {
        return fireballLvl;
    }

    int getIceWall() const
    {
        return iceWallLvl;
    }

    // Level up function
    void levelUp()
    {
        cout << "You have leveled up!\n";
        maxHealth += 5;
        setHealth(maxHealth);
        intelligence += 1;
        level += 1;
        if (level % 5 == 0) {
            // Increment the number of turns when the player's level is a multiple of 5
            numberTurns++;
            cout << "Congratulations! Your number of turns has increased to: " << numberTurns << endl;
        }

        exp = expNeeded - exp;
        expNeeded = level * 5;

        int choice;

        cout << "What Spell would you like to level up\n"
             << "Leveling up Fireball will increase its damage\n"
             << "Leveling up Ice wall will increase its effect duration but also increase cooldown duration.\n"
             << "Your cooldown will be two more than the level of the Ice wall spell."

             << "1. FireBall " << fireballLvl << endl
             << "2. Ice Wall " << iceWallLvl << endl;

        do {
            cout << "Enter your choice: ";
            cin >> choice;
            if (choice < 0 || choice > 3) {
                cout << "Incorrect value. Please enter a valid value.\n";
            }
        } while (choice < 0 || choice > 3);

        switch (choice)
        {
        case 1:
        {

            fireballLvl += 1;
            cout << "FireBall is now level " << fireballLvl << endl;
            break;
        }
        case 2:
        {
            iceWallLvl += 1;
            cout << "Ice Wall is now level " << iceWallLvl << endl;
            break;
        }
        // Need to finish the function in utility.
        //checkForLevelUp();
        }
    }
};