#pragma once
#include <iostream>
#include <string>

using namespace std;

struct InventoryLoadFile
{
    int healthPotion;
    string type;
    int defense, weight, value; // Add more fields as per your Armor structure
    string wType;
    string material, materialW;
    int damage, weightW, valueW; // Add more fields as per your Weapon structure
    int gold;
};

