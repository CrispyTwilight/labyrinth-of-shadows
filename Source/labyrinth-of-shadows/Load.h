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
	}

};