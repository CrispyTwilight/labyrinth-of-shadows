// Auth: Christian A. Botos
// Date: 12/09/2023
// Desc: This is a header file that holds modules that display the title screen that comes with instructions

#pragma once
#include "Headers.h"

class Screens
{
public:
    void showTitle()
    {
        cout << R"(
|----------------------------------------------------------------------------------------------------|
|    _    ____ ___  _   _ ____ _ _  _ ___ _  _    ____ ____    ____ _  _ ____ ___  ____ _ _ _ ____   |
|    |    |__| |__]  \_/  |__/ | |\ |  |  |__|    |  | |___    [__  |__| |__| |  \ |  | | | | [__    |
|    |___ |  | |__]   |   |  \ | | \|  |  |  |    |__| |       ___] |  | |  | |__/ |__| |_|_| ___]   |
|                                                                                                    |
|----------------------------------------------------------------------------------------------------|


                                 WELCOME TO THE LABYRINTH OF SHADOWS!
                        TRAVERSE ITS HALLS AND SURVIVE ITS TERRORS TO WIN THE GAME!

                                      1. Start New Game
                                      2. Load Previous Game
                                      0. Quit and Save the Game
                                      ?. Help and Controls)";
    }

    void showDeath()
    {
        cout << R"(
                                                  _____
                                                 /     \
                                                | () () |
                                                 \  ^  /
                                                  |||||
                                                  |||||

                                            YOU HAVE PERISHED.
                                 PRESS ENTER TO RETURN TO THE MAIN MENU.)";
    }

    void showVictory()
    {
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
                                  PRESS ENTER TO RETURN TO THE MAIN MENU!)";
    }

    void showHelp()
    {
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
        )";
    }
};