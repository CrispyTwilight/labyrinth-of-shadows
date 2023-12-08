// Date: ??
// Auth: Christian Baack
// Desc: Class to define the map of the game.
#pragma once
#include "All_Includes.h"

MapManager manage;

//Map class
class Map {
private:

    int width, height;
    vector<vector<char>> grid;

public:

    Map(int w, int h) : width(w), height(h)
    {
        grid = vector<vector<char>>(h, vector<char>(w, '.')); // '.' for empty space
    }

    void updatePlayerPosition(int x, int y)
    {
        //Only clear the player's previous position
        for (auto& row : grid)
        {
            for (auto& cell : row)
            {
                if (cell == '@')
                {
                    cell = '.';
                }
            }
        }
        //Update new position
        if (x >= 0 && x < width && y >= 0 && y < height)
        {
            grid[y][x] = '@'; // '@' represents the player
        }
    }

    void display() const
    { // JPO: const because it doesn't modify the object
        for (const auto& row : grid)
        {
            for (char cell : row)
            {
                cout << cell << " ";
            }
            cout << endl; // JPO: removed the std:: prefix because we're using the namespace std
        }
    }

    void test()
    {
        grid = manage.getMap1();
    }

    vector<vector<char>> getGrid()
    {
        return grid;
    }
};