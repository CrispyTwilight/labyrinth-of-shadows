// Auth: John O'Neal
// Date: 12/07/2023
// Desc: A header file to include all the standard C++ headers and the headers for the classes and structures used in the project. Use #include "All_Includes.h" across all files and then add the file name here for cross-file access.
#pragma once

// Include all the standard C++ headers used in the project
#include <array>
#include <conio.h>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <sstream>
#include <thread>
#include <vector>
#include <windows.h>

// Use the standard namespace
using namespace std;

// Utility includes
#include "Util.h"
#include "Dice.h"
#include "GameManager.h"
#include "Screens.h"

// Map includes
#include "MapManager.h"
#include "Map.h"

// Item includes
#include "Item.h"
#include "Inventory.h"
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"
#include "Shop.h"
#include "Loot.h"

//Character and enemy includes
#include "Player.h"

// File includes
#include "RangerLoadFile.h"
#include "WizardLoadFile.h"
#include "Save.h"
#include "Load.h"