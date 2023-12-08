// Auth: John O'Neal
// Date: 12/07/2023
// Desc: A header file to include all the standard C++ headers and the headers for the classes and structures used in the project. Use #include "All_Includes.h" across all files and then add the file name here for cross-file access.
#pragma once

// Include all the standard C++ headers used in the project.
#include <array>
#include <conio.h>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <thread>
#include <vector>
#include <windows.h>

// Use the standard namespace.
using namespace std;

// Utility includes
#include "Util.h"
#include "Dice.h"
#include "GameManager.h"

// Map includes
#include "MapManager.h"
#include "Map.h"

// Item includes
#include "Inventory.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "Shop.h"
#include "Loot.h"

//Character and enemy includes
#include "Dagger.h"
#include "Sword.h"
#include "Bow.h"
#include "Staff.h"

#include "Character.h"
#include "Enemy.h"
#include "easyEnemy.h"
#include "Boss.h"

#include "Player.h"
#include "Ranger.h"
#include "Boss.h"
#include "Rogue.h"
#include "Wizard.h"

// File includes
#include "RangerLoadFile.h"
#include "WizardLoadFile.h"
#include "Save.h"
#include "Load.h"