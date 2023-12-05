//Auth: William Brickner
//Date: 11/30/23
//Desc: Creating the subclass ranger for the player.
#pragma once
#include "Character.h"
#include "Enemy.h"
#include "Utility.h"
#include <conio.h> // This allows us to use _getch() which will automatically continue after the user enters a single character.
#include "Bow.h"

class Ranger : public Character
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
    int rainLvl; 
    int chargedLvl;
    int repulsionLvl;
    int numberTurns;
    int rainCooldown;
    int chargedCooldown;
    int repulsionUses;
    bool isRepulsionActivated;
    bool isBlocking;
    bool isStunned;
    bool isEnemyStunned;
    Bow bow;
public:
    Ranger(int max, int hea, int  str, int intel, int  dex, int lev, int ex, int need, int rai, int charg, int re, int potion, int turns)
    {
        maxHealth = max;
        //This is a placeholder because the playername
        setName("Ranger");
        setHealth(hea);
        strength = str;
        intelligence = intel;
        dexterity = dex;
        level = lev;
        numberTurns = turns;
        healthPotions = potion;
        exp = ex;
        expNeeded = need;
        rainLvl = rai;
        chargedLvl = charg;
        repulsionLvl = re;
        // Since this an combat ability it will only be able to activated during combat so it starts off false
        isRepulsionActivated = false;
        isBlocking = false;
        isStunned = false;
        isEnemyStunned = false;
        rainCooldown = 0;
        chargedCooldown = 0;
        repulsionUses = repulsionLvl;

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

    void setRainLvl(int value)
    {
        rainLvl = value;
    }

    void setChargedLvl(int value)
    {
        chargedLvl = value;
    }

    void setRepulsionLvl(int value)
    {
        repulsionLvl = value;
    }

    // Getters
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

    int getNumTurns() const
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

    int getRainLvl() const
    {
        return rainLvl;
    }

    int getChargedLvl() const
    {
        return chargedLvl;
    }

    int getRepulsionLvl() const
    {
        return repulsionLvl;
    }

    // Leveling up the player
    void levelUp()
    {
        std ::cout << "Congratulations you leveled up!";
        // Increasing the players max health and healing them to full.
        maxHealth += 5;
        setHealth(maxHealth);
        dexterity += 1;
        level += 1;
        if (level % 5 == 0) {
            // Increment the number of turns when the player's level is a multiple of 5
            numberTurns++;
            std :: cout << "Congratulations! Your number of turns has increased to: " << numberTurns << std :: endl;
        }

        expNeeded = level * 5;
        exp = expNeeded - exp;

        int choice;

        // Displaying the level up message
        std ::cout << "What Spell would you like to level up\n"
             << "Rain of Arrows per level will do an additional 5 damage. Starts with doing 10 damage.\n"
             << "Charged Shot for the first unlock will allow the Ranger to stun their enemy for a turn.  \n"
             << "Then every upgrade after that increases the number of turns per stun. Then the cooldown will increase a turn by one as well.\n"
             << "Repulsion will reflect the next damage that is taken back at the opponent base can only be used once per a fight.\n"
             << "But every level after number one you can use it an additional time per combat\n"
             << "1. Rain of Arrows " << rainLvl << std :: endl
             << "2. Charged Shot " << chargedLvl << std :: endl
             << "3. Repulsion " << repulsionLvl << std :: endl << std :: endl << std :: endl;

        do {
            std :: cout << "Enter your choice: ";
            // Here is the use of getch.
            choice = _getch();
            if (choice < 0 || choice > 3) {
                std :: cout << "Incorrect value. Please enter a valid value.\n";
            }
        } while (choice < 0 || choice > 3);

        switch (choice)
        {
            case 1:
            {
                rainLvl += 1;
                std ::cout << "Rain of Arrows is now level " << rainLvl << std :: endl;
                break;
            }
            case 2:
            {
                chargedLvl += 1;
                std :: cout << "Charged Shot is now level " << chargedLvl << std :: endl;
                break;
            }
            case 3:
            {
                repulsionLvl += 1;
                std ::cout << "Repulsion is now level " << repulsionLvl << std :: endl;
                break;
            }
            default:
            {
                std :: cout << "Incorrect value. Please eneter a valid value.\n";
                break;
            }
           
        }
        //Seeing if they enough exp for a second level up.
        //This will go to the utility class to check.
        //checkForLevelUp();
    }

    //Player turn for the base enemy type
    void playerTurn(Enemy& enemy)
    {
        //Setting blocking back to off at the start of their next turn.
        isBlocking = false;
        // Only lowering the cooldowns when they are above zero.
        if (rainCooldown > 0)
        {
            rainCooldown -= 1;
        }
        if (chargedCooldown > 0)
        {
            chargedCooldown -= 1;
        }
        // Reseting the choice variable
        int choice = 0;

        if (chargedCooldown == 1)
        {
            isEnemyStunned = false;
        }
        // Starting the turn if the player is not stunned.
        if (!isStunned)
        {

            for (int turn = 1; turn <= numberTurns; ++turn)
            {
               std :: cout << "It's your turn, what would you like to do?\n"
                    << "1. Basic Attack\n"
                    << "2. Block\n"
                    << "3. Take Health Potion\n"
                    << "4. Rain of Arrows\n"
                    << "5. Charged Shot\n"
                    << "6. Repulsion\n" << std :: endl << std ::endl;


                do {
                    bool incorrectChoice = false;
                    std ::cout << "Enter your choice: ";
                    choice = _getch();

                    if (choice == 3 && healthPotions < 0) {
                        std:: cout << "You are out of health potions, pick another option.\n";
                        incorrectChoice = true;
                    }
                    else if (choice == 3 && getHealth() == maxHealth) {
                        std:: cout << "You are full on health. I highly recommend you do something else.\n";
                        incorrectChoice = true;
                    }
                    else if (choice == 4 && rainCooldown > 0) {
                        std:: cout << "Rain of Arrows is still on cooldown. You have to wait " << rainCooldown << " number of turns.\n";
                        incorrectChoice = true;
                    }
                    else if (choice == 5 && chargedCooldown > 0) {
                        std:: cout << "Charged shot is still on cooldown. You have to wait " << chargedCooldown << " number of turns.\n";
                        incorrectChoice = true;
                    }
                    else if (choice < 0 || choice > 5) {
                        std:: cout << "Incorrect value. Please enter a valid value.\n";
                        incorrectChoice = true;
                    }

                    // Check if the choice is invalid 
                    if (incorrectChoice) {
                        // The do-while loop will continue if the choice was incorrect
                        continue;
                    }

                } while (choice > 6 || choice < 0);


                switch (choice)
                {
                case 1:
                {
                    std:: cout << "You did a basic attack\n";
                    // attack monster
                    attackMonster(enemy, bow.damage + dexterity);
                    break;
                }
                case 2:
                {
                    // Block attack
                    std:: cout << "You have started to block\n";
                    isBlocking = true;
                    break;
                }
                case 3:
                {
                    // Take Health Potion If have any
                    std:: cout << "You took a health potion\n";
                    takePotion();
                    break;
                }
                case 4:
                {
                    std:: cout << "You used Rain of Arrows\n";
                    // Rain of arrows
                    attackMonster(enemy, rainAttack());
                    rainCooldown = 3;
                    break;
                }
                case 5:
                {
                    std:: cout << " You used Charged Shot\n";
                    // Charged Shot
                    isEnemyStunned = true;
                    chargedCooldown = chargedLvl + 1;
                    break;
                }
                case 6:
                {
                    std:: cout << "You activated Repulsion\n";
                    //Repulsion Activates
                    isRepulsionActivated = true;
                    break;
                }
                default:
                {
                    std:: cout << "You put in an incorrect value please try again\n";
                }
                }
            }
        }
        if (isStunned)
        {
            std:: cout << "You turn has been skipped!\n";
        }
    }

    void attackMonster(Enemy& enemy, int d)
    {
        enemy.takeDamage(d);
        std:: cout << enemy.getName() << "took " << d << " damage.\n";
    }

    // Taking damage from a normal enemy.
    void takeDamage(Enemy& enemy, int d)
    {
        // Getting a random number and seeing if the players dex is higher and if it is they will dodge the attack.
        int enemyAttack = rand() % 100 + 1;

        if (isBlocking)
        {
            std:: cout << "You successfully blocked the attack!\n";
        }
        else if (isRepulsionActivated)
        {
            std:: cout << "You used Repulsion";
            attackMonster(enemy, d);
        }
        else if (enemyAttack <= dexterity)
        {
            std:: cout << "You dodged the attack!\n";
        }
        else
        {
            std::cout << "You took " << d << " damage\n";
            setHealth(getHealth()- d);
        }
    }

    int rainAttack()
    {
        return  10 + (rainLvl * 5);
    }

    void takePotion()
    {
        healthPotions -= 1;

        setHealth(getHealth() + level * 5);
        if (getHealth() > maxHealth)
        {
            setHealth(maxHealth);
        }
        std:: cout << "Your health is now at " << getHealth() << std:: endl;
    }

    void fightNormalEnemy(Enemy& enemy)
    {
        Enemy enemy(1);

        std:: cout << "You encounter " << enemy.getName() << " with " << enemy.getHealth() << " health!\n";

        while (getHealth() > 0 && enemy.getHealth() > 0) {
            // Player's turn
            playerTurn(enemy);

            if (!isEnemyStunned)
            {
                // Enemy's turn
                takeDamage(enemy, enemy.getDamage());
            }
            else
            {
                std:: cout << "The enemies turn was skipped\n";
            }
            std :: cout << "Your health is " << getHealth() << " / " << maxHealth 
             << "Enemy's health: " << enemy.getHealth() << std:: endl;
        }

        if (getHealth() <= 0) {
            // Game over logic
            std::cout << "You were defeated! Game Over.\n";

        }
        else {
            // Victory logic
            std::cout << "You defeated the enemy!\n";
            std:: cout << "You gained " << enemy.giveEXP() << "Experience\n";
            isEnemyStunned = false;
            exp += enemy.giveEXP();
            //checkForLevelUp();
        }
    }

};