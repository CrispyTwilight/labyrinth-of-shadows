// Date: 11/27/2023
// Auth: John O'Neal, William Brickner, Christian Botos, Hunter Kauffman, Christian Baack.
// Desc: Main for final project.
#include "All_Includes.h"

// Prototypes
void testDriver();
void mapDriver();
void shopDriver();

int main()
{
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
        choice = _getch(); // Get a single character from the user without echoing it to the console

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
        //This clears the cli
        setCursorPosition(0, 0);


        //Update player's position on the map
        int playerX, playerY;

        player.getPosition(playerX, playerY);
        gameMap.updatePlayerPosition(playerX, playerY);
        gameMap.display();

        //Updating other non static things on the map
        gameMap.updateNonStatic();

        gameMap.mapSwitcher();

        player.handleInput();

        visual();

        //This is necessary to control speed of the game.
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

// JPO: This function drives the shop for testing.
void shopDriver() {
    cout << endl << endl;
    Shop shop;
    shop.displayShopItems();
}