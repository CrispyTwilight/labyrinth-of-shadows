//Auth: William Brickner
// Date: 12/8/23
// Desc: A Load class that will allow us to save from any where else in the program.

#pragma once
// #include "All_Includes.h"
// JPO: Temp fix for the issue with the compiler not finding the files
#include <iostream>
#include <fstream>
#include "RangerLoadFile.h"
#include "WizardLoadFile.h"
#include "RogueLoadFile.h"
#include "InventoryLoadFile.h"
#include "Inventory.h"
#include "Armor.h"
#include "Weapon.h"

using namespace std;

//Before this finished I need the inventory system to be finished.
class Load
{
private:
	//fields
	string characterSelected;

public:
    //Default Constructor
    Load()
    {

    }

    //Passing by reference in order to properly load the game for the rest of the program.
    void loadTheGameRanger(int &score, int &round, Ranger &playerRanger, Inventory& playerInventory)
    {
        ifstream inFile("ranger.txt");
        if (inFile.is_open());
        RangerLoadFile loadFile;
        inFile >> loadFile.max >> loadFile.health >> loadFile.strength >> loadFile.intelligence
            >> loadFile.dexterity >> loadFile.level >> loadFile.numTurns >> loadFile.healthPotions
            >> loadFile.exp >> loadFile.expNeed >> loadFile.rainLvl >> loadFile.chargedLvl
            >> loadFile.repulsionLvl >> loadFile.score >> loadFile.round;

        playerRanger.setMaxHealth(loadFile.max);
        playerRanger.setHealth(loadFile.health);
        playerRanger.setStrength(loadFile.strength);
        playerRanger.setIntelligence(loadFile.intelligence);
        playerRanger.setDexterity(loadFile.dexterity);
        playerRanger.setLevel(loadFile.level);
        playerRanger.setNumTurns(loadFile.numTurns);
        playerRanger.setHealthPotions(loadFile.healthPotions);
        playerRanger.setExp(loadFile.exp);
        playerRanger.setExpNeeded(loadFile.expNeed);
        playerRanger.setRainLvl(loadFile.rainLvl);
        playerRanger.setChargedLvl(loadFile.chargedLvl);
        playerRanger.setRepulsionLvl(loadFile.repulsionLvl);
        score = loadFile.score;
        round = loadFile.round;

        inFile.close();
        cout << "Character Loaded Sucessfully\n";

        loadInventory(playerInventory, "ranger_inventory.txt");
    }

    void loadTheGameWizard(int &score, int &round, Wizard &playerWizard, Inventory& playerInventory)
    {
        ifstream inFile("wizard.txt");
        if (inFile.is_open());
        WizardLoadFile loadFile;
        inFile >> loadFile.max >> loadFile.health >> loadFile.strength >> loadFile.intelligence
            >> loadFile.dexterity >> loadFile.level >> loadFile.numTurns >> loadFile.healthPotions
            >> loadFile.exp >> loadFile.expNeed >> loadFile.fireballLvl >> loadFile.iceWallLvl
            >> loadFile.score >> loadFile.round;

        playerWizard.setMaxHealth(loadFile.max);
        playerWizard.setHealth(loadFile.health);
        playerWizard.setStrength(loadFile.strength);
        playerWizard.setIntelligence(loadFile.intelligence);
        playerWizard.setDexterity(loadFile.dexterity);
        playerWizard.setLevel(loadFile.level);
        playerWizard.setNumTurns(loadFile.numTurns);
        playerWizard.setHealthPotions(loadFile.healthPotions);
        playerWizard.setExp(loadFile.exp);
        playerWizard.setExpNeeded(loadFile.expNeed);
        playerWizard.setFirballLvl(loadFile.fireballLvl);
        playerWizard.setIceWallLvl(loadFile.iceWallLvl);
        score = loadFile.score;
        round = loadFile.round;

        inFile.close();
        cout << "Character Loaded Sucessfully\n";

        loadInventory(playerInventory, "wizard_inventory.txt");
	}

    void loadTheGameRogue(int& score, int& round, Rogue& playerRogue, Inventory& playerInventory)
    {
        ifstream inFile("rogue.txt");
        if (inFile.is_open());
        RogueLoadFile loadFile;
        inFile >> loadFile.max >> loadFile.health >> loadFile.strength >> loadFile.intelligence
            >> loadFile.dexterity >> loadFile.level >> loadFile.numTurns >> loadFile.healthPotions
            >> loadFile.exp >> loadFile.expNeed >> loadFile.dodgeLvl >> loadFile.sneakAttackLvl
            >> loadFile.score >> loadFile.round;

        playerRogue.setMaxHealth(loadFile.max);
        playerRogue.setHealth(loadFile.health);
        playerRogue.setStrength(loadFile.strength);
        playerRogue.setIntelligence(loadFile.intelligence);
        playerRogue.setDexterity(loadFile.dexterity);
        playerRogue.setLevel(loadFile.level);
        playerRogue.setNumTurns(loadFile.numTurns);
        playerRogue.setHealthPotions(loadFile.healthPotions);
        playerRogue.setExp(loadFile.exp);
        playerRogue.setExpNeeded(loadFile.expNeed);
        playerRogue.setDodgeLvl(loadFile.dodgeLvl);
        playerRogue.setSneakAttackLvl(loadFile.sneakAttackLvl);
        score = loadFile.score;
        round = loadFile.round;

        inFile.close();
        cout << "Character Loaded Sucessfully\n";

        loadInventory(playerInventory, "rogue_inventory.txt");

    }

    void loadInventory(Inventory& playerInventory, const string& filename) {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            InventoryLoadFile loadFile;
            string itemType, itemName;

            while (inFile >> itemType >> itemName) {
                if (itemType == "HealthPotion") {
                    inFile >> loadFile.healthPotion;
                    playerInventory.setHealthPotion(loadFile.healthPotion);
                }
                else if (itemType == "EquippedArmor") {
                    inFile >> loadFile.type >> loadFile.defense >> loadFile.weight >> loadFile.value >> loadFile.material;
                    Armor* equippedArmor = new Armor(loadFile.type, loadFile.defense, loadFile.weight, loadFile.value, itemName, loadFile.material);
                    playerInventory.setEquippedArmorByType(equippedArmor->getArmorType(), equippedArmor);
                    delete equippedArmor;
                }

                else if (itemType == "EquippedWeapon") {
                    inFile >> loadFile.wType >> loadFile.damage >> loadFile.weightW >> loadFile.valueW >> loadFile.materialW;
                    Weapon* equippedWeapon = new Weapon(loadFile.wType, loadFile.damage, loadFile.weightW, loadFile.valueW, itemName, loadFile.materialW);
                    playerInventory.setEquippedWeapon(equippedWeapon);\
                    delete equippedWeapon;
                }
                else if (itemType == "Gold") {
                    inFile >> loadFile.gold;
                    playerInventory.setGold(loadFile.gold);
                }
                // Add more conditions based on your saved inventory structure
            }

            cout << "Inventory details loaded from " << filename << endl;
        }
        else {
            cout << "Unable to open the file for loading inventory details\n";
        }

        inFile.close();
    }
};