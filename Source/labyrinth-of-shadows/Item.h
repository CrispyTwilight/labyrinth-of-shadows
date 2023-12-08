// Auth: Christian A. Botos
// Date: 12/07/2023
// Desc: This is the file that holds Item names and materials

#pragma once
#include "Headers.h"

struct Item {
    // These are for weapon names and materials and are static because they remain unchanged for all instances of the structure.
    static std::vector<std::string> possibleWeaponNames;
    static std::vector<std::string> possibleWeaponMaterials;

    // These are for armor names and materials and are static because they remain unchanged for all instances of the structure.
    static std::vector<std::string> possibleArmorNames;
    static std::vector<std::string> possibleArmorMaterials;

    // These are for potion names and materials and are static because they remain unchanged for all instances of the structure.
    static std::vector<std::string> possiblePotionNames;
    static std::vector<std::string> possiblePotionMaterials;
};

// Initialize the static fields of the Sword struct. These are vectors of strings that will be used to generate random names and materials for the sword. They can be expanded to include more names and materials without needing to change anything else. They could also be set up as parallel arrays so that a given name matches a given material.
std::vector<std::string> Item::possibleWeaponNames = {
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

std::vector<std::string> Item::possibleWeaponMaterials = {
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

std::vector<std::string> Item::possibleArmorNames = {
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

std::vector<std::string> Item::possibleArmorMaterials = {
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

std::vector<std::string> Item::possiblePotionNames = {
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

std::vector<std::string> Item::possibleArmorMaterials = {
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