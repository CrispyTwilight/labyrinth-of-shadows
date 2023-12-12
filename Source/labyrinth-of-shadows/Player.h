// Date: 12/11/23
// Auth: Christian Baack
// Desc: Class to represent the player in the game for movement and position.
#pragma once
#include "All_Includes.h"
#include "Shop.h"

class Player
{
private:
    Map& map;
    int x, y; //Player's position
    int px, py; //Proposed position. Checking for walls
    int keys = 0;

public:
    Player(Map& map, int initialX, int initialY) : map(map), x(initialX), y(initialY), px(initialX), py(initialY) {}

    //Function gets player input and calls the according move function
    void handleInput(char option)

    {
        cout << "Enter move (WASD): ";

        switch (option) {
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
        }
    }

    //This will check if the proposed position is valid
    void move(int dx, int dy)
    {
        px += dx;
        py += dy;

        //All the different checks for Collisions.
        if (map.getGrid()[py][px] == 'A')
        {
            map.setLevel(map.getLevel() - 1);
            px = x = 25;
            py = y = 15;
        }
        if (map.getGrid()[py][px] == '?')
        {
            map.updateSpace(px, py, '.');
            keys += 1;
            if (keys == 5)
            {
                map.updateSpace(24, 14, '?');
            }
        }
        if (map.getGrid()[py][px] == 'E' || map.getGrid()[py][px] == 'L')
        {
            map.toggle();
        }
        if (map.getGrid()[py][px] == 'D')
        {
            map.setLevel(map.getLevel() + 1);
            px = x = 25;
            py = y = 15;
        }
        if (map.getGrid()[py][px] == 'S')
        {
            Shop::getInstance()->runShop(); // Call to handle the shop logic.
        }
        else if (map.getGrid()[py][px] != '#')
        {
            x += dx;
            y += dy;
        }

        px = x;
        py = y;

        resetOrBoss();
    }

    void getPosition(int& outX, int& outY) const
    {
        outX = x;
        outY = y;
    }

    //Resets the map or goes onto the boss fight.
    void resetOrBoss()
    {
        char c = '0';
        if (keys == 6)
        {
            cout << "Would you like to reset the game(you keep all your character progress), or fight the final boss?\n1. Reset\n2. Fight";
            c = _getch();
            keys = 0;
            system("cls");
        }

        if (c == '1')
        {
            map.reset();
            map.setLevel(0);
        }
        else if (c == '2')
        {
            map.toggle2();
        }
    }
};