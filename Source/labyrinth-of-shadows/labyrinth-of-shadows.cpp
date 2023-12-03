// Date: 11/27/2023
// Auth: John O'Neal, William Brickner, Christian Botos, Hunter Kauffman, Christian Baack.
// Desc: Main for final project.

#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>

// Header files for game objects
#include "Map.h"
#include "Player.h"
#include "Utility.h"

int main() 
{
    //Game objects
    Map gameMap(50, 30);
    Player player(gameMap,24, 13);
    Utility util;
    
    //Infinite loop right now, will need a menu.
    while (true) 
    {
        player.handleInput();
        //This clears the cli
        util.setCursorPosition(0, 0);

        gameMap.test();

        //Update player's position on the map
        int playerX, playerY;

        player.getPosition(playerX, playerY);
        gameMap.updatePlayerPosition(playerX, playerY);
        gameMap.display();

        util.visual();
            
        //This is necessary to control speed of the game.
        std::this_thread::sleep_for(std::chrono::milliseconds(100));

    }

    return 0;
}