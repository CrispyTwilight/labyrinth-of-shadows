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

// Before These are truly finished I need to see the inventory needs to be finished
class Save
{
public:
    // Default Constructor
	Save()
	{}

    void saveTheGameRanger(int round, int score, Ranger playerRanger)
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
        }
        else {
            cout << "Unable to open the file for saving!" << endl;
        }

        outFile.close();
    }

    void saveTheGameWizard(int round, int score, Wizard playerWizard)
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
        }
        else {
            cout << "Unable to open the file for saving!" << endl;
        }

        outFile.close();
	}

    void saveTheGameRogue(int round, int score, Rogue playerRogue)
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
        }
        else {
            cout << "Unable to open the file for saving!" << endl;
        }

        outFile.close();
    }
};