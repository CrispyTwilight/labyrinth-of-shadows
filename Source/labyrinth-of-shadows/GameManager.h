// Date: 12/04/2023
// Auth: John O'Neal, William Brickner, Christian Botos, Hunter Kauffman, Christian Baack.
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
#include "Map.h"
#include "Player.h"

using namespace std;

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
    Screens screen;

public:
    GameManager()
    {
        Ranger playRanger(25, 25, 5, 5, 7, 1, 0, 5, 0, 0, 0, 0, 1);
        playerRanger = playRanger;
        Wizard playWizard(30, 30, 3, 8, 5, 1, 0, 5, 1, 1, 2, 1);
        playerWizard = playWizard;
        Rogue playRogue(40, 40, 5, 3, 6, 1, 0, 5, 0, 1, 1, 1);
        playerRogue = playRogue;
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
                startNewGame();
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
            save.saveTheGameRanger(round, score, playerRanger);
            cout << "Your game has been saved.\n";
        }
        else if (characterSelected == "Wizard") {
            save.saveTheGameWizard(round, score, playerWizard);
            cout << "Your game has been saved.\n";
        }
        else if (characterSelected == "Rogue") {
            save.saveTheGameRogue(round, score, playerRogue);
            cout << "Your game has been saved.\n";
        }
        else {
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
                Inventory::getInstance()->setMaxWeight(characterSelected);
                startMap();
                break;
            case '2':
                characterSelected = "Wizard";
                Inventory::getInstance()->setMaxWeight(characterSelected);
                startMap();
                break;
            case '3':
                characterSelected = "Rogue";
                Inventory::getInstance()->setMaxWeight(characterSelected);
                startMap();
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
                load.loadTheGameRanger(score, round, playerRanger);
                characterSelected = "Ranger";
                break;
            case 2:
                load.loadTheGameWizard(score, round, playerWizard);
                characterSelected = "Wizard";
                break;
            case 3:
                load.loadTheGameRogue(score, round, playerRogue);
                characterSelected = "Rogue";
                break;
            default:
                cout << "Incorrect value. Please enter a valid value.\n";
                choice = 0; // Reset choice to ensure the loop continues
                break;
            }
        } while (choice < 1 || choice > 3);
    }

    void startMap()
    {
        Map gameMap(51, 31); // JPO: Updated so that the @ is can actually be in the middle of the map.
        Player player(gameMap, 25, 15); // JPO: Updated so that the player starts in the middle of the map.
        while (true)
        {
            srand(time(NULL));
            //This clears the cli
            setCursorPosition(0, 0);

            //Update player's position on the map
            int playerX, playerY;

            player.getPosition(playerX, playerY);
            gameMap.updatePlayerPosition(playerX, playerY);
            gameMap.display();

            gameMap.mapSwitcher();

            // Get input, then decide if inGameMenu or pass to handleInput.
            char option = _getch();
            if (option == 'b' || option == 'i' || option == 'm' || option == '?')
                inGameMenu(option);

            player.handleInput(option);

            gameMap.mapSwitcher();

            gameMap.moveL(playerY, playerX);
            gameMap.moveE();

            visual();
            if (gameMap.getTrigger())
            {
                gameMap.updateSpace(playerX, playerY, '.');

                //Calls the fighting.
                fighting(false);

                gameMap.toggle();

                system("cls");
            }
            if (gameMap.getTrigger2())
            {
                fighting(true);
            }

            //This is necessary to control speed of the game.
            this_thread::sleep_for(chrono::milliseconds(100));
        }
    }

    void inGameMenu(char option) {
        switch (option) {
        case 'b':
            saveGame();
            break;
        case 'i':
            Inventory::getInstance()->openInventory();
            break;
        case 'm':
            processMainMenu();
            // User can quit from here
            break;
        case '?':
            screen.showHelp();
            break;
        default:
            cout << "You have encountered an unexpected error.\n";
            break;
        }
    }

    void fighting(bool isBossFight)
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
                    screen.showDeath();
                    processMainMenu();
                    // This is a lose and should restart the game.
                }
            }

            else if (isBossFight) {
                Boss* bossPtr = new Boss(round);
                playerRanger.fightBossEnemy(*bossPtr);
                delete bossPtr;
                bossPtr = nullptr;

                if (playerRanger.getHealth() > 0) {
                    round++;
                    score = score + 5;
                    screen.showVictory();
                    // This is a victory and should take them back to the map.
                }
                else {
                    cout << "Your score was " << score << endl;
                    score = 0;
                    round = 0;
                    screen.showDeath();
                    processMainMenu();
                    //Should Restart the game
                }
            }

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
                    screen.showDeath();
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
                    screen.showDeath();
                    processMainMenu();
                    //This is a loss and should restart the game.
                }
            }

            else if (isBossFight)
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
                    screen.showDeath();
                    processMainMenu();
                    //This is a lose and should restart the game.
                }
            }

            else
            {

                Enemy* enemyPtr = new Enemy(round);
                playerWizard.fightNormalEnemy(*enemyPtr);
                delete enemyPtr;
                enemyPtr = nullptr;

                if (playerWizard.getHealth() > 0) {
                    round++;
                    score = score + 10;
                    // This is a victory and should take them back to the map.
                }
                else {
                    cout << "Your score was " << score << endl;
                    score = 0;
                    round = 0;
                    screen.showDeath();
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
                    processMainMenu();
                    //This is a loss and should restart the game.
                }
            }

            if (isBossFight)
            {
                Boss* bossPtr = new Boss(round);
                playerRogue.fightBossEnemy(*bossPtr);
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
                    // This is a lose and should restart the game.
                }
            }

            else if (isBossFight) {
                Boss* bossPtr = new Boss(round);
                playerRogue.fightBossEnemy(*bossPtr);
                delete bossPtr;
                bossPtr = nullptr;

                if (playerRogue.getHealth() > 0) {
                    round++;
                    score = score + 5;
                    screen.showVictory();
                    // This is a victory and should take them back to the map.
                }
                else{
                    cout << "Your score was " << score << endl;
                    score = 0;
                    round = 0;
                    screen.showDeath();
                    processMainMenu();
                    //This is a lose and should restart the game.
                }
            }

            else {
                Enemy* enemyPtr = new Enemy(round);
                playerRogue.fightNormalEnemy(*enemyPtr);
                delete enemyPtr;
                enemyPtr = nullptr;

                if (playerRogue.getHealth() > 0) {
                    round++;
                    score = score + 10;
                    // This is a victory and should take them back to the map.
                }
                else {
                    cout << "Your score was " << score << endl;
                    score = 0;
                    round = 0;
                    screen.showDeath();
                    processMainMenu();
                    //This is a loss and should restart the game.
                }
            }
        }
    }
};