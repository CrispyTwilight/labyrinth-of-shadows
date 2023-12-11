//Auth: William Brickner
//Date: 11/30/23
//Desc: Creating the subclass ranger for the player.
#pragma once
// #include "All_Includes.h"
// JPO: Temp fix for the issue with the compiler not finding the files
#include "Character.h"
#include "Enemy.h"
#include "easyEnemy.h"
#include "Boss.h"
#include "Inventory.h"


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
    Dice d100;
    Inventory* playerInventory;

public:
    Ranger()
    {
       
        maxHealth = 25;
        //This is a placeholder because the playername
        setName("Ranger");
        setHealth(25);
        strength = 7;
        intelligence = 3;
        dexterity = 4;
        level = 1;
        numberTurns = 1;
        healthPotions = 1;
        exp = 0;
        expNeeded = 5;
        rainLvl = 1;
        chargedLvl = 1;
        repulsionLvl = 1;
        // Since this an combat ability it will only be able to activated during combat so it starts off false
        isRepulsionActivated = false;
        isBlocking = false;
        isStunned = false;
        isEnemyStunned = false;
        rainCooldown = 0;
        chargedCooldown = 0;
        repulsionUses = repulsionLvl;
        d100.setMin(1);
        d100.setMax(100);
       

    }
    Ranger(int max, int hea, int  str, int intel, int  dex, int lev, int ex, int need, int rai, int charg, int re, int potion, int turns) : playerInventory(getInventory())
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
        d100.setMin(1);
        d100.setMax(100);
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
        cout << "Congratulations you leveled up!";
        // Increasing the players max health and healing them to full.
        maxHealth += 5;
        setHealth(maxHealth);
        dexterity += 1;
        level += 1;
        if (level % 5 == 0) {
            // Increment the number of turns when the player's level is a multiple of 5
            numberTurns++;
            cout << "Congratulations! Your number of turns has increased to: " << numberTurns << endl;
        }

        expNeeded = level * 5;
        exp = expNeeded - exp;

        int choice;

        // Displaying the level up message
            cout << "What Spell would you like to level up\n"
            << "Rain of Arrows per level will do an additional 5 damage. Starts with doing 10 damage.\n"
            << "Charged Shot for the first unlock will allow the Ranger to stun their enemy for a turn.  \n"
            << "Then every upgrade after that increases the number of turns per stun. Then the cooldown will increase a turn by one as well.\n"
            << "Repulsion will reflect the next damage that is taken back at the opponent base can only be used once per a fight.\n"
            << "But every level after number one you can use it an additional time per combat\n"
            << "1. Rain of Arrows " << rainLvl << endl
            << "2. Charged Shot " << chargedLvl << endl
            << "3. Repulsion " << repulsionLvl << endl;

        do {
            cout << "Enter your choice: \n";
            // Here is the use of getch.
            choice = _getch() - '0';
            if (choice < 0 || choice > 3) {
                cout << "Incorrect value. Please enter a valid value.\n";
            }
        } while (choice < 0 || choice > 3);

        switch (choice)
        {
            case 1:
            {
                rainLvl += 1;
                cout << "Rain of Arrows is now level " << rainLvl << endl;
                break;
            }
            case 2:
            {
                chargedLvl += 1;
                cout << "Charged Shot is now level " << chargedLvl << endl;
                break;
            }
            case 3:
            {
                repulsionLvl += 1;
                cout << "Repulsion is now level " << repulsionLvl << endl;
                break;
            }
            default:
            {
                cout << "Incorrect value. Please eneter a valid value.\n";
                break;
            }
        }

        system("pause");
        system("cls");
        //Checking for a level up.
        if (checkForLevelUp(exp, expNeeded))
        {
            levelUp();
        }
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
                   cout << "It's your turn, what would you like to do?\n"
                    << "1. Basic Attack\n"
                    << "2. Block\n"
                    << "3. Take Health Potion\n"
                    << "4. Rain of Arrows\n"
                    << "5. Charged Shot\n"
                    << "6. Repulsion\n" << endl;


                   bool incorrectChoice = false;
                do
                {
                    incorrectChoice = false;
                    cout << "Enter your choice: \n";
                    choice = _getch() - '0';

                    if (choice == 3 && healthPotions < 0) {
                        cout << "You are out of health potions, pick another option.\n";
                        incorrectChoice = true;
                    }
                    else if (choice == 3 && getHealth() == maxHealth) {
                        cout << "You are full on health. I highly recommend you do something else.\n";
                        incorrectChoice = true;
                    }
                    else if (choice == 4 && rainCooldown > 0) {
                        cout << "Rain of Arrows is still on cooldown. You have to wait " << rainCooldown << " number of turns.\n";
                        incorrectChoice = true;
                    }
                    else if (choice == 5 && chargedCooldown > 0) {
                        cout << "Charged shot is still on cooldown. You have to wait " << chargedCooldown << " number of turns.\n";
                        incorrectChoice = true;
                    }
                    else if (choice < 0 || choice > 5) {
                        cout << "Incorrect value. Please enter a valid value.\n";
                        incorrectChoice = true;
                    }

                } while (choice > 6 || choice < 0 || incorrectChoice);


                switch (choice)
                {
                case 1:
                {
                    cout << "You did a basic attack\n";
                    // attack monster
                    attackMonster(enemy, playerInventory->getEquippedWeaponDamage());
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
                    cout << "You used Rain of Arrows\n";
                    // Rain of arrows
                    attackMonster(enemy, rainAttack());
                    rainCooldown = 3;
                    break;
                }
                case 5:
                {
                    cout << " You used Charged Shot\n";
                    // Charged Shot
                    isEnemyStunned = true;
                    chargedCooldown = chargedLvl + 1;
                    break;
                }
                case 6:
                {
                    cout << "You activated Repulsion\n";
                    //Repulsion Activates
                    isRepulsionActivated = true;
                    break;
                }
                default:
                {
                    cout << "You put in an incorrect value please try again\n";
                }
                }
            }
        }
        if (isStunned)
        {
            cout << "You turn has been skipped!\n";
        }
    }

    // Player for the easy enemy
    void playerTurnEasy(easyEnemy& easyEnemy)
    {
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
        int choice = 0;
        // Dex + Bow damage
        if (chargedCooldown == 1)
        {
            isEnemyStunned = false;
        }
        if (!isStunned)
        {

            for (int turn = 1; turn <= numberTurns; ++turn)
            {
                cout << "It's your turn, what would you like to do?\n";
                cout << "1. Basic Attack\n"
                    << "2. Block\n"
                    << "3. Take Health Potion\n"
                    << "4. Rain of Arrows\n"
                    << "5. Charged Shot\n"
                    << "6. Repulsion\n" << endl;




                bool incorrectChoice = false;
                do
                {
                    incorrectChoice = false;
                    cout << "Enter your choice: \n";

                    choice = _getch() - '0';

                    if (choice == 3 && healthPotions < 0) {
                        cout << "You are out of health potions, pick another option.\n";
                        incorrectChoice = true;
                    }
                    else if (choice == 3 && getHealth() == maxHealth) {
                        cout << "You are full on health. I highly recommend you do something else.\n";
                        incorrectChoice = true;
                    }
                    else if (choice == 4 && rainCooldown > 0) {
                        cout << "Rain of Arrows is still on cooldown. You have to wait " << rainCooldown << " number of turns.\n";
                        incorrectChoice = true;
                    }
                    else if (choice == 5 && chargedCooldown > 0) {
                        cout << "Charged shot is still on cooldown. You have to wait " << chargedCooldown << " number of turns.\n";
                        incorrectChoice = true;
                    }
                    else if (choice < 0 || choice > 5) {
                        cout << "Incorrect value. Please enter a valid value.\n";
                        incorrectChoice = true;
                    }

                } while (choice > 6 || choice < 0 || incorrectChoice);


                switch (choice)
                {
                case 1:
                {

                    // attack monster
                    cout << "You did a basic attack\n";
                    attackMonsterEasy(easyEnemy, playerInventory->getEquippedWeaponDamage());
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
                    // Rain of arrows
                    cout << "You used Rain of Arrows\n";
                    attackMonsterEasy(easyEnemy, rainAttack());
                    rainCooldown = 3;
                    break;
                }
                case 5:
                {
                    // Charged Shot
                    cout << " You used Charged Shot\n";
                    isEnemyStunned = true;
                    chargedCooldown = chargedLvl + 1;
                    break;
                }
                case 6:
                {
                    //Repulsion Activates
                    cout << "You activated Repulsion\n";
                    isRepulsionActivated = true;
                    break;
                }
                default:
                {
                    cout << "You have encountered an error\n";
                    break;
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
    void playerTurnBoss(Boss& boss)
    {
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
        int choice = 0;
        // Dex + Bow damage
        if (chargedCooldown == 1)
        {
            isEnemyStunned = false;
        }
        if (!isStunned)
        {

            for (int turn = 1; turn <= numberTurns; ++turn)
            {
                cout << "It's your turn, what would you like to do?\n"
                     << "1. Basic Attack\n"
                    << "2. Block\n"
                    << "3. Take Health Potion\n"
                    << "4. Rain of Arrows\n"
                    << "5. Charged Shot\n"
                    << "6. Repulsion\n " << endl << endl;



                bool incorrectChoice = false;
                do
                {
                    incorrectChoice = false;
                    cout << "Enter your choice: \n";
                    choice = _getch() - '0';

                    if (choice == 3 && healthPotions < 0) {
                        cout << "You are out of health potions, pick another option.\n";
                        incorrectChoice = true;
                    }
                    else if (choice == 3 && getHealth() == maxHealth) {
                        cout << "You are full on health. I highly recommend you do something else.\n";
                        incorrectChoice = true;
                    }
                    else if (choice == 4 && rainCooldown > 0) {
                        cout << "Rain of Arrows is still on cooldown. You have to wait " << rainCooldown << " number of turns.\n";
                        incorrectChoice = true;
                    }
                    else if (choice == 5 && chargedCooldown > 0) {
                        cout << "Charged shot is still on cooldown. You have to wait " << chargedCooldown << " number of turns.\n";
                        incorrectChoice = true;
                    }
                    else if (choice < 0 || choice > 5) {
                        cout << "Incorrect value. Please enter a valid value.\n";
                        incorrectChoice = true;
                    }

                } while (choice > 6 || choice < 0 || incorrectChoice);


                switch (choice)
                {
                case 1:
                {

                    // attack monster
                    cout << "You did a basic attack\n";
                    attackMonsterBoss(boss, playerInventory->getEquippedWeaponDamage());
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
                    // Rain of arrows
                    cout << "You used Rain of Arrows\n";
                    attackMonsterBoss(boss, rainAttack());
                    rainCooldown = 3;
                    break;
                }
                case 5:
                {
                    cout << " You used Charged Shot\n";
                    // Charged Shot
                    isEnemyStunned = true;
                    chargedCooldown = chargedLvl + 1;
                    break;
                }
                case 6:
                {
                    cout << "You activated Repulsion\n";
                    //Repulsion Activates
                    isRepulsionActivated = true;
                    break;
                }
                default:
                {
                    cout << "You have encountered an error\n";
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
    void takeDamageEasyEnemy(easyEnemy& easyEnemy, int d)
    {
        int enemyAttack = d100.rollDice();

        if (isBlocking)
        {
            cout << "You successfully blocked the attack!\n";
        }
        else if (isRepulsionActivated)
        {
            cout << "You used Repulsion\n";
            attackMonsterEasy(easyEnemy, d);
        }
        else if (enemyAttack <= dexterity)
        {
            cout << "You dodged the attack!\n";
        }
        else
        {
            d = d - playerInventory->getTotalEquippedDefense();
            if (d < 0)
            {
                d = 0;
            }
            cout << "You took " << d << " damage\n";
            setHealth(getHealth()-d);
        }
    }

    // Taking damage from a normal enemy.
    void takeDamageBoss(Boss& boss, int d)
    {
        // Getting a random number and seeing if the players dex is higher and if it is they will dodge the attack.
        int enemyAttack = d100.rollDice();

        if (isBlocking)
        {
            cout << "You successfully blocked the attack!\n";
        }
        else if (isRepulsionActivated)
        {
            cout << "You used Repulsion";
            attackMonsterBoss(boss, d);
            isRepulsionActivated = false;
        }
        else if (enemyAttack <= dexterity)
        {
            cout << "You dodged the attack!\n";
        }
        else
        {
            d = d - playerInventory->getTotalEquippedDefense();
            if (d < 0)
            {
                d = 0;
            }
            cout << "You took " << d << " damage\n";
            setHealth(getHealth() - d);
        }
    }

    // Taking damage from a normal enemy.
    void takeDamage(Enemy& enemy, int d)
    {
        // Getting a random number and seeing if the players dex is higher and if it is they will dodge the attack.
        int enemyAttack = d100.rollDice();

        if (isBlocking)
        {
           cout << "You successfully blocked the attack!\n";
        }
        else if (isRepulsionActivated)
        {
            cout << "You used Repulsion";
            attackMonster(enemy, d);
        }
        else if (enemyAttack <= dexterity)
        {
            cout << "You dodged the attack!\n";
        }
        else
        {
            d = d - playerInventory->getTotalEquippedDefense();
            if (d < 0)
            {
                d = 0;
            }
            cout << "You took " << d << " damage\n";
            setHealth(getHealth()- d);
        }
    }

    //calculating the damage from a rain of arrows attack.
    int rainAttack()
    {
        return  10 + (rainLvl * 5);
    }

    //Taking a health potion
    // We should also find a way for them to be used if their in their inventory.
    void takePotion()
    {
        //Removing health potion from their inventory. When the inventory is fully setup we will remove it from the inventory class instead.
        healthPotions -= 1;
        //Setting their current health to a higher one.
        setHealth(getHealth() + level * 5);

        // If their health after taking the health potion is higher than their max set their health to their max instead.
        if (getHealth() > maxHealth)
        {
            setHealth(maxHealth);
        }
        // Confirming for their players so they know they took a health potion.
        cout << "Your health is now at " << getHealth() << endl;
    }

    void fightNormalEnemy(Enemy& enemy)
    {
        cout << "You encounter " << enemy.getName() << " with " << enemy.getHealth() << " health!\n";

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
                cout << "The enemies turn was skipped\n";
            }
            cout << "Your health is " << getHealth() << " / " << maxHealth << endl
                << "Rain of Arrows cooldown " << rainCooldown << endl
                << "Charged Shot cooldown " << chargedCooldown << endl
                << "Repulsion uses remaining " << repulsionUses << endl
                << "Enemy's health: " << enemy.getHealth() << endl;
            system("pause");
            system("cls");
        }

        if (getHealth() <= 0) {
            // Game over logic
            cout << "You were defeated! Game Over.\n";
            

        }
        else {
            // Victory logic
            cout << "You defeated the enemy!\n";
            cout << "You gained " << enemy.giveEXP() << "Experience\n";
            isEnemyStunned = false;
            //currently fights just give out health potions but later will be drawn from the loot pool and added to their inventory.
            healthPotions++;
            exp += enemy.giveEXP();
            system("pause");
            if (checkForLevelUp(exp, expNeeded))
            {
                levelUp();
            }
        }
    }

    // Fighting for the boss enemy.
    void fightBossEnemy(Boss& boss)
    {
        int turnCount = 0;
        cout << "You encounter " << boss.getName() << " with " << boss.getHealth() << " health!\n";

        while (getHealth() > 0 && boss.getHealth() > 0) {
            // Player's turn
            playerTurnBoss(boss);

            turnCount++;

            if (!isEnemyStunned)
            {
                // Enemy's turn
                if (turnCount % 2 != 0)
                {
                    takeDamageBoss(boss, boss.getDamage());
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
            cout << "Your health is " << getHealth() << " / " << maxHealth << endl
                << "Rain of Arrows cooldown " << rainCooldown << endl
                << "Charged Shot cooldown " << chargedCooldown << endl
                << "Repulsion uses remaining " << repulsionUses << endl
                << "Boss's health: " << boss.getHealth() << endl;
            system("pause");
            system("cls");
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
            //currently fights just give out health potions but later will be drawn from the loot pool and added to their inventory.
            healthPotions++;
            exp += boss.giveEXP();
            system("pause");
            //Checking if they can level up.
            if (checkForLevelUp(exp, expNeeded))
            {
                levelUp();
            }
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

            cout << "Your health is " << getHealth() << " / " << maxHealth << endl
                << "Rain of Arrows cooldown " << rainCooldown << endl
                << "Charged Shot cooldown " << chargedCooldown << endl
                << "Repulsion uses remaining " << repulsionUses << endl
                << "Enemy's health: " << easyEnemy.getHealth() << endl;
            system("pause");
            system("cls");
        }

        if (getHealth() <= 0) {
            cout << "You were defeated! Game Over.\n";
            // Game over logic
        }
        else {
            cout << "You defeated the enemy!\n";
            exp += easyEnemy.giveEXP();
            isEnemyStunned = false;
            //currently fights just give out health potions but later will be drawn from the loot pool and added to their inventory.
            healthPotions++;
            system("pause");
            //Checking for the level up after the fight is over and they have they are not dead.
            if (checkForLevelUp(exp, expNeeded))
            {
                levelUp();
            }
        }
    }
};