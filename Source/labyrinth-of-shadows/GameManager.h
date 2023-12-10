// Date: 12/04/2023
// Auth: John O'Neal
// Desc: This class will manage the game and all of its components. Loading, ending, saving, quitting, etc. will all be handled here.
#pragma once
#include <iostream>
#include <conio.h>
#include "Character.h"
#include "Save.h"
#include "Load.h"
#include "Ranger.h"
#include "Wizard.h"
#include "Rogue.h"
#include "Enemy.h"
#include "easyEnemy.h"
#include "Boss.h"
#include "Inventory.h"
// Will need to #include all of the other classes here.

class GameManager
{
private:
    // Adding the basic fields of score and round count so that I could properly save and load the game.
    int round;
    int score;
    std::string characterSelected;
    Inventory playerInventory;
public:
    // Initializes the game, loads resources, etc.
    void init()
    {

        // Since we need to be able to quit the game immediatley but still want to save and quit to be one function
        //we need to make all of the player classes before we can continue to the other parts of the code.
        // These are the base stats for the class these are definitely are subject to change when playtesting.
        Ranger playerRanger(25, 25, 5, 5, 7, 1, 0, 5, 0, 0, 0, 0, 1);
        Wizard playerWizard(30, 30, 3, 8, 5, 1, 0, 5, 1, 1, 2, 1);
        Rogue playerRogue(40, 40, 5, 3, 6, 1, 0, 5, 0, 0, 0, 1);

        int choice;
       // Introduction will go here
        //Splash Screen goes here and Introduction

            cout << "1. Start New Game\n"
            << "2. Load Previous Game\n"
            << "0. Quit and Save the Game\n";

        do
        {
            cout << "Enter your choice: ";
            choice = _getch() - '0';
            if (choice < 0 || choice > 2)
            {
                cout << "Incorrect value. Please enter a valid value.\n";
            }
        } while (choice < 0 || choice > 2);


        switch (choice)
        {
        case 0:
        {
            Save save;
            if (characterSelected == "Ranger")
            {
                save.saveTheGameRanger(round, score, playerRanger,playerInventory);
            }
            else if (characterSelected == "Wizard")
            {
                save.saveTheGameWizard(round, score, playerWizard,playerInventory);
            }
            else if (characterSelected == "Rogue")
            {
                save.saveTheGameRogue(round, score, playerRogue, playerInventory);
            }
            else
            {
                cout << "There is no character to be saved.";
            }
            exit(0);

        }
        case 1:
        {
            choice = 0;
            cout << "Select a class to play as Ranger, Wizard, or Warrior.\n"
                << "1. Ranger (A class focused on reflecting attacks and dodging attacks while doing massive damage)\n"
                << "2. Wizard (A High Defense and High Damaging Wizard)\n"
                << "3. Rogue (A damaging Rogue that can vanish and do deadly sneak attacks\n";

            do
            {
                cout << "Enter your choice: \n";

                choice = _getch() - '0';

                if (choice < 0 || choice > 3)
                {
                    cout << "Incorrect value. Please enter a valid value.\n";
                }
            } while (choice < 0 || choice > 3);

            switch (choice)
            {
            case 1:
            {
                // Make the Ranger the currently selected class.
                characterSelected = "Ranger";
                break;
            }
            case 2:
            {
                // Make the Wizard the curren1tly selected class.
                characterSelected = "Wizard";
                break;
            }
            case 3:
            {
                characterSelected = "Rogue";
            }
            default:
            {
                "You have encountered an error.";
                break;
            }
            }
            break;
        }
        //Load the game from previous save.
        case 2:
        {
            //Creating the load object.
            Load load();
            // Reseting the choice variable back to zero.
            choice = 0;
            //Displaying the menu for the player
                cout << "What class would you like to load?\n"
                << "1. Ranger\n"
                << "2. Wizard\n"
                << "3. Rogue\n";

            //Average do-while loop.
            do
            {
                cout << "Enter your choice: ";
                choice = _getch() - '0';
                if (choice < 0 || choice > 3)
                {
                    cout << "Incorrect value. Please enter a valid value.\n";
                }


                switch (choice)
                {
                case 1:
                {
                    //Loading the previously used Ranger class.
                    load().loadTheGameRanger(score, round, playerRanger, playerInventory);
                    // Make the current class selected into the Ranger so the rest of the code will work properly.
                    characterSelected = "Ranger";
                    break;
                }
                case 2:
                {
                    //Loading the previous Wizard class.
                    load().loadTheGameWizard(score, round, playerWizard, playerInventory);
                    // Make the current class selected into the wizard for loading.
                    characterSelected = "Wizard";
                    break;
                }
                case 3:
                {
                    //Loading the game for the rogue class.
                    load().loadTheGameRogue(score, round, playerRogue, playerInventory);
                    //Making the currently selected character the rogue after loading the game.
                    characterSelected = "Rogue";
                }
                default:
                {
                    //Input validation.
                    cout << "You have entered in an incorrect value. Please try again.\n";
                    break;
                }
                }

            } while (choice < 0 || choice > 2);


        }
        default:
        {
            cout << "You have encountered an unexpected error.\n";
            
            break;
        }
       

        }
        exit(0);
    }




    // Starts the main game loop
    void start()
    {

        // We need to decide whether to display the map first or pop up a menu.

    }


