// Date: 12/11/23
// Auth: Christian Baack
// Desc: Class to define the map of the game.
#pragma once
#include "MapManager.h"
#include <vector>

//Map class
class Map {
protected:
    bool fightTrigger = false;
    bool bossTrigger = false;
    int mapLevel = 0;
    int width, height;
    vector<vector<char>> grid;
    MapManager manage;

public:
    Map(int w, int h) : width(w), height(h)
    {
        grid = vector<vector<char>>(h, vector<char>(w, '.')); // '.' for empty space
    }

    void updatePlayerPosition(int x, int y)
    {
        //Only clear the player's previous position
       /* for (auto& row : grid)
        {
            for (auto& cell : row)
            {
                if (cell == '@')
                {
                    cell = '.';
                }
            }
        }
        */
        //Update new position

        grid[y][x] = '@'; // '@' represents the player

    }

    //Displays the Map.
    void display() const
    {
        for (const auto& row : grid)
        {
            for (char cell : row)
            {
                cout << cell << " ";
            }
            cout << endl;
        }
    }

    //Checks which map should be displayed
    void mapSwitcher()
    {
        for (auto& row : grid)
        {
            fill(row.begin(), row.end(), '.'); //Replace every cell with '.' to clear enemies and other characters
        }
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

    //Updates the space given coordinates
    void updateSpace(int x, int y, char u)
    {
        manage.updateMap(y, x, mapLevel, u);
    }

    void reset()
    {
        manage.reset();
    }

    //All the Logic to handle moving 'E' around the map.
    void moveE()
    {
        static int currentDirection = -1;
        static bool stop = false;
        const int moveProbability = 60;

        vector<pair<int, int>> results = manage.findE(grid);
        for (const auto& result : results)
        {
            int x = result.first;
            int y = result.second;

            if (rand() % 100 >= moveProbability)
            {
                continue;
            }

            if (currentDirection == -1 || stop)
            {
                currentDirection = rand() % 4 + 1;
                stop = false;
            }

            switch (currentDirection)
            {
            case 1:
                if (grid[x + 1][y] != '#' && grid[x + 1][y] != 'E' && grid[x + 1][y] != 'A' && grid[x + 1][y] != 'D' && grid[x + 1][y] != '?')
                {
                    manage.updateMap(x, y, mapLevel, '.');
                    manage.updateMap(x + 1, y, mapLevel, 'E');
                }
                else
                {
                    stop = true;
                }
                break;
            case 2:
                if (grid[x - 1][y] != '#' && grid[x - 1][y] != 'E' && grid[x - 1][y] != 'A' && grid[x - 1][y] != 'D' && grid[x - 1][y] != '?')
                {
                    manage.updateMap(x, y, mapLevel, '.');
                    manage.updateMap(x - 1, y, mapLevel, 'E');
                }
                else
                {
                    stop = true;
                }
                break;
            case 3:
                if (grid[x][y + 1] != '#' && grid[x][y + 1] != 'E' && grid[x][y + 1] != 'A' && grid[x][y + 1] != 'D' && grid[x][y + 1] != '?')
                {
                    manage.updateMap(x, y, mapLevel, '.');
                    manage.updateMap(x, y + 1, mapLevel, 'E');
                }
                else
                {
                    stop = true;
                }
                break;
            case 4:
                if (grid[x][y - 1] != '#' && grid[x][y - 1] != 'E' && grid[x][y - 1] != 'A' && grid[x][y - 1] != 'D' && grid[x][y - 1] != '?')
                {
                    manage.updateMap(x, y, mapLevel, '.');
                    manage.updateMap(x, y - 1, mapLevel, 'E');
                }
                else
                {
                    stop = true;
                }
                break;
            default:
                break;
            }
        }
    }

    //All the Logic to handle moving 'L' around the map.
    void moveL(int px, int py)
    {
        vector<pair<int, int>> results = manage.findL(grid);
        for (const auto& result : results)
        {
            int x = result.first;
            int y = result.second;

            if (px > x && grid[x + 1][y] != '#' && grid[x + 1][y] != 'A' && grid[x + 1][y] != 'D' && grid[x + 1][y] != '?')
            {
                manage.updateMap(x, y, mapLevel, '.');
                manage.updateMap(x + 1, y, mapLevel, 'L');
            }
            else if (px < x && grid[x - 1][y] != '#' && grid[x - 1][y] != 'A' && grid[x - 1][y] != 'D' && grid[x - 1][y] != '?')
            {
               manage.updateMap(x, y, mapLevel, '.');
               manage.updateMap(x - 1, y, mapLevel, 'L');
            }
            else if (py > y && grid[x][y + 1] != '#' && grid[x][y + 1] != 'A' && grid[x][y + 1] != 'D' && grid[x][y + 1] != '?')
            {
                manage.updateMap(x, y, mapLevel, '.');
                manage.updateMap(x, y + 1, mapLevel, 'L');
            }
            else if (py < y && grid[x][y - 1] != '#' && grid[x][y + 1] != 'A' && grid[x][y + 1] != 'D' && grid[x][y + 1] != '?')
            {
                manage.updateMap(x, y, mapLevel, '.');
                manage.updateMap(x, y - 1, mapLevel, 'L');
            }
        }
    }

    void toggle()
    {
        fightTrigger = !fightTrigger;
    }

    void toggle2()
    {
        bossTrigger = !bossTrigger;
    }

    bool getTrigger()
    {
        return fightTrigger;
    }

    bool getTrigger2()
    {
        return bossTrigger;
    }
};