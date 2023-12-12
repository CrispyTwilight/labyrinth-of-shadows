# Labyrinth of Shadows
Final Project for C++ and Intro to Programming Logic<br>

This is a dungeon crawl game played in the command line interface. The game allows a player to chose a character, move around a map to different dungeons, encounter and battle monsters, and transact at a shop.

## CAB:
### Class File Item.h:
- Holds names and materials for weapons, armor, and potions. The vector variables held in this file for the classes and structures in Armor.h, Weapon.h, and Potion.h will use the Dice.h file to calculate what the name and material of the item will be based on what the program rolls.

### Structure File Armor.h:
- Holds the data for what type of armor piece an iteration is (like a helmet, shield, greaves, etc.) as an enumerated data type called armorType
    
- Holds the data for an iteration's defense rating and weight is, along with the material it's made of and its name; variable names for these are: int defense, int weight, and string material

- Uses the Dice.h file to make a random number in a certain range and insert them into the values of each variable. For example, if a variable has a range of 1 through 10 and it rolls a 6, the value of that variable will be six. This also works mostly the same way for the string variables
    
- Translates the enumerated variable of armorType of an iteration to a string. For example, if armorType is equal to HELMET, the program will translate the value into the string "Helmet"

### Structure File Weapon.h:
- Holds the date for what kind of weapon an iteration is (like a bow, sword, axe, or dagger) as an enumerated data type called weaponType

- Holds the data for an iteration's damage rating and weight is, along with the material it's made of and its name; variable names are: int damage, int weight, and string material

- Uses the Dice.h file to make a random number in a certain range and insert them into the values of each variable. For example, if a variable has a range of 1 through 10 and it rolls a 6, the value of that variable will be six. This also works mostly the same way for the string variables

- Translates the enumerated variable of weaponType of an iteration to a string. For example, if weaponType is equal to SWORD, the program will translate the value to the string "Sword"

### Structure File Potion.h:
- Holds the date for what kind of potion an iteration is (like a small healing) as an enumerated data type called weaponType

- Holds the data for an iteration's damage rating and weight is, along with the material it's made of and its name; variable names are: int damage, int weight, and string material

- Uses the Dice.h file to make a random number in a certain range and insert them into the values of each variable. For example, if a variable has a range of 1 through 10 and it rolls a 6, the value of that variable will be six. This also works mostly the same way for the string variables

- Translates the enumerated variable of weaponType of an iteration to a string. For example, if weaponType is equal to SMALL_HEAL, the program will translate the value to the string "Small Heal"

### Class File Screens.h
- Uses strings to display a title screen upon booting the game, a victory screen upon beating the game, and a loss screen upon being defeated in combat using modules with names respective to their purpose.

### Structure File Loot.h:
- This file makes random dice rolls for whether loot that the player picks up is a weapon, a piece of armor, or a potion. It also calculates how much gold a user can get in a certain range.

## Christian Baack
### MapManager.h:
- Defines MapManager class.
- Manages multiple maps (map0, map1, etc.).
- Includes functionalities for map retrieval, updating, and resetting.

### Map.h:
- Defines Map class.
- Represents individual maps with dimensions and a 2D grid.
- Includes methods for player position updating, map displaying, and level switching.

### Player.h:
- Defines Player class.
- Manages player's movement and position.
- Integrates with Map class for gameplay mechanics.
- Handles keys collection, fights triggering, and shop interactions.

## John O'Neal
### Inventory.h
- This class represents the player's inventory in a game. It includes items, gold, and equipped weapons and armor. The inventory has a maximum weight and a maximum number of items it can hold.

#### Private Fields:
- `items`: A vector of pointers to Item objects. These represent the items in the inventory.
- `maxWeight`: The maximum weight the inventory can hold.
- `maxItems`: The maximum number of items the inventory can hold.
- `gold`: The amount of gold the player has.
- `selectedCharacter`: The character selected by the player.
- `equippedArmor`: A pointer to the Armor object currently equipped by the player.
- `equippedWeapon`: A pointer to the Weapon object currently equipped by the player.
- `equippedArmorSlots`: A map that stores the Armor objects equipped by the player, categorized by their ArmorType.
- `instance`: A static pointer to an Inventory object. This is used to implement the Singleton design pattern, ensuring that only one instance of the Inventory class can exist.

