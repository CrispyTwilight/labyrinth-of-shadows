// Auth: Christian A. Botos, John O'Neal
// Date: 12/07/2023
// Desc: This is the file that holds Item names and materials.
#pragma once
#include "All_Includes.h"

class Item {
public:
    // These are static because they are the same for all instances of the struct.
    inline static vector<string> possibleWeaponNames = {
        "Reaper",
        "Shadowstrike",
        "Celestial Fury",
        "Thunderclaw",
        "Moonbeam",
        "Soulrender",
        "Blazebringer",
        "Soulreaper",
        "Omega",
        "Oblivion",
    };

    inline static vector<string> possibleWeaponMaterials = {
        "Ironwood",
        "Alloy",
        "Starlight Silver",
        "Damascus Steel",
        "Mithril",
        "Titanium",
        "Silver",
        "Bronze",
        "Iron",
        "Steel",
    };

    inline static vector<string> possibleArmorNames = {
        "Champion's Ward",
        "Elder's Guard",
        "Ender's Gear",
        "Guardian's Ward",
        "Soulward",
        "Aegis",
        "Elven Garb",
        "Mage's Robes",
        "Warrior's Garments",
        "Divine Protector",
    };

    inline static vector<string> possibleArmorMaterials = {
         "Cloth",
        "Leather",
        "Steel",
        "Iron",
        "Chainmail",
        "Bronze",
        "Silver",
        "Alloy",
        "Mithril",
        "Titanium",
    };

    inline static vector<string> possiblePotionNames = {
        "Blue Potion",
        "Red Potion",
        "Green Potion",
        "Orange Potion",
        "Yellow Potion",
        "Purple Potion",
        "Clear Potion",
        "Unmarked Potion",
        "White Potion",
        "Black Potion",
    };

    inline static vector<string> possiblePotionMaterials = {
        "Wheatgrass",
        "Divine Blood",
        "Butterfly Wings",
        "Common Mushrooms",
        "Raven Eggs",
        "Red Flowers",
        "Falcon Eyes",
        "Sunstone Dust",
        "Corrupted Plants",
        "Eagle Feathers",
    };
};