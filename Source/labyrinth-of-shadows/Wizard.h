//Auth: William Brickner
//Date: 11/30/23
//Desc: Creating the subclass Wizard for the player.
#pragma once
#include "Character.h"
#include "Utility.h"
#include "Staff.h"
#include <conio.h> // This allows us to use _getch() which will automatically continue after the user enters a single character.

class Wizard : public Character
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
    bool isBlocking;
    bool isStunned;
    bool isEnemyStunned;
    Staff staff;
    Utility util;

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
            choice = _getch();
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
        default:
        {
            cout << "You have encountered an error.";
            break;
        }
       
        }
        if (util.checkForLevelUp(exp, expNeeded))
        {
            levelUp();
        }
    }
    void playerTurn(Enemy& enemy)
    {
        if (iceWallEffect > 0)
        {
            isBlocking = true;
            iceWallEffect -= 1;
        }
        else
        {
            isBlocking = false;
        }


        int choice = 0;

        if (iceWallCooldown > 0)
        {
            iceWallCooldown -= 1;
        }

        if (fireballCooldown > 0)
        {
            fireballCooldown -= 1;
        }



        for (int turn = 1; turn <= numberTurns; ++turn)
        {
            cout << "It's your turn, what would you like to do?\n";
            cout << "1. Basic Attack\n"
                << "2. Take Health Potion\n"
                << "3. Ice Wall\n"
                << "4. Fireball\n";

            do {
                bool incorrectChoice = false;
                cout << "Enter your choice: ";
                cin >> choice;

                if (choice == 2 && healthPotions < 0) {
                    cout << "You are out of health potions, pick another option.\n";
                    incorrectChoice = true;
                }
                else if (choice == 2 && getHealth() == maxHealth) {
                    cout << "You are full on health. I highly recommend you do something else.\n";
                    incorrectChoice = true;
                }
                else if (choice == 3 && iceWallCooldown > 0) {
                    cout << "Ice Wall is still on cooldown. You have to wait " << iceWallCooldown << " number of turns.\n";
                    incorrectChoice = true;
                }
                else if (choice == 4 && fireballCooldown > 0) {
                    cout << "Fireball is still on cooldown. You have to wait " << fireballCooldown << " number of turns.\n";
                    incorrectChoice = true;
                }


                // Check if the choice is invalid due to cooldown or lack of resources
                if (incorrectChoice) {
                    // The do-while loop will continue if the choice was incorrect
                    continue;
                }

            } while (choice > 5 || choice < 0);

            switch (choice)
            {
            case 1:
            {
                // attack monster
                attackMonster(enemy, staff.damage + dexterity);
                break;
            }
            case 2:
            {
                // Take Health Potion If have any
                takePotion();
                break;
            }
            case 3:
            {
                isBlocking = true;
                iceWallCooldown = iceWallLvl + 2;
                iceWallEffect = iceWallLvl + 1;
                break;
            }
            break;
            case 4:
            {
                attackMonster(enemy, fireBall());
                break;
            }
            default:
            {
                cout << "You have encountered an error.";
                break;
            }
            }
        }
    }


    //Player turn for easy enemies.
    void playerTurnEasy(easyEnemy& easyEnemy)
    {
        if (iceWallEffect > 0)
        {
            isBlocking = true;
            iceWallEffect -= 1;
        }
        else
        {
            isBlocking = false;
        }


        int choice = 0;


        if (iceWallCooldown > 0)
        {
            iceWallCooldown -= 1;
        }

        if (fireballCooldown > 0)
        {
            fireballCooldown -= 1;
        }
        for (int turn = 1; turn <= numberTurns; ++turn)
        {

            cout << "It's your turn, what would you like to do?\n";
            cout << "1. Basic Attack\n"

                << "2. Take Health Potion\n"
                << "3. Ice Wall\n"
                << "4. Fireball\n";

            do {
                bool incorrectChoice = false;
                cout << "Enter your choice: ";
                cin >> choice;

                if (choice == 2 && healthPotions < 0) {
                    cout << "You are out of health potions, pick another option.\n";
                    incorrectChoice = true;
                }
                else if (choice == 2 && getHealth() == maxHealth) {
                    cout << "You are full on health. I highly recommend you do something else.\n";
                    incorrectChoice = true;
                }
                else if (choice == 3 && iceWallCooldown > 0) {
                    cout << "Ice Wall is still on cooldown. You have to wait " << iceWallCooldown << " number of turns.\n";
                    incorrectChoice = true;
                }
                else if (choice == 4 && fireballCooldown > 0) {
                    cout << "Fireball is still on cooldown. You have to wait " << fireballCooldown << " number of turns.\n";
                    incorrectChoice = true;
                }

                // Check if the choice is invalid due to cooldown or lack of resources
                if (incorrectChoice) {
                    // The do-while loop will continue if the choice was incorrect
                    continue;
                }

            } while (choice > 5 || choice < 0);

            switch (choice)
            {
            case 1:
            {
                // attack monster
                attackMonsterEasy(easyEnemy, staff.damage + dexterity);
                break;
            }
            case 2:
            {
                // Take Health Potion If have any
                takePotion();
                break;
            }
            case 3:
            {
                isBlocking = true;
                iceWallCooldown = iceWallLvl + 2;
                iceWallEffect = iceWallLvl + 1;
            }
            break;
            case 4:
            {
                attackMonsterEasy(easyEnemy, fireBall());
                break;
            }
            }

        }

    }

    // Taking damage from a normal enemy.
    void takeDamage(Enemy& enemy, int d)
    {
        // Getting a random number and seeing if the players dex is higher and if it is they will dodge the attack.
        int enemyAttack = rand() % 100 + 1;

        if (isBlocking)
        {
            cout << "You successfully blocked the attack!\n";
        }

        else if (enemyAttack <= dexterity)
        {
            cout << "You dodged the attack!\n";
        }
        else
        {
            cout << "You took " << d << " damage\n";
            setHealth(getHealth() - d);
        }
    }

    // Taking damage from the easy enemy.
    void takeDamageEasyEnemy(easyEnemy& easyEnemy, int d)
    {
        int enemyAttack = rand() % 100 + 1;

        if (isBlocking)
        {
            cout << "You successfully blocked the attack!\n";
        }
        else if (enemyAttack <= dexterity)
        {
            cout << "You dodged the attack!\n";
        }
        else
        {
            cout << "You took " << d << " damage\n";
            setHealth(getHealth() - d);
        }
    }

    // Taking damage from a normal enemy.
    void takeDamageBoss(Boss& boss, int d)
    {
        // Getting a random number and seeing if the players dex is higher and if it is they will dodge the attack.
        int enemyAttack = rand() % 100 + 1;

        if (isBlocking)
        {
            cout << "You successfully blocked the attack!\n";
        }
        else if (enemyAttack <= dexterity)
        {
            cout << "You dodged the attack!\n";
        }
        else
        {
            cout << "You took " << d << " damage\n";
            health -= d;
        }

    void attackMonster(Enemy& enemy, int d)
    {
        enemy.takeDamage(d);
        cout << enemy.getName() << "took " << d << " damage.\n";
    }

    void attackMonsterEasy(easyEnemy& easyEnemy, int d)
    {
        easyEnemy.takeDamage(d);
        cout << easyEnemy.getName() << " took " << d << " damage.\n";
    }

    int fireBall()
    {
        return intelligence * fireballLvl;
    }
    void takePotion()
    {
        healthPotions -= 1;

        setHealth(getHealth() + level * 5);
        if (getHealth() > maxHealth)
        {
            setHealth(maxHealth);
        }
        cout << "Your health is now at " << getHealth() << endl;
    }
    

    // The function for fighting every enemy after that.
    void fightNormalEnemy(Enemy& enemy)
    {

        cout << "You encounter " << enemy.getName() << " with " << enemy.getHealth() << " health!\n";

        while (getHealth() > 0 && enemy.getHealth() > 0) {
            // Player's turn
            playerTurn(enemy);

            // Enemy's turn
            takeDamage(enemy, enemy.getDamage());


            // Display updated stats after each round
         
            cout << "Enemy's health: " << enemy.getHealth() << endl;
        }

        if (getHealth() <= 0) {
            // Game over logic
            cout << "You were defeated! Game Over.\n";

        }
        else 
        {
            // Victory logic
            cout << "You defeated the enemy!\n";
            cout << "You gained " << enemy.giveEXP() << "Experience\n";

            healthPotions++;
            exp += enemy.giveEXP();
            util.checkForLevelUp(exp,expNeeded);
        }
    }

    // The function when the player has to fight a weak enemy (The first three enemies).
    void fightWeakEnemy(easyEnemy& easyEnemy)
    {
        // Display the enemy's details
        cout << "You encounter " << easyEnemy.getName() << " with " << easyEnemy.getHealth() << " health!\n";

        while (getHealth() > 0 && easyEnemy.getHealth() > 0) {
            // Player's turn
            playerTurnEasy(easyEnemy);

            if (easyEnemy.getHealth() > 0)
            {
                // Enemy's turn
                if (!isEnemyStunned)
                {
                    takeDamageEasyEnemy(easyEnemy, easyEnemy.attack());

                }
                else
                {
                    cout << "The enemies turn was skipped!\n";
                }
            }
            // Display updated stats after each round

            cout << "Enemy's health: " << easyEnemy.getHealth() << endl;
            cout << "Your Health is at " << getHealth() << endl;
        }

        if (getHealth() <= 0) {
            cout << "You were defeated! Game Over.\n";
            // Game over logic


        }
        else {
            cout << "You defeated the enemy!\n";
            exp += easyEnemy.giveEXP();
            isEnemyStunned = false;
            if (util.checkForLevelUp(exp, expNeeded))
            {
                levelUp();
            }
        }
    }


};