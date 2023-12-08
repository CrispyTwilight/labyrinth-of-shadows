// Auth: Christian A. Botos, John O'Neal
// Date: 12/07/2023
// Desc: Loot structure.
#pragma once
#include "All_Includes.h"

struct Loot {
    Weapon lootWeapon;
    Armor lootArmor;
    //Potion lootPotion;
    int gold;


    // Constructor takes no arguments, overriding the default constructor
    Loot() {
        // Generate a random number between 1 and 100
        Dice lootDie(100, 1);
        int lootRoll = lootDie.rollDice();

        // 40% chance of getting some loot
        if (lootRoll <= 40) {
            // Generate a random number between 1 and 3 to determine the type of loot
            Dice typeDie(3, 1);
            int typeRoll = typeDie.rollDice();

            switch (typeRoll) {
                case 1:
                    // Generate a random weapon
                    lootWeapon = Weapon(true);
                    break;
                case 2:
                    // Generate a random armor
                    lootArmor = Armor(true);
                    break;
                case 3:
        // Generate a random potion
                    // lootPotion = Potion(true);
                    break;
                default:
                    cout << "Error: Invalid loot type roll.\n";
                    break;
            }
        }

        // Else generate a random amount of gold. This always occurs.
        Dice goldDie(50);
        gold = goldDie.rollDice();
    }
};

