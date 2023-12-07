// Date: ??
// Auth: Christian Baack
// Desc: Class to define the map of the game.

#pragma once
#include <vector>
#include<iostream>
#include "MapManager.h"

using namespace std;

MapManager manage;

//Map class
class Map {
private:
    int mapLevel = 0;
    int width, height;
    vector<vector<char>> grid;

public:
    Map(int w, int h) : width(w), height(h) // JPO: We could get rid of the default map I think.
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

    void mapSwitcher()
    {
        switch (mapLevel)
        {
        case 0:
            grid = manage.getMap0();
            break;
        case 1:
            grid = manage.getMap1();
            break;
        case 2:
            grid = manage.getMap2();
            break;
        case 3:
            grid = manage.getMap3();
            finalKeys();
            break;
        default:
            cout << "There was an error in map generation";
            break;
        }
    }

    vector<vector<char>> getGrid() const
    {
        return grid;
    }

    void setLevel(int l)
    {
        mapLevel = l;
    }

    int getLevel() const
    {
        return mapLevel;
    }

    void finalKeys()
    {
        int x[4] = {18, 3, 28, 48};
        int y[4] = { 6, 20, 20, 1 };

        for (int i = 0; i < 4; i++)
        {
            grid[y[i]][x[i]] = '?';
        }
    }

    void updateNonStatic()
    {
        finalKeys();
    }
};