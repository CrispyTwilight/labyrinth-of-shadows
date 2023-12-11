// Date: 12/04/2023
// Auth: John O'Neal
// Desc: This class will manage the game and all of its components. Loading, ending, saving, quitting, etc. will all be handled here.
#pragma once
#include <iostream>
#include <conio.h>
#include <string>
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
#include "Screens.h"
#include "MapManager.h"
#include "Map.h"
#include "Player.h"
#include "Util.h"

using namespace std;
// Will need to #include all of the other classes here.

class GameManager
{
private:
    // Adding the basic fields of score and round count so that I could properly save and load the game.
    int round;
    int score;
    string characterSelected;
    Ranger playerRanger;
    Wizard playerWizard;
    Rogue playerRogue;
    Inventory playerInventory;
    Screens screen;

public:
    GameManager()
    {
        Ranger playRanger(25, 25, 5, 5, 7, 1, 0, 5, 0, 0, 0, 0, 1);
        playerRanger = playRanger;
        Wizard playWizard(30, 30, 3, 8, 5, 1, 0, 5, 1, 1, 2, 1);
        playerWizard = playWizard;
        Rogue playRogue(40, 40, 5, 3, 6, 1, 0, 5, 0, 0, 0, 1);
        playerRogue = playRogue;
        Inventory playerInventory;
        round = 0;
        score = 0;
        characterSelected = "";
    }

    void processMainMenu() {
        char choice;
        do {
            screen.showTitle();
            choice = _getch();
            switch (choice)
            {
            case '1': {
                startNewGame();
                break;
            }
            case '2':
                cout << "\nLoading previous game...\n";
                loadGame();
                runGame();
                system("pause");
                break;
            case 27: // ESC
                cout << "\nSaving and quitting game...\n";
                saveGame();
                system("pause");
                return;
            case '?':
                screen.showHelp();
                break;
            default:
                cout << "\nInvalid choice. Try again." << endl;
                system("pause");
                break;
            }
        } while (true);
    }

    void saveGame() {
        Save save;
        if (characterSelected == "Ranger") {
            save.saveTheGameRanger(round, score, playerRanger, playerInventory);
            cout << "Your game has been saved.\n";
        } else if (characterSelected == "Wizard") {
            save.saveTheGameWizard(round, score, playerWizard, playerInventory);
            cout << "Your game has been saved.\n";
        } else if (characterSelected == "Rogue") {
            save.saveTheGameRogue(round, score, playerRogue, playerInventory);
            cout << "Your game has been saved.\n";
        } else {
            cout << "There is no character to be saved.";
        }
        return;
    }

    void startNewGame() {
        cout << "\n\nSelect a class to play as:\n"
            << "1) Ranger (A class focused on reflecting attacks and dodging attacks while doing massive damage)\n"
            << "2) Wizard (A High Defense and High Damaging Wizard)\n"
            << "3) Rogue (A damaging Rogue that can vanish and do deadly sneak attacks)\n"
            << "ESC) Exit";

        char choice;
        do {
            choice = _getch();
            switch (choice) {
            case '1':
                characterSelected = "Ranger";
                playerInventory.setMaxWeight(characterSelected);
                runGame();
                break;
            case '2':
                characterSelected = "Wizard";
                playerInventory.setMaxWeight(characterSelected);
                runGame();
                break;
            case '3':
                characterSelected = "Rogue";
                playerInventory.setMaxWeight(characterSelected);
                runGame();
                break;
            case 27: // ESC
                return;
            default:
                cout << "\nInvalid choice. Try again.\n";
                break;
            }
        } while (true);
    }

    void loadGame() {
        int choice = 0;
        Load load;
        cout << "\nWhat class would you like to load?\n"
            << "1. Ranger\n"
            << "2. Wizard\n"
            << "3. Rogue\n";

        do {
            cout << "Enter your choice: ";
            choice = _getch() - '0';

            switch (choice) {
            case 1:
                load.loadTheGameRanger(score, round, playerRanger, playerInventory);
                characterSelected = "Ranger";
                break;
            case 2:
                load.loadTheGameWizard(score, round, playerWizard, playerInventory);
                characterSelected = "Wizard";
                break;
            case 3:
                load.loadTheGameRogue(score, round, playerRogue, playerInventory);
                characterSelected = "Rogue";
                break;
            default:
                cout << "Incorrect value. Please enter a valid value.\n";
                choice = 0; // Reset choice to ensure the loop continues
                break;
            }
        } while (choice < 1 || choice > 3);
    }

