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

//This is for some visual issues I was having with the cli, Should be moved later to utilities.
// JPO: maybe add some more comments here to explain each part of this function as it is a bit complex
void setCursorPosition(int x, int y) {
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}

int main() {
    //Game objects
    Map gameMap(40, 20);
    Player player(0, 0);

    //Infinite loop right now, will need a menu.
    while (true) {
        player.handleInput();
        //This clears the cli
        setCursorPosition(0, 0);
        //Update player's position on the map
        int playerX, playerY;
        player.getPosition(playerX, playerY);
        gameMap.updatePlayerPosition(playerX, playerY);
        gameMap.display();

        //Also for visual issues, will be moved.
        CONSOLE_CURSOR_INFO cursorInfo;
        GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
        cursorInfo.bVisible = false; // Set cursor visibility
        SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

        //This is necessary to control speed of the game.
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}