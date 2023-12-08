// Auth: Christian A. Botos
// Date: 12/07/2023
// Desc: Loot structure. Can be used as a template for other structs.
#pragma once
#include "Headers.h"

struct Loot {
    Weapon weapon;
    Armor armor;
    Potion potion;

    int gold;

    // Constructor
    Loot() {
        // Generate a random weapon
        Dice typeDie(Weapon::WEAPON_TYPE_COUNT, 1);
        weapon.type = static_cast<Weapon::WeaponType>(typeDie.rollDice());

        Dice dmgDie(20, 1);
        weapon.damage = dmgDie.rollDice();

        Dice weightDie(20, 1);
        weapon.weight = weightDie.rollDice();

        Dice valueDie(20, 1);
        weapon.value = valueDie.rollDice();

        Dice nameDie(Item::possibleWeaponNames.size());
        weapon.name = Item::possibleWeaponNames[nameDie.rollDice()];

        Dice materialDie(Item::possibleWeaponMaterials.size());
        weapon.material = Item::possibleWeaponMaterials[materialDie.rollDice()];

        // Generate a random armor piece
        Dice typeDie(Armor::ARMOR_TYPE_COUNT, 1);
        armor.type = static_cast<Armor::ArmorType>(typeDie.rollDice());

        Dice dmgDie(20, 1);
        weapon.damage = dmgDie.rollDice();

        Dice weightDie(20, 1);
        armor.weight = weightDie.rollDice();

        Dice valueDie(20, 1);
        armor.value = valueDie.rollDice();

        Dice nameDie(Item::possibleArmorNames.size());
        armor.name = Item::possibleArmorNames[nameDie.rollDice()];

        Dice materialDie(Item::possibleArmorMaterials.size());
        armor.material = Item::possibleArmorMaterials[materialDie.rollDice()];

        // Generate a random potion
        Dice typeDie(Potion::POTION_TYPE_COUNT, 1);
        weapon.type = static_cast<Weapon::WeaponType>(typeDie.rollDice());

        Dice healDie(20, 1);
        potion.heal = healDie.rollDice();

        Dice weightDie(20, 1);
        potion.weight = weightDie.rollDice();

        Dice valueDie(20, 1);
        potion.value = valueDie.rollDice();

        Dice nameDie(Item::possiblePotionNames.size());
        potion.name = Item::possiblePotionNames[nameDie.rollDice()];

        Dice materialDie(Item::possiblePotionMaterials.size());
        potion.material = Item::possiblePotionMaterials[materialDie.rollDice()];

        // Generate a random amount of gold. This always occurs.
        Dice goldDie(50);
        gold = goldDie.rollDice();
    }
};

