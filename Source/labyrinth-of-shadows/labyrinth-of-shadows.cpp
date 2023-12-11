// Date: 11/27/2023
// Auth: John O'Neal, William Brickner, Christian Botos, Hunter Kauffman, Christian Baack.
// Desc: Main for final project.
#include "All_Includes.h"

// Prototypes
void testDriver();
void gameDriver();
void shopDriver();
void screenDriver();


// Initialization stuff
Shop* Shop::instance = nullptr; // JPO: Needed to initialize the static instance variable for the shop.

int main()
{
    srand(time(0)); // JPO: Moved from Dice.h to so  it is only called once. Was causing issues with randomness in the shop.
    testDriver();
    return 0;
}

// JPO: This function asks which test to drive.
void testDriver() {
    char choice;
    do {
        // Welcome and menu
        cout << "Pick an option to test:\n"
            << "1) Test full game\n"
            << "2) Test Shop\n"
            << "3) Test Screens\n"
            << "ESC) Quit\n"
            << "Choice: ";
        choice = _getch();

        switch (choice) {
            case '1':
                gameDriver();
                break;
            case '2':
                shopDriver();
                break;
            case '3':
                system("cls");
                screenDriver();
			    break;
            case 27:
                cout << "Quitting..." << endl;
                return;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
            }
        if (choice != 27) {
            system("pause");
            system("cls");
        }
    } while (true);
}

// JPO: This function drives the map.
void gameDriver() {
    GameManager game;
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

void screenDriver() {
    Screens screens;
    char choice;
    do {
        cout << "Pick an option to test:\n"
            << "1) Title Screen\n"
            << "2) Death Screen\n"
            << "3) Victory Screen\n"
            << "4) Help Screen\n"
            << "ESC) Quit\n";

        choice = _getch();
        switch (choice) {
        case '1':
            screens.showTitle();
            screens.processMainMenu();
            break;
        case '2':
            screens.showDeath();
            break;
        case '3':
            screens.showVictory();
            break;
        case '4':
            screens.showHelp();
            break;
        case 27 :
            return;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
        if (choice != 27) {
			system("pause");
			system("cls");
		}
    } while (choice != 27);
}