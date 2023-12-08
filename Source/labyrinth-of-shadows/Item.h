// Auth: John O'Neal
// Date: 12/07/2023
// Desc: Item class is a base class for all items in the game.
#pragma once
#include "All_Includes.h"

class Item {
public:
    // These are static because they are the same for all instances of the struct.
    inline static vector<string> possibleNames = {
        "Reaper",
        "Shadowstrike",
        "Celestial Fury",
        "Thunderclaw",
        "Moonbeam",
        "Abyssal Edge",
        "Soulrender",
        "Blazebringer",
        "Riftblade",
        "Doomblade",
        "Soulslayer",
        "Soulreaper",
        "Frostbite",
        "Skullcrusher",
        "The End",
        "Omega",
        "The Void",
        "Eclipse",
        "Stormbreaker",
        "Netherbane",
    };

    inline static vector<string> possibleMaterials = {
        "Ironwood",
        "Alloy",
        "Obsidian",
        "Dragonbone",
        "Starlight Silver",
        "Shadowsteel",
        "Crystal",
        "Damascus Steel",
        "Mithril",
        "Titanium",
        "Platinum",
        "Gold",
        "Silver",
        "Bronze",
        "Copper",
        "Tin",
        "Iron",
        "Steel",
        "Stone",
        "Wood",
        "Bone",
        "Leather",
        "Cloth",
        "Glass",
    };
};