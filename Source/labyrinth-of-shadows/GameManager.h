// Date: 12/04/2023
// Auth: John O'Neal
// Desc: This class will manage the game and all of its components. Loading, ending, saving, quitting, etc. will all be handled here.
#pragma once
#include <iostream>
#include <conio.h>
#include "Save.h"
#include "Load.h"
#include "Ranger.h"
#include "Wizard.h"
#include "Enemy.h"
// Will need to #include all of the other classes here.

class GameManager
{
private:
    // Adding the basic fields of score and round count so that I could properly save and load the game.
    int round;
    int score;
    std::string characterSelected;
public:
    // Initializes the game, loads resources, etc.
    void init()
    {
       // Introduction will go here

    }

    // Starts the main game loop
    void start() 
    {

    }

    // Handles the game's update logic
    void update() 
    {

    }

    // Renders the game to the screen
    void render() 
    {

    }

    // Ends the game with message, releases resources, etc.
    void end() 
    {

    }

    // Saves the current game state
    void save() 
    {

    }

    // Loads a saved game state
    void load() 
    {

    }

    // Quits the game
    void SaveAndQuit() 
    {

    }
};