    void runGame() {
        Map gameMap(51, 31);
        Player player(gameMap, 25, 15);

        while (true)
        {
            srand(time(NULL));
            setCursorPosition(0, 0);

            int playerX, playerY;
            player.getPosition(playerX, playerY);
            gameMap.updatePlayerPosition(playerX, playerY);
            gameMap.display();

            gameMap.mapSwitcher();

            player.handleInput();

            gameMap.mapSwitcher();

            gameMap.moveL(playerY, playerX);
            gameMap.moveE();

            visual();
            if (gameMap.getTrigger())
            {
                gameMap.updateSpace(playerX, playerY, '.');

                fighting(false);  // Assuming fighting() is a method in GameManager

                gameMap.toggle();
            }
            if (gameMap.getTrigger2())
            {
                fighting(true);  // Assuming fighting() is a method in GameManager
            }

            this_thread::sleep_for(chrono::milliseconds(100));
        }
    }

    // Starts the main game loop
    void start()
    {
        // We need to decide whether to display the map first or pop up a menu
    }


    void fighting(bool isBossFight)
    {
        cout << playerRanger.getHealth();
        if (characterSelected == "Ranger") {
            if (round < 3) {
                easyEnemy* easyEnemyPtr = new easyEnemy();
                playerRanger.fightWeakEnemy(*easyEnemyPtr,playerInventory);
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
                    processMainMenu();
                    // This is a victory and should take them back to the map.
                }
            }

            else if (isBossFight) {
                Boss* bossPtr = new Boss(round);
                playerRanger.fightBossEnemy(*bossPtr,playerInventory);
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

            else {
                Enemy* enemyPtr = new Enemy(round);
                playerRanger.fightNormalEnemy(*enemyPtr, playerInventory);
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
                    processMainMenu();
                   // Should Restart the game
                }
            }
        }

        else if (characterSelected == "Wizard")
        {

            if (round < 3)
            {
                easyEnemy* easyEnemyPtr = new easyEnemy();

                playerWizard.fightWeakEnemy(*easyEnemyPtr, playerInventory);

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
                    processMainMenu();
                    //This is a loss and should restart the game.
                }
            }

            if (isBossFight)
            {
                Boss* bossPtr = new Boss(round);

                playerWizard.fightBossEnemy(*bossPtr ,playerInventory);


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
                    processMainMenu();
                    //This is a lose and should restart the game.
                }
            }


            else
            {

                Enemy* enemyPtr = new Enemy(round);
                playerWizard.fightNormalEnemy(*enemyPtr, playerInventory);

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
                    processMainMenu();
                   //This is a loss and should restart the game.
                }

            }
        }
        else if (characterSelected == "Rogue")
        {
        if (round < 3)
        {
            easyEnemy* easyEnemyPtr = new easyEnemy();

            playerRogue.fightWeakEnemy(*easyEnemyPtr, playerInventory);

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
                processMainMenu();
                //This is a loss and should restart the game.
            }
        }


        if (isBossFight)
        {
            Boss* bossPtr = new Boss(round);

            playerRogue.fightBossEnemy(*bossPtr, playerInventory);


            delete bossPtr;
            bossPtr = nullptr;

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
                processMainMenu();
                //This is a lose and should restart the game.
            }
        }


        else
        {

            Enemy* enemyPtr = new Enemy(round);
            playerRogue.fightNormalEnemy(*enemyPtr, playerInventory);

            delete enemyPtr;
            enemyPtr = nullptr;

            if (playerRogue.getHealth() > 0)
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
                processMainMenu();
                //This is a loss and should restart the game.
            }

        }
        }
    };



    // Handles the game's update logic
    void openInventory()
    {
        playerInventory.openInventory();
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