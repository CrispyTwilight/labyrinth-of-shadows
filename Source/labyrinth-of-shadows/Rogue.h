//Auth: Hunter Kauffman
//Date: 12/5/23
//Desc: Creating the subclass Rogue for the player.
#pragma once
// #include "All_Includes.h"
// JPO: Temp fix for the issue with the compiler not finding the files
#include "Character.h"
#include "Enemy.h"
#include "easyEnemy.h"
#include "Boss.h"
#include "Dice.h"
#include "Inventory.h"

class Rogue : public Character
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
    int sneakAttackLvl;
    int dodgeLvl;
    int numberTurns;
    int sneakAttackCooldown;
    int dodgeCooldown;
    bool isDodgingActivated;
    bool isBlocking;
    bool isStunned;
    bool isEnemyStunned;
    
    Dice d100;

public:
    Rogue()
    {

    }
    Rogue(int max, int hea, int  str, int intel, int  dex, int lev, int ex, int need, int sa, int dodge, int potion, int turns)
    {
        maxHealth = max;
        //This is a placeholder because the playername
        setName("Rogue");
        setHealth(hea);
        strength = str;
        intelligence = intel;
        dexterity = dex;
        level = lev;
        numberTurns = turns;
        healthPotions = potion;
        exp = ex;
        expNeeded = need;
        sneakAttackLvl = sa;
        dodgeLvl = dodge;
        // Since this an combat ability it will only be able to activated during combat so it starts off false
        isDodgingActivated = false;
        isBlocking = false;
        isStunned = false;
        isEnemyStunned = false;
        sneakAttackCooldown = 0;
        dodgeCooldown = 0;
        d100.setMax(100);
        d100.setMin(1);

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

    void setSneakAttackLvl(int sa)
    {
        sneakAttackLvl = sa;
    }

    void setDodgeLvl(int dodge)
    {
        dodgeLvl = dodge;
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

    int getSneakAttackLvl() const
    {
        return sneakAttackLvl;
    }

    int getDodgeLvl() const
    {
        return dodgeLvl;
    }

    // Leveling up the player
    void levelUp()
    {
        std::cout << "Congratulations you leveled up!";
        // Increasing the players max health and healing them to full.
        maxHealth += 5;
        setHealth(maxHealth);
        dexterity += 1;
        level += 1;
        if (level % 5 == 0) {
            // Increment the number of turns when the player's level is a multiple of 5
            numberTurns++;
            std::cout << "Congratulations! Your number of turns has increased to: " << numberTurns << endl;
        }

        expNeeded = level * 5;
        exp = expNeeded - exp;

        int choice;

        // Displaying the level up message
        cout << "What Skill would you like to level up\n"
             << "Sneak Attack per level will do an additional 5 damage. Starts with doing 5 damage.\n"
             << "Dodge for the first unlock will allow the Rogue to dodge their enemy for a turn.  \n"
             << "Then every upgrade after that increases the number of turns per dodge. Then the cooldown will increase a turn by one as well.\n"
             << "1. Sneak Attack " << sneakAttackLvl << endl
             << "2. Dodge " << dodgeLvl << endl;

        do {
            std::cout << "Enter your choice: ";
            // Here is the use of getch.
            choice = _getch() - '0';
            if (choice < 0 || choice > 2) {
                cout << "Incorrect value. Please enter a valid value.\n";
            }
        } while (choice < 0 || choice > 2);

        switch (choice)
        {
        case 1:
        {
            sneakAttackLvl += 1;
            cout << "Sneak Attack is now level " << sneakAttackLvl << endl;
            break;
        }
        case 2:
        {
            dodgeLvl += 1;
            cout << "Dodge is now level " << dodgeLvl << endl;
            break;
        }
        default:
        {
            cout << "Incorrect value. Please eneter a valid value.\n";
            break;
        }

        }
        if (checkForLevelUp(exp, expNeeded))
        {
            levelUp();
        }
    }

    //Player turn for the base enemy type
    void playerTurn(Enemy& enemy, Inventory& playerInventory)
    {
        //Setting blocking back to off at the start of their next turn.
        isBlocking = false;
        // Only lowering the cooldowns when they are above zero.
        if (sneakAttackCooldown > 0)
        {
            sneakAttackCooldown -= 1;
        }
        if (dodgeCooldown > 0)
        {
            dodgeCooldown -= 1;
        }
        // Reseting the choice variable
        int choice = 0;

        if (dodgeCooldown == 1)
        {
            isEnemyStunned = false;
        }
        // Starting the turn if the player is not stunned.
        if (!isStunned)
        {

            for (int turn = 1; turn <= numberTurns; ++turn)
            {
                cout << "It's your turn, what would you like to do?\n"
                    << "1. Basic Attack\n"
                    << "2. Block\n"
                    << "3. Take Health Potion\n"
                    << "4. Sneak Attack\n"
                    << "5. Dodge\n" << endl << endl;

                bool incorrectChoice = false;
                do {
                    incorrectChoice = false;
                    cout << "Enter your choice: ";
                    choice = _getch() - '0';

                    if (choice == 3 && healthPotions < 0) {
                        cout << "You are out of health potions, pick another option.\n";
                        incorrectChoice = true;
                    }
                    else if (choice == 3 && getHealth() == maxHealth) {
                        cout << "You are full on health. I highly recommend you do something else.\n";
                        incorrectChoice = true;
                    }
                    else if (choice == 4 && sneakAttackCooldown > 0) {
                        cout << "Sneak Attack is still on cooldown. You have to wait " << sneakAttackCooldown << " number of turns.\n";
                        incorrectChoice = true;
                    }
                    else if (choice == 5 && dodgeCooldown > 0) {
                        cout << "Dodge is still on cooldown. You have to wait " << dodgeCooldown << " number of turns.\n";
                        incorrectChoice = true;
                    }
                    else if (choice < 0 || choice > 5) {
                        cout << "Incorrect value. Please enter a valid value.\n";
                        incorrectChoice = true;
                    }

                    // Check if the choice is invalid
                    if (incorrectChoice) {
                        // The do-while loop will continue if the choice was incorrect
                        continue;
                    }

                } while (choice > 5 || choice < 0 || incorrectChoice);


                switch (choice)
                {
                    case 1:
                    {
                        cout << "You did a basic attack\n";
                        // attack monster
                        attackMonster(enemy, playerInventory.getEquippedWeaponDamage());
                        break;
                    }
                    case 2:
                    {
                        // Block attack
                        std::cout << "You have started to block\n";
                        isBlocking = true;
                        break;
                    }
                    case 3:
                    {
                        // Take Health Potion If have any
                        std::cout << "You took a health potion\n";
                        takePotion();
                        break;
                    }
                    case 4:
                    {
                        std::cout << "You used Sneak Attack\n";
                        // Rain of arrows
                        attackMonster(enemy, sneakAttack());
                        sneakAttackCooldown = 3;
                        break;
                    }
                    case 5:
                    {
                        std::cout << " You used Dodge\n";
                        // Charged Shot
                        isDodgingActivated = true;
                        dodgeCooldown = dodgeLvl + 1;
                        break;
                    }
                    default:
                    {
                        std::cout << "You put in an incorrect value please try again\n";
                    }
                }
            }
        }
        if (isStunned)
        {
            std::cout << "You turn has been skipped!\n";
        }
    }

    // Player for the easy enemy
    void playerTurnEasy(easyEnemy& easyEnemy, Inventory& playerInventory)
    {
        //Setting blocking back to off at the start of their next turn.
        isBlocking = false;
        // Only lowering the cooldowns when they are above zero.
        if (sneakAttackCooldown > 0)
        {
            sneakAttackCooldown -= 1;
        }
        if (dodgeCooldown > 0)
        {
            dodgeCooldown -= 1;
        }
        // Reseting the choice variable
        int choice = 0;

        if (dodgeCooldown == 1)
        {
            isEnemyStunned = false;
        }
        // Starting the turn if the player is not stunned.
        if (!isStunned)
        {

            for (int turn = 1; turn <= numberTurns; ++turn)
            {
                cout << "It's your turn, what would you like to do?\n"
                    << "1. Basic Attack\n"
                    << "2. Block\n"
                    << "3. Take Health Potion\n"
                    << "4. Sneak Attack\n"
                    << "5. Dodge\n" << endl << endl;


                do {
                    bool incorrectChoice = false;
                    cout << "Enter your choice: ";
                    choice = _getch();

                    if (choice == 3 && healthPotions < 0) {
                        cout << "You are out of health potions, pick another option.\n";
                        incorrectChoice = true;
                    }
                    else if (choice == 3 && getHealth() == maxHealth) {
                        cout << "You are full on health. I highly recommend you do something else.\n";
                        incorrectChoice = true;
                    }
                    else if (choice == 4 && sneakAttackCooldown > 0) {
                        cout << "Sneak Attack is still on cooldown. You have to wait " << sneakAttackCooldown << " number of turns.\n";
                        incorrectChoice = true;
                    }
                    else if (choice == 5 && dodgeCooldown > 0) {
                        cout << "Dodge is still on cooldown. You have to wait " << dodgeCooldown << " number of turns.\n";
                        incorrectChoice = true;
                    }
                    else if (choice < 0 || choice > 5) {
                        cout << "Incorrect value. Please enter a valid value.\n";
                        incorrectChoice = true;
                    }

                    // Check if the choice is invalid
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
                        cout << "You did a basic attack\n";
                        attackMonsterEasy(easyEnemy, playerInventory.getEquippedWeaponDamage());
                        break;
                    }
                    case 2:
                    {
                        // Block attack
                        cout << "You have started to block\n";
                        isBlocking = true;
                        break;
                    }
                    case 3:
                    {
                        // Take Health Potion If have any
                        cout << "You took a health potion\n";
                        takePotion();
                        break;
                    }
                    case 4:
                    {
                        // Sneak Attack
                        cout << "You used Sneak Attack\n";
                        attackMonsterEasy(easyEnemy, sneakAttack());
                        sneakAttackCooldown = 3;
                        break;
                    }
                    case 5:
                    {
                        // Dodge
                        cout << " You used Dodge\n";
                        isDodgingActivated = true;
                        dodgeCooldown = dodgeLvl + 1;
                        break;
                    }
                    default:
                    {
                        std::cout << "You put in an incorrect value please try again\n";
                    }
                }
            }

            if (isStunned)
            {
                cout << "You turn has been skipped!\n";
            }
        }
    }

    // Player turn for the boss class
    void playerTurnBoss(Boss& boss, Inventory& playerInventory)
    {
        //Setting blocking back to off at the start of their next turn.
        isBlocking = false;
        // Only lowering the cooldowns when they are above zero.
        if (sneakAttackCooldown > 0)
        {
            sneakAttackCooldown -= 1;
        }
        if (dodgeCooldown > 0)
        {
            dodgeCooldown -= 1;
        }
        // Reseting the choice variable
        int choice = 0;

        if (dodgeCooldown == 1)
        {
            isEnemyStunned = false;
        }
        // Starting the turn if the player is not stunned.
        if (!isStunned)
        {

            for (int turn = 1; turn <= numberTurns; ++turn)
            {
                cout << "It's your turn, what would you like to do?\n"
                    << "1. Basic Attack\n"
                    << "2. Block\n"
                    << "3. Take Health Potion\n"
                    << "4. Sneak Attack\n"
                    << "5. Dodge\n" << endl << endl;


                do {
                    bool incorrectChoice = false;
                    cout << "Enter your choice: ";
                    choice = _getch();

                    if (choice == 3 && healthPotions < 0) {
                        cout << "You are out of health potions, pick another option.\n";
                        incorrectChoice = true;
                    }
                    else if (choice == 3 && getHealth() == maxHealth) {
                        cout << "You are full on health. I highly recommend you do something else.\n";
                        incorrectChoice = true;
                    }
                    else if (choice == 4 && sneakAttackCooldown > 0) {
                        cout << "Sneak Attack is still on cooldown. You have to wait " << sneakAttackCooldown << " number of turns.\n";
                        incorrectChoice = true;
                    }
                    else if (choice == 5 && dodgeCooldown > 0) {
                        cout << "Dodge is still on cooldown. You have to wait " << dodgeCooldown << " number of turns.\n";
                        incorrectChoice = true;
                    }
                    else if (choice < 0 || choice > 5) {
                        cout << "Incorrect value. Please enter a valid value.\n";
                        incorrectChoice = true;
                    }

                    // Check if the choice is invalid
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
                    cout << "You did a basic attack\n";
                    attackMonsterBoss(boss, playerInventory.getEquippedWeaponDamage());
                    break;
                }
                case 2:
                {
                    // Block attack
                    cout << "You have started to block\n";
                    isBlocking = true;
                    break;
                }
                case 3:
                {
                    // Take Health Potion If have any
                    cout << "You took a health potion\n";
                    takePotion();
                    break;
                }
                case 4:
                {
                    // Sneak Attack
                    cout << "You used Sneak Attack\n";
                    attackMonsterBoss(boss, sneakAttack());
                    sneakAttackCooldown = 3;
                    break;
                }
                case 5:
                {
                    cout << " You used Dodge\n";
                    // Dodge
                    isDodgingActivated = true;
                    dodgeCooldown = dodgeLvl + 1;
                    break;
                }

                }
            }

            if (isStunned)
            {
                cout << "You turn has been skipped!\n";
                isStunned = false;
            }
        }
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

    void attackMonsterBoss(Boss& boss, int d)
    {
        boss.takeDamage(d);
        cout << boss.getName() << "took " << d << " damage.\n";
    }

    // Taking damage from the easy enemy.
    void takeDamageEasyEnemy(easyEnemy& easyEnemy, int d, Inventory& playerInventory)
    {
        int enemyAttack = d100.rollDice();

        if (isBlocking)
        {
            cout << "You successfully blocked the attack!\n";
            d = d * 0.25;
            // Assuming playerInventory.getTotalEquippedDefense() is an integer value
            d = d - playerInventory.getTotalEquippedDefense();
            if (d < 0) {
                d = 0;
            }

            // Convert the decimal damage to a whole number (rounding up)
            d = static_cast<int>(ceil(d));

            cout << "You took " << d << " damage\n";
        }
        else if (isDodgingActivated)
        {
            cout << "You Dodge the enemy and countered\n";
            attackMonsterEasy(easyEnemy, d);
            isDodgingActivated = false;
        }
        else if (enemyAttack <= dexterity)
        {
            cout << "You dodged the attack!\n";
        }
        else
        {
            d = d - playerInventory.getTotalEquippedDefense();
            if (d < 0)
            {
                d = 0;
            }
            cout << "You took " << d << " damage\n";
            setHealth(getHealth() - d);
        }
    }

    // Taking damage from a normal enemy.
    void takeDamageBoss(Boss& boss, int d, Inventory& playerInventory)
    {
        // Getting a random number and seeing if the players dex is higher and if it is they will dodge the attack.
        int enemyAttack = d100.rollDice();

        if (isBlocking)
        {
            cout << "You successfully blocked the attack!\n";
            d = d * 0.25;
            // Assuming playerInventory.getTotalEquippedDefense() is an integer value
            d = d - playerInventory.getTotalEquippedDefense();
            if (d < 0) {
                d = 0;
            }

            // Convert the decimal damage to a whole number (rounding up)
            d = static_cast<int>(ceil(d));

            cout << "You took " << d << " damage\n";
        }
        else if (isDodgingActivated)
        {
            cout << "You Dodge the enemy and countered\n";
            attackMonsterBoss(boss, d);
            isDodgingActivated = false;
        }
        else if (enemyAttack <= dexterity)
        {
            cout << "You dodged the attack!\n";
        }
        else
        {
            d = d - playerInventory.getTotalEquippedDefense();
            if (d < 0)
            {
                d = 0;
            }
            cout << "You took " << d << " damage\n";
            setHealth(getHealth() - d);
        }
    }

    // Taking damage from a normal enemy.
    void takeDamage(Enemy& enemy, int d, Inventory& playerInventory)
    {
        // Getting a random number and seeing if the players dex is higher and if it is they will dodge the attack.
        int enemyAttack = d100.rollDice();

        if (isBlocking)
        {
            cout << "You successfully blocked the attack!\n";
            d = d * 0.25;
            // Assuming playerInventory.getTotalEquippedDefense() is an integer value
            d = d - playerInventory.getTotalEquippedDefense();
            if (d < 0) {
                d = 0;
            }

            // Convert the decimal damage to a whole number (rounding up)
            d = static_cast<int>(ceil(d));

            cout << "You took " << d << " damage\n";
        }
        else if (isDodgingActivated)
        {
            cout << "You Dodge the enemy and countered\n";
            attackMonster(enemy, d);
            isDodgingActivated = false;
        }
        else if (enemyAttack <= dexterity)
        {
            std::cout << "You dodged the attack!\n";
        }
        else
        {
            d = d - playerInventory.getTotalEquippedDefense();
            if (d < 0)
            {
                d = 0;
            }
            std::cout << "You took " << d << " damage\n";
            setHealth(getHealth() - d);
        }
    }

    int sneakAttack() //Calculates the damage for Sneak Attack
    {
        if (sneakAttackLvl == 1)
        {
            return 2 * 5;
        }
        else
        {
            return 2 * (5 + (sneakAttackLvl * 5));
        }
    }

    // Taking a potion effect that scales up with their level.
    void takePotion()
    {
        healthPotions -= 1;

        setHealth(getHealth() + level * 5);
        if (getHealth() > maxHealth)
        {
            setHealth(maxHealth);
        }
        std::cout << "Your health is now at " << getHealth() << std::endl;
    }

    void fightNormalEnemy(Enemy& enemy, Inventory& playerInventory)
    {


        std::cout << "You encounter " << enemy.getName() << " with " << enemy.getHealth() << " health!\n";

        while (getHealth() > 0 && enemy.getHealth() > 0) {
            // Player's turn
            playerTurn(enemy, playerInventory);

            if (!isEnemyStunned)
            {
                // Enemy's turn
                takeDamage(enemy, enemy.getDamage(), playerInventory);
            }
            else
            {
                std::cout << "The enemies turn was skipped\n";
            }
            std::cout << "Your health is " << getHealth() << " / " << maxHealth
                << "Enemy's health: " << enemy.getHealth() << std::endl;
        }

        if (getHealth() <= 0) {
            // Game over logic
            std::cout << "You were defeated! Game Over.\n";

        }
        else {
            // Victory logic
            std::cout << "You defeated the enemy!\n";
            std::cout << "You gained " << enemy.giveEXP() << "Experience\n";
            isEnemyStunned = false;
            exp += enemy.giveEXP();
            if (checkForLevelUp(exp, expNeeded))
            {
                levelUp();
            }
        }
    }

    // Fighting for the boss enemy.
    void fightBossEnemy(Boss& boss, Inventory& playerInventory)
    {
        int turnCount = 0;
        cout << "You encounter " << boss.getName() << " with " << boss.getHealth() << " health!\n";

        while (getHealth() > 0 && boss.getHealth() > 0) {
            // Player's turn
            playerTurnBoss(boss, playerInventory);

            turnCount++;

            if (!isEnemyStunned)
            {
                // Enemy's turn
                if (turnCount % 2 != 0)
                {
                    takeDamageBoss(boss, boss.getDamage(), playerInventory);
                }
                else
                {
                    isStunned = true;
                }
            }
            else
            {
                cout << "The Bosses turn was skipped\n";
            }
            // Display updated stats after each round

            cout << "Enemy's health: " << boss.getHealth() << endl;
        }

        if (getHealth() <= 0)
        {
            // Game over logic
            cout << "You were defeated! Game Over.\n";
        }
        else
        {
            // Victory logic
            cout << "You defeated the Boss!\n";
            cout << "You gained " << boss.giveEXP() << " Experience";
            isEnemyStunned = false;
            healthPotions++;
            exp += boss.giveEXP();
            if (checkForLevelUp(exp, expNeeded))
            {
                levelUp();
            }
        }
    }

    // The function when the player has to fight a weak enemy (The first three enemies).
    void fightWeakEnemy(easyEnemy& easyEnemy, Inventory & playerInventory)
    {
        // Display the enemy's details
        cout << "You encounter " << easyEnemy.getName() << " with " << easyEnemy.getHealth() << " health!\n";

        while (getHealth() > 0 && easyEnemy.getHealth() > 0) {
            // Player's turn
            playerTurnEasy(easyEnemy, playerInventory);

            if (easyEnemy.getHealth() > 0)
            {
                // Enemy's turn
                if (!isEnemyStunned)
                {
                    takeDamageEasyEnemy(easyEnemy, easyEnemy.attack(), playerInventory);

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
            if (checkForLevelUp(exp, expNeeded))
            {
                levelUp();
            }
        }
    }
};