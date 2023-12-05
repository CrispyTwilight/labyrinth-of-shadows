#pragma once
#include <iostream>
#include <fstream>
#include "Ranger.h"
#include "Wizard.h"

// Before These are truly finished I need to see the inventory needs to be finished
class Save
{


public:
    // Default Constructor
	Save()
	{
	}

    void saveTheGameRanger(int round, int score, Ranger playerRanger)
    {

        //Saving the game incase they are a ranger
        std::ofstream outFile("ranger.txt");
        if (outFile.is_open()) {
            outFile << playerRanger.getMaxHealth() << std::endl;
            outFile << playerRanger.getHealth() << std::endl;
            outFile << playerRanger.getStrength() << std::endl;
            outFile << playerRanger.getIntelligence() << std::endl;
            outFile << playerRanger.getDexterity() << std::endl;
            outFile << playerRanger.getLevel() << std::endl;
            outFile << playerRanger.getNumTurns() << std::endl;
            outFile << playerRanger.getHealthPotions() << std::endl;
            outFile << playerRanger.getExp() << std::endl;
            outFile << playerRanger.getExpNeeded() << std::endl;
            outFile << playerRanger.getRainLvl() << std::endl;
            outFile << playerRanger.getChargedLvl() << std::endl;
            outFile << playerRanger.getRepulsionLvl() << std::endl;
            outFile << score << std::endl;
            outFile << round << std::endl;


            std::cout << "Character saved successfully!" << std::endl;
        }
        else {
            std::cout << "Unable to open the file for saving!" << std::endl;
        }

        outFile.close();

        // Saving the game if they are a wizard


    }
    void saveTheGameWizard(int round, int score, Wizard playerWizard)
    {
            std::ofstream outFile("wizard.txt");
            if (outFile.is_open())
            {
                outFile << playerWizard.getMaxHealth() << std::endl;
                outFile << playerWizard.getHealth() << std::endl;
                outFile << playerWizard.getStrength() << std::endl;
                outFile << playerWizard.getIntelligence() << std::endl;
                outFile << playerWizard.getDexterity() << std::endl;
                outFile << playerWizard.getLevel() << std::endl;
                outFile << playerWizard.getNumturns() << std::endl;
                outFile << playerWizard.getHealthPotions() << std::endl;
                outFile << playerWizard.getExp() << std::endl;
                outFile << playerWizard.getExpNeeded() << std::endl;
                outFile << playerWizard.getFireball() << std::endl;
                outFile << playerWizard.getIceWall() << std::endl;
                outFile << score << std::endl;
                outFile << round << std::endl;

                std::cout << "Character saved successfully!" << std::endl;
            }
            else {
                std::cout << "Unable to open the file for saving!" << std::endl;
            }
            outFile.close();
	}

};

