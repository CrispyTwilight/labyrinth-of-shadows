#pragma once
#include <iostream>
#include <string>
#include "Armor.h"
#include "Item.h"
#include "Weapon.h"
using namespace std;

struct InventoryLoadFile
{
    int healthPotion;
    string armorType;
    int defense, weight, value; // Add more fields as per your Armor structure
    string weaponType;
    string material, materialW;
    int damage, weightW, valueW; // Add more fields as per your Weapon structure
    int gold;
};

