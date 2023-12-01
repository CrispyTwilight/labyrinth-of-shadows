// Date: ??
// Auth: Christian Baack
// Desc: Class to define the map of the game.

#pragma once
#include <vector>
#include<iostream>
using namespace std;

//Map class
class Map {
private:
    vector<vector<char>> grid;
    int width, height;

public:
    Map(int w, int h) : width(w), height(h) {
        grid = vector<vector<char>>(h, vector<char>(w, '.')); // '.' for empty space
    }

    void updatePlayerPosition(int x, int y) {
        //Clear previous position
        for (auto& row : grid) {
            fill(row.begin(), row.end(), '.');
        }

        //Update new position
        if (x >= 0 && x < width && y >= 0 && y < height) {
            grid[y][x] = '@'; // '@' represents the player
        }
    }

    void display() const { // JPO: const because it doesn't modify the object
        for (const auto& row : grid) {
            for (char cell : row) {
                cout << cell << " ";
            }
            cout << endl; // JPO: removed the std:: prefix because we're using the namespace std
        }
    }
};