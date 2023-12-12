//Auth: William Brickner
// Date: 12/8/23
// Desc: A save class that will allow us to save from any where else in the program.
#pragma once
// #include "All_Includes.h"
// JPO: Temp fix for the issue with the compiler not finding the files
#include <iostream>
#include <fstream>
#include "Ranger.h"
#include "Wizard.h"
#include "Rogue.h"
#include "Inventory.h"
#include "Armor.h"
#include "Weapon.h"
// Before These are truly finished I need to see the inventory needs to be finished
class Save
{
public:
    // Default Constructor
	Save()
	{}

    void saveTheGameRanger(int round, int score, Ranger& playerRanger)
    {
        //Saving the game if they are a ranger
        ofstream outFile("ranger.txt");
        if (outFile.is_open()) {
            outFile << playerRanger.getMaxHealth() << endl;
            outFile << playerRanger.getHealth() << endl;
            outFile << playerRanger.getStrength() << endl;
            outFile << playerRanger.getIntelligence() << endl;
            outFile << playerRanger.getDexterity() << endl;
            outFile << playerRanger.getLevel() << endl;
            outFile << playerRanger.getNumTurns() << endl;
            outFile << playerRanger.getHealthPotions() << endl;
            outFile << playerRanger.getExp() << endl;
            outFile << playerRanger.getExpNeeded() << endl;
            outFile << playerRanger.getRainLvl() << endl;
            outFile << playerRanger.getChargedLvl() << endl;
            outFile << playerRanger.getRepulsionLvl() << endl;
            outFile << score << endl;
            outFile << round << endl;

            cout << "Character saved successfully!" << endl;
            saveInventory("ranger_inventory.txt");
        }
        else {
            cout << "Unable to open the file for saving!" << endl;
        }

        outFile.close();
    }

    void saveTheGameWizard(int round, int score, Wizard& playerWizard)
    {
        // Saving the game if they are a wizard
        ofstream outFile("wizard.txt");
        if (outFile.is_open())
        {
            outFile << playerWizard.getMaxHealth() << endl;
            outFile << playerWizard.getHealth() << endl;
            outFile << playerWizard.getStrength() << endl;
            outFile << playerWizard.getIntelligence() << endl;
            outFile << playerWizard.getDexterity() << endl;
            outFile << playerWizard.getLevel() << endl;
            outFile << playerWizard.getNumturns() << endl;
            outFile << playerWizard.getHealthPotions() << endl;
            outFile << playerWizard.getExp() << endl;
            outFile << playerWizard.getExpNeeded() << endl;
            outFile << playerWizard.getFireball() << endl;
            outFile << playerWizard.getIceWall() << endl;
            outFile << score << endl;
            outFile << round << endl;

            cout << "Character saved successfully!" << endl;
            saveInventory("wizard_inventory.txt");
        }
        else {
            cout << "Unable to open the file for saving!" << endl;
        }

        outFile.close();
	}

    void saveTheGameRogue(int& round, int& score, Rogue& playerRogue)
    {
        //Saving the game if they are a rogue
        ofstream outFile("rogue.txt");
        if (outFile.is_open()) {
            outFile << playerRogue.getMaxHealth() << endl;
            outFile << playerRogue.getHealth() << endl;
            outFile << playerRogue.getStrength() << endl;
            outFile << playerRogue.getIntelligence() << endl;
            outFile << playerRogue.getDexterity() << endl;
            outFile << playerRogue.getLevel() << endl;
            outFile << playerRogue.getNumTurns() << endl;
            outFile << playerRogue.getHealthPotions() << endl;
            outFile << playerRogue.getExp() << endl;
            outFile << playerRogue.getExpNeeded() << endl;
            outFile << playerRogue.getSneakAttackLvl() << endl;
            outFile << playerRogue.getDodgeLvl() << endl;
            outFile << score << endl;
            outFile << round << endl;

            cout << "Character saved successfully!" << endl;
            saveInventory("rogue_inventory.txt");
        }
        else {
            cout << "Unable to open the file for saving!" << endl;
        }

        outFile.close();
    }
    void saveInventory(const string& filename) const {
        const Inventory& playerInventory = *Inventory::getInstance();
        ofstream outFile(filename);

        if (outFile.is_open()) {
            // Save health potion count
            // outFile << "HealthPotion," << playerInventory.getHealthPotion() << "\n"; JPO: We need to save the Items, health potions are one time use.

            // Save equipped armor details
            for (const auto& armorSlot : playerInventory.getEquippedArmorSlots()) {
                Armor* equippedArmor = armorSlot.second;
                if (equippedArmor) {
                    outFile << "EquippedArmor" << endl << armorTypeToString(armorSlot.first) << endl
                        << equippedArmor->defense << endl << equippedArmor->weight << endl
                        << equippedArmor->value << endl << equippedArmor->name << endl
                        << equippedArmor->material << "\n";
                }
            }

            // Save equipped weapon details
            Weapon* equippedWeapon = playerInventory.getEquippedWeapon();
            if (equippedWeapon) {
                outFile << "EquippedWeapon" << endl << weaponTypeToString(equippedWeapon->type) << endl
                    << equippedWeapon->damage << endl << equippedWeapon->weight << endl
                    << equippedWeapon->value << endl << equippedWeapon->name << endl
                    << equippedWeapon->material << "\n";
            }

            // Save gold
            outFile << "Gold" << endl << playerInventory.getGold() << endl;

            // Save individual items
            const vector<Item*>& items = playerInventory.getItems();
            for (const Item* item : items) {
                if (const Armor* armorItem = dynamic_cast<const Armor*>(item)) {
                    // This is an Armor item
                    outFile << "Armor" << endl << armorTypeToString(armorItem->type) << endl
                        << armorItem->defense << endl << armorItem->weight << endl
                        << armorItem->value << endl << armorItem->name << endl
                        << armorItem->material << endl;
                }
                else if (const Weapon* weaponItem = dynamic_cast<const Weapon*>(item)) {
                    // This is a Weapon item
                    outFile << "Weapon" << endl <<  weaponTypeToString(weaponItem->type) << endl
                        << weaponItem->damage << endl << weaponItem->weight << endl
                        << weaponItem->value << endl << weaponItem->name << endl
                        << weaponItem->material << endl;
                }
            }
            cout << "Inventory details saved to " << filename << endl;
        }
        else {
            cout << "Unable to open the file for saving inventory details\n";
        }
        outFile.close();
    }
};