    void fighting(int& round, string& characterSelected, Ranger& playerRanger, Wizard& playerWizard, Rogue& playerRogue)
    {
        if (characterSelected == "Ranger") {
            if (round < 3) {
                easyEnemy* easyEnemyPtr = new easyEnemy();
                playerRanger.fightWeakEnemy(*easyEnemyPtr);
                delete easyEnemyPtr;
                easyEnemyPtr = nullptr;

                if (playerRanger.getHealth() > 0) {
                    round++;
                    score = score + 5;
                    // This is a victory and should take them back to the map.
                }
                else {
                    cout << "Your score was " << score << endl;
                    score = 0;
                    round = 0;
                    // This is a victory and should take them back to the map.
                }
            }
            /* This is how bosses used to be set up but we will call this when the boss is ready.
            else if (round % 10 == 0) {
                Boss* bossPtr = new Boss(round);
                playerRanger.fightBossEnemy(*bossPtr);
                delete bossPtr;
                bossPtr = nullptr;

                if (playerRanger.getHealth() > 0) {
                    round++;
                    score = score + 5;
                    // This is a victory and should take them back to the map.
                }
                else {
                    cout << "Your score was " << score << endl;
                    score = 0;
                    round = 0;
                    //Should Restart the game
                }
            }
            */
            else {
                Enemy* enemyPtr = new Enemy(round);
                playerRanger.fightNormalEnemy(*enemyPtr);
                delete enemyPtr;
                enemyPtr = nullptr;

                if (playerRanger.getHealth() > 0) {
                    round++;
                    score = score + 10;
                    // This is a victory and should take them back to the map.
                }
                else {
                    cout << "Your score was " << score << endl;
                    score = 0;
                    round = 0;
                   // Should Restart the game
                }
            }
        }

        else if (characterSelected == "Wizard")
        {

            if (round < 3)
            {
                easyEnemy* easyEnemyPtr = new easyEnemy();

                playerWizard.fightWeakEnemy(*easyEnemyPtr);

                // Freeing the memory allocated for the easyEnemy object
                delete easyEnemyPtr;
                easyEnemyPtr = nullptr;

                if (playerWizard.getHealth() > 0)
                {
                    round++;
                    score = score + 5;
                   // This is a victory and should take them back to the map.
                }
                else
                {
                    cout << "Your score was " << score << endl;
                    score = 0;
                    round = 0;
                    //This is a loss and should restart the game.
                }
            }

            /* This is for how bosses used to be setup for.
            if (round % 10 == 0)
            {
                Boss* bossPtr = new Boss(round);

                playerWizard.fightBossEnemy(*bossPtr);


                delete bossPtr;
                bossPtr = nullptr;

                if (playerWizard.getHealth() > 0)
                {
                    round++;
                    score = score + 5;
                    // This is a victory and should take them back to the map.
                }
                else
                {
                    cout << "Your score was " << score << endl;
                    score = 0;
                    round = 0;
                    //This is a lose and should restart the game.
                }
            }
            */

            else
            {

                Enemy* enemyPtr = new Enemy(round);
                playerWizard.fightNormalEnemy(*enemyPtr);

                delete enemyPtr;
                enemyPtr = nullptr;

                if (playerWizard.getHealth() > 0)
                {
                    round++;
                    score = score + 10;
                    // This is a victory and should take them back to the map.
                }
                else
                {
                    cout << "Your score was " << score << endl;
                    score = 0;
                    round = 0;
                   //This is a loss and should restart the game.
                }

            }
        }
        else if (characterSelected == "Rogue")
        {
        if (round < 3)
        {
            easyEnemy* easyEnemyPtr = new easyEnemy();

            playerRogue.fightWeakEnemy(*easyEnemyPtr);

            // Freeing the memory allocated for the easyEnemy object
            delete easyEnemyPtr;
            easyEnemyPtr = nullptr;

            if (playerRogue.getHealth() > 0)
            {
                round++;
                score = score + 5;
                // This is a victory and should take them back to the map.
            }
            else
            {
                cout << "Your score was " << score << endl;
                score = 0;
                round = 0;
                //This is a loss and should restart the game.
            }
        }

        /* This is for how bosses used to be setup for.
        if (round % 10 == 0)
        {
            Boss* bossPtr = new Boss(round);

            playerWizard.fightBossEnemy(*bossPtr);


            delete bossPtr;
            bossPtr = nullptr;

            if (playerWizard.getHealth() > 0)
            {
                round++;
                score = score + 5;
                // This is a victory and should take them back to the map.
            }
            else
            {
                cout << "Your score was " << score << endl;
                score = 0;
                round = 0;
                //This is a lose and should restart the game.
            }
        }
        */

        else
        {

            Enemy* enemyPtr = new Enemy(round);
            playerRogue.fightNormalEnemy(*enemyPtr);

            delete enemyPtr;
            enemyPtr = nullptr;

            if (playerWizard.getHealth() > 0)
            {
                round++;
                score = score + 10;
                // This is a victory and should take them back to the map.
            }
            else
            {
                cout << "Your score was " << score << endl;
                score = 0;
                round = 0;
                //This is a loss and should restart the game.
            }

        }
        }
    };



    // Handles the game's update logic
    void update()
    {

    }

    // Renders the game to the screen
    void render()
    {

    }

    // Ends the game with message, releases resources, etc.
    void end()
    {

    }

    // Saves the current game state
    void save()
    {

    }

    // Loads a saved game state
    void load()
    {

    }

    // Quits the game
    void SaveAndQuit()
    {

    }
};