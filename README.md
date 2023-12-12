# Labyrinth of Shadows
Final Project for C++ and Intro to Programming Logic<br>

This is a dungeon crawl game played in the command line interface. The game allows a player to chose a character, move around a map to different rooms, encounter and battle monsters, and solve puzzles. 

CAB:
    Item Groups:
        Class File Item.h:
            Holds names and materials for weapons, armor, and potions. The vector variables held in this file for the classes and structures in Armor.h, Weapon.h, and Potion.h will use the Dice.h file to calculate what the name and material of the item will be based on what the program rolls.

        Structure File Armor.h:
            Holds the data for what type of armor piece an iteration is (like a helmet, shield, greaves, etc.) as an enumerated data type called armorType
            
            Holds the data for an iteration's defense rating and weight is, along with the material it's made of and its name; variable names for these are: int defense, int weight, and string material

            Uses the Dice.h file to make a random number in a certain range and insert them into the values of each variable. For example, if a variable has a range of 1 through 10 and it rolls a 6, the value of that variable will be six. This also works mostly the same way for the string variables
            
            Translates the enumerated varaible of armorType of an iteration to a string. For example, if armorType is equal to HELMET, the program will translate the value into the string "Helmet"

        Structure File Weapon.h:
            Holds the date for what kind of weapon an iteration is (like a bow, sword, axe, or dagger) as an enumerated data type called weaponType

            Holds the data for an iteration's damage rating and weight is, along with the material it's made of and its name; variable names are: int damage, int weight, and string material

            Uses the Dice.h file to make a random number in a certain range and insert them into the values of each variable. For example, if a variable has a range of 1 through 10 and it rolls a 6, the value of that variable will be six. This also works mostly the same way for the string variables

            Translates the enumerated varaible of weaponType of an iteration to a string. For example, if weaponType is equal to SWORD, the program will translate the value to the string "Sword"
        
        Structure File Potion.h:
            Holds the date for what kind of potion an iteration is (like a small healing) as an enumerated data type called weaponType

            Holds the data for an iteration's damage rating and weight is, along with the material it's made of and its name; variable names are: int damage, int weight, and string material

            Uses the Dice.h file to make a random number in a certain range and insert them into the values of each variable. For example, if a variable has a range of 1 through 10 and it rolls a 6, the value of that variable will be six. This also works mostly the same way for the string variables

            Translates the enumerated varaible of weaponType of an iteration to a string. For example, if weaponType is equal to SMALL_HEAL, the program will translate the value to the string "Small Heal"

        Class File Screens.h
            Uses strings to display a title screen upon booting the game, a victory screen upon beating the game, and a loss screen upon being defeated in combat using modules with names respective to their purpose.

        Structure File Loot.h:
            This file makes random dice rolls for whether loot that the player picks up is a weapon, a piece of armor, or a potion. It also calculates how much gold a user can get in a certain range.