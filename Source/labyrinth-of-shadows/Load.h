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
    void loadTheGameRanger(int &score, int &round, Ranger &playerRanger)
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

        loadInventory("ranger_inventory.txt");
    }

    void loadTheGameWizard(int &score, int &round, Wizard &playerWizard)
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

        loadInventory("wizard_inventory.txt");
	}

    void loadTheGameRogue(int& score, int& round, Rogue& playerRogue)
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

        loadInventory("rogue_inventory.txt");

    }

    void loadInventory(const string& filename) {
        Inventory& playerInventory = *Inventory::getInstance();
        ifstream inFile(filename);
        if (inFile.is_open()) {
            string line;

            while (getline(inFile, line)) {
                istringstream iss(line);
                string itemType;
                iss >> itemType;

                if (itemType == "EquippedArmor") {
                    string type, material, name;
                    int defense, weight, value;
                    getline(inFile, type);
                    inFile >> defense >> weight >> value >> name >> material;

                    Armor* equippedArmor = new Armor(type, defense, weight, value, name, material);
                    playerInventory.setEquippedArmorByType(equippedArmor->getArmorType(), equippedArmor);
                    playerInventory.addItem(equippedArmor);
                }
                else if (itemType == "EquippedWeapon") {
                    string type, material, name;
                    int damage, weight, value;
                    getline(inFile, type);
                    inFile >> damage >> weight >> value >> name >> material;

                    Weapon* equippedWeapon = new Weapon(type, damage, weight, value, name, material);
                    playerInventory.setEquippedWeapon(equippedWeapon);
                    playerInventory.addItem(equippedWeapon);
                }
                else if (itemType == "Gold") {
                    int gold;
                    inFile >> gold;
                    playerInventory.setGold(gold);
                }
                else if (itemType == "Armor") {
                    string type, material, name;
                    int defense, weight, value;
                    getline(inFile, type);
                    inFile >> defense >> weight >> value >> name >> material;

                    Armor* newArmor = new Armor(type, defense, weight, value, name, material);
                    playerInventory.addItem(newArmor);
                }
                else if (itemType == "Weapon") {
                    string type, material, name;
                    int damage, weight, value;
                    getline(inFile, type);
                    inFile >> damage >> weight >> value >> name >> material;

                    Weapon* newWeapon = new Weapon(type, damage, weight, value, name, material);
                    playerInventory.addItem(newWeapon);
                }
                // Handle other item types similarly
            }

            cout << "Inventory details loaded from " << filename << endl;
        }
        else {
            cout << "Unable to open the file for loading inventory details\n";
        }

        inFile.close();
    }
};