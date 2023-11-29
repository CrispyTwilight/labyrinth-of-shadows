// Date: 11/27/2023
// Auth: John O'Neal, William Brickner, Christian Botos, Hunter Kauffman, Christian Baack.
// Desc: Main for final project.

#include <iostream>
#include "Map.h"
#include "Player.h"

int main() {
    //Game objects
    Map gameMap(10, 10);
    Player player(0, 0);

    //Infinite loop right now, will need a menu.
    while (true) {
        player.handleInput();
        //This clears the cli
        system("cls");
        //Update player's position on the map
        int playerX, playerY;
        player.getPosition(playerX, playerY);
        gameMap.updatePlayerPosition(playerX, playerY);
        gameMap.display();

    }

    return 0;
}