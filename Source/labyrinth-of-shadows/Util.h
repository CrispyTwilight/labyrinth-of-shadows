//Auth: William Brickner (Should be everyone else as well.)
//Date: 11/30/23
//Desc: All of the utility function and modules that are used most or all classes that will free up space and get rid of clutter.
#pragma once
#include "All_Includes.h"

bool checkForLevelUp(int& exp, int& expNeeded)
{
    if (exp > expNeeded)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//This is for some visual issues I was having with the cli, Should be moved later to utilities.
//This always keeps the command line at the bottom instead of clearing it.
void setCursorPosition(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}

void visual()
{
    //Also for visual issues, will be moved.
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
    cursorInfo.bVisible = false; // Set cursor visibility
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}


// JPO: This is used in Inventory and Shop Classes to get the index of the item the user wants to select.
int getZeroBasedIntOrQuit() {
    char input = _getch();
    if (input == 27) { // Escape key
        return -1;
    }
    return input - 1 - '0'; // Convert to integer 0 based index
}