#### Public Methods:
- `getInstance`: Returns the singleton instance of the Inventory class. If the instance doesn't exist, it creates one.
- `getItems`, `getItem`, `getSize`, `getItemWeight`, `getCurrentWeight`, `getMaxWeight`, `getMaxItems`, `getGold`, `getSelectedCharacter`, `getEquippedArmorByType`, `getEquippedArmorSlots`, `getEquippedWeapon`, `getEquippedWeaponDamage`, `getTotalEquippedDefense`: These are getter methods that return the respective private fields.
- `addItem`, `removeItem`, `setMaxWeight`, `setMaxItems`, `setGold`, `addGold`, `deductGold`, `setEquippedArmorByType`, `setEquippedWeapon`: These are setter methods that modify the respective private fields.
- `displayCurrentInventory`, `equipItem`, `equipArmor`, `equipWeapon`, `discardItem`, `takePotion`, `openInventory`: These methods perform various operations related to the inventory, such as displaying the inventory, equipping and discarding items, taking a potion, and opening the inventory.

#### Private Constructor:
- The constructor is private to ensure that only the singleton instance can be created. It initializes the private fields with the provided arguments or default values.

#### Destructor:
- The destructor deletes all the Item objects in the `items` vector to free up memory.

### Shop.h
- This class represents a shop in the game. It includes an inventory of items, a name, an owner, and other attributes. The shop uses the Singleton design pattern, ensuring that only one instance of the Shop class can exist.

#### Private Fields:
- `instance`: A static pointer to a Shop object. This is used to implement the Singleton design pattern.
- `shopInventoryWeapons`, `shopInventoryArmors`, `shopInventoryPotions`: Vectors of pointers to Weapon, Armor, and Potion objects. These represent the items in the shop's inventory.
- `shopName`, `shopOwner`, `shopOwnerAttribute`: Strings representing the shop's name, the owner's name, and the owner's attribute.
- `menuOptions`: An array of strings representing the options available in the shop's menu.

#### Public Methods:
- `getInstance`: Returns the singleton instance of the Shop class. If the instance doesn't exist, it creates one.
- `initializeShopInformation`, `initializeInventory`: These methods initialize the shop's information and inventory.
- `displayFullShop`, `displayShopInformation`: These methods display the shop's information and inventory.
- `runShop`: This method runs the shop, allowing the player to interact with it.
- `handlePurchase`, `handleSale`: These methods handle the purchase and sale of items.
- `removeAndReplaceFromInventories`: This method removes an item from the shop's inventory and replaces it with a new item.
- `inspectItem`: This method allows the player to inspect an item in the shop's inventory.

#### Private Constructor:
- The constructor is private to ensure that only the singleton instance can be created. It initializes the private fields with the provided arguments or default values.

### Util.h
- This file contains utility functions that are used across multiple classes. These functions help to reduce code clutter and improve code reusability. The functions are globally scoped.

#### Functions:

- `checkForLevelUp`: This function checks if the experience points (`exp`) are greater than the experience points needed (`expNeeded`) for a level up. If `exp` is greater than `expNeeded`, it returns `true`; otherwise, it returns `false`.

- `setCursorPosition`: This function sets the cursor position on the console. It takes two integers `x` and `y` as arguments, representing the coordinates of the new cursor position. The function uses the `SetConsoleCursorPosition` function from the Windows API to set the cursor position.

- `visual`: This function modifies console cursor visibility. It uses the `GetConsoleCursorInfo` and `SetConsoleCursorInfo` functions from the Windows API to make the console cursor invisible.

- `getZeroBasedIntOrQuit`: This function gets a zero-based integer from the user's input or quits if the user presses the Escape key. It uses the `_getch` function to get the user's input and returns the input converted to a zero-based integer index. If the user presses the Escape key, the function returns `-1`.

### GameManager.h
The GameManager class is responsible for managing the game and all of its components. This includes loading, ending, saving, quitting, etc.

#### Private Fields:
- `round`: An integer representing the current round.
- `score`: An integer representing the player's score.
- `characterSelected`: A string representing the character class selected by the player.
- `playerRanger`, `playerWizard`, `playerRogue`: Objects of the Ranger, Wizard, and Rogue classes representing the player characters.

#### Public Methods:

- `GameManager`: Constructor that initializes the player characters and sets the round, score, and characterSelected to their default values.
- `processMainMenu`: Displays the main menu and handles the user's choice.
- `saveGame`: Saves the current game state.
- `startNewGame`: Starts a new game and lets the user select a character class.
- `loadGame`: Loads a previously saved game.
- `startMap`: Starts the game map and handles the game loop.
- `inGameMenu`: Handles the in-game menu options.
- `fighting`: Handles the fighting mechanics of the game. It checks the character selected and the round number to determine the type of enemy to fight. It also handles the victory and defeat scenarios.

### labryinth-of-shadows.cpp
- The main function of a program. It seeds the random number generator, creates an instance of the GameManager class, calls the processMainMenu method on the GameManager instance, and then ends the program.