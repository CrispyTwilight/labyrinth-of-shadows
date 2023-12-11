// Date: 11/27/2023
// Auth: John O'Neal, William Brickner, Christian Botos, Hunter Kauffman, Christian Baack.
// Desc: Main for final project.
#include "All_Includes.h"

// Prototypes
void testDriver();
void mapDriver();
void shopDriver();

// Initialization stuff
Shop* Shop::instance = nullptr; // JPO: Needed to initialize the static instance variable for the shop.
GameManager game;

int main()
{
   
    srand(time(0)); // JPO: Moved from Dice.h to so  it is only called once. Was causing issues with randomness in the shop.
    testDriver();
    return 0;
}

// JPO: This function asks which test to drive.
void testDriver() {
    char choice = '0'; // Default value to enter the loop

    // Start a loop that will run until the user presses q
    while (choice != 'q') {
        // Welcome and menu
        cout << "Pick an option to test:\n"
            << "1. Test Map\n"
            << "2. Test Shop\n"
            << "q. Quit\n"
            << "Choice: ";
        choice = _getch();

        switch (choice) {
        case '1':
            mapDriver();
            break;
        case '2':
            shopDriver();
            break;
        case 'q':
            cout << "Quitting..." << endl;
            return;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
        if (choice != 'q') {
            system("pause");
            system("cls");
        }
    }
}

// JPO: This function drives the map.
void mapDriver() {
    //Game objects
    Map gameMap(51, 31); // JPO: Updated so that the @ is can actually be in the middle of the map.
    Player player(gameMap, 25, 15); // JPO: Updated so that the player starts in the middle of the map.

    //Infinite loop right now, will need a menu.
    while (true)
    {
        srand(time(NULL));
        //This clears the cli
        setCursorPosition(0, 0);

        //Update player's position on the map
        int playerX, playerY;

        player.getPosition(playerX, playerY);
        gameMap.updatePlayerPosition(playerX, playerY);
        gameMap.display();

        gameMap.mapSwitcher();

        player.handleInput();

        gameMap.mapSwitcher();

        gameMap.moveL(playerY, playerX);
        gameMap.moveE();


        visual();
        if (gameMap.getTrigger())
        {
            gameMap.updateSpace(playerX, playerY, '.');

            //Calls the fighting.
            game.fighting(false);
            
            gameMap.toggle();

            system("cls");
        }
        if (gameMap.getTrigger2())
        {
            game.fighting(true);
        }

        //This is necessary to control speed of the game.
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}

// JPO: This function drives the shop for testing.
void shopDriver() {
    cout << endl << endl;
    Shop::getInstance()->runShop();
}