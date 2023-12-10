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
protected:
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

    void updateSpace(int x, int y, char u)
    {
        manage.updateMap(y, x, mapLevel, u);
    }

    void reset()
    {
        manage.reset();
    }

    void moveE()
    {
        static int currentDirection = -1; 
        static bool stop = false;
        const int moveProbability = 80; 

        vector<pair<int, int>> results = manage.findE(grid);
        for (const auto& result : results)
        {
            int x = result.first;
            int y = result.second;

            if (rand() % 100 >= moveProbability) {
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
                if (grid[x + 1][y] != '#' && grid[x + 1][y] != 'E')
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
                if (grid[x - 1][y] != '#' && grid[x + 1][y] != 'E')
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
                if (grid[x][y + 1] != '#' && grid[x + 1][y] != 'E')
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
                if (grid[x + 1][y - 1] != '#' && grid[x + 1][y] != 'E')
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

    void moveL(int px, int py) 
    {
        vector<pair<int, int>> results = manage.findL(grid);
        for (const auto& result : results)
        {
            int x = result.first;
            int y = result.second;



          
                if (grid[x + 1][y] != '#' && grid[x + 1][y] != 'E')
                {
                    manage.updateMap(x, y, mapLevel, '.');
                    manage.updateMap(x + 1, y, mapLevel, 'E');
                } 
           
                if (grid[x - 1][y] != '#' && grid[x + 1][y] != 'E')
                {
                    manage.updateMap(x, y, mapLevel, '.');
                    manage.updateMap(x - 1, y, mapLevel, 'E');
                }
                else
                {
                   
                }
                
                if (grid[x][y + 1] != '#' && grid[x + 1][y] != 'E')
                {
                    manage.updateMap(x, y, mapLevel, '.');
                    manage.updateMap(x, y + 1, mapLevel, 'E');
                }
                
                
            
                if (grid[x + 1][y - 1] != '#' && grid[x + 1][y] != 'E')
                {
                    manage.updateMap(x, y, mapLevel, '.');
                    manage.updateMap(x, y - 1, mapLevel, 'E');
                }
                
               
            


        }
    }
};