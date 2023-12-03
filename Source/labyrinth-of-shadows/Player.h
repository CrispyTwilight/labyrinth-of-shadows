// Date: ??
// Auth: Christian Baack
// Desc: Class to represent the player in the game for movement and position.

#pragma once
#include <iostream>
#include <conio.h>
#include "Map.h"
using namespace std;

class Player 
{
private:
    Map& map;
    int x, y; //Player's position
    int px, py; //Proposed position. Checking for walls

public:
    Player(Map& map, int initialX, int initialY) : map(map), x(initialX), y(initialY), px(initialX), py(initialY) {}

    void handleInput() 
    {
        char input;
        cout << "Enter move (WASD): ";
        input = _getch();

        switch (input) {
        case 'W': case 'w':
            move(0, -1);
            break;
        case 'S': case 's':
            move(0, 1);
            break;
        case 'A': case 'a':
            move(-1, 0);
            break;
        case 'D': case 'd':
            move(1, 0);
            break;
            //Add more controls as needed
        }
    }

    //This will check if the proposed postion is valid
    void move(int dx, int dy) 
    {   
        px += dx;
        py += dy;
        if (map.getGrid()[py][px] != '#')
        {
            x += dx;
            y += dy;
        }
        else
        {
            px = x;
            py = y;
        }
        cout << "X: " << x << "  Y: " << y;
        
    }

    void getPosition(int& outX, int& outY) const 
    {
        outX = x;
        outY = y;
    }
};