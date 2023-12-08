// Auth: John O'Neal
// Date: 12/07/2023
// Desc: A header file to include all the standard C++ headers and the headers for the classes used in the project. Keep in alphabetical order.
#pragma once
// Include all the standard C++ headers used in the project.
#include <array>
#include <conio.h>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>
#include <thread>
#include <vector>
#include <windows.h>

// Use the standard namespace.
using namespace std;

// Include all the headers for the classes used in the project.
#include "Dice.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "Shop.h"
#include "Loot.h"
#include "Character.h"
#include "Dice.h"
#include "Enemy.h"
#include "GameManager.h"
#include "MapManager.h" // out of alphabetical order because it uses Map.h
#include "Map.h"
#include "Player.h"
#include "Ranger.h"
#include "Util.h"