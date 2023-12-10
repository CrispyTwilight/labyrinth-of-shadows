// Date: 11/27/2023
// Auth: John O'Neal, William Brickner, Christian Botos, Hunter Kauffman, Christian Baack.
// Desc: Main for final project.

#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>

// Header files for game objects
#include "GameManager.h"
#include "Map.h"
#include "Player.h"
#include "Utility.h"

int main()
{
    //Game objects
    Map gameMap(51, 31); // JPO: Updated so that the @ is can actually be in the middle of the map.
    Player player(gameMap,25, 15); // JPO: Updated so that the player starts in the middle of the map.
    Utility util;

    //Infinite loop right now, will need a menu.
    while (true)
    {
        srand(time(NULL));
        //This clears the cli
        util.setCursorPosition(0, 0);


        //Update player's position on the map
        int playerX, playerY;

        player.getPosition(playerX, playerY);
        gameMap.updatePlayerPosition(playerX, playerY);
        gameMap.display();

        gameMap.mapSwitcher();

        player.handleInput();

        util.visual();
        gameMap.moveE();


        visual();

        //This is necessary to control speed of the game.
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

    }

    return 0;
}