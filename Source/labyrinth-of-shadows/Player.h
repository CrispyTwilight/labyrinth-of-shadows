#pragma once
#include <iostream>
#include <conio.h>
using namespace std;

class Player
{
private:
    int x, y; //Player's position

public:
    Player(int initialX, int initialY) {
        x = initialX;
        y = initialY;
    }

    void handleInput() {
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

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    void getPosition(int& outX, int& outY) const {
        outX = x;
        outY = y;
    }

};

