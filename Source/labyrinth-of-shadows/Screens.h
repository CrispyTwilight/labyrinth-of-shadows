// Auth: Christian A. Botos
// Date: 12/09/2023
// Desc: This is a header file that holds modules that display the title screen that comes with instructions

#pragma once

#include "GameManager.h"
#include <iostream>
#include <conio.h>
#include <string>

class Screens
{

public:
    void showTitle()
    {
        system("cls");
        cout << R"(
|----------------------------------------------------------------------------------------------------|
|    _    ____ ___  _   _ ____ _ _  _ ___ _  _    ____ ____    ____ _  _ ____ ___  ____ _ _ _ ____   |
|    |    |__| |__]  \_/  |__/ | |\ |  |  |__|    |  | |___    [__  |__| |__| |  \ |  | | | | [__    |
|    |___ |  | |__]   |   |  \ | | \|  |  |  |    |__| |       ___] |  | |  | |__/ |__| |_|_| ___]   |
|                                                                                                    |
|----------------------------------------------------------------------------------------------------|


                                 WELCOME TO THE LABYRINTH OF SHADOWS!
                        TRAVERSE ITS HALLS AND SURVIVE ITS TERRORS TO WIN THE GAME!

                                      1) Start New Game
                                      2) Load Previous Game
                                      ESC) Quit and Save the Game
                                      ?) Help and Controls)";

    }

    void processMainMenu() {
        char choice;
        do {
            showTitle();
            choice = _getch();
            switch (choice)
            {
            case '1': 
            {
                
                break;
            }
            case '2':
                cout << "\nLoading previous game...\n";
                system ("pause");
                // call to load game
                break;
            case 27: // ESC
                cout << "\nSaving and quitting game...\n";
                //system("pause");
                return;
                // call to save game
            case '?':
                showHelp();
                break;
            default:
                cout << "\nInvalid choice. Try again." << endl;
                system("pause");
                break;
            }
        } while (true);
    }

    void showDeath()
    {
        system("cls");
        cout << R"(
                                                  _____
                                                 /     \
                                                | () () |
                                                 \  ^  /
                                                  |||||
                                                  |||||

                                            YOU HAVE PERISHED.
                                 PRESS ENTER TO RETURN TO THE MAIN MENU.)" << endl;
        _getch(); // Pause for user input
        processMainMenu();
    }

    void showVictory()
    {
        system("cls");
        cout << R"(
                                             .-=========-.
                                             \'-=======-'/
                                             _|   .=.   |_
                                            ((|  {{1}}  |))
                                             \|   /|\   |/
                                              \__ '`' __/
                                                _`) (`_
                                              _/_______\_
                                             /___________\

                                     YOU HAVE OVERCOME THE LABYRINTH!
                                 PRESS ENTER TO RETURN TO THE MAIN MENU.)";
        _getch(); // Pause for user input
    }

    void showHelp()
    {
        system("cls");
        cout << R"(
        ASCII ART OF THE TROPHY AND SKULL COURTESY OF "ascii.co.uk"
        TITLE TEXT FONT COURTESY OF "ascii.today"
        --------------------------------------------------------------

        CONTROLS
        -------------------------
        WASD - MOVEMENT
        E- INTERACT
        ENTER - SAVE GAME
        CTRL - LOAD GAME
        ESC - RETURN TO MENU
        
        PRESS ANY KEY TO EXIT
        )";
        
        _getch(); // Pause for user input
        // This should return to whatever screen the user was on before.
    }
};