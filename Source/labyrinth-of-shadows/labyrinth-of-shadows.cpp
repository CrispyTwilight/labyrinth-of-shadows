// Date: 11/27/2023
// Auth: John O'Neal, William Brickner, Christian Botos, Hunter Kauffman, Christian Baack.
// Desc: Main client for final project.
#include "All_Includes.h"

// This function is where the program starts.
int main()
{
    srand(time(0)); // JPO: Moved from Dice.h to so  it is only called once. Was causing issues with randomness in the shop.
    GameManager game;
    game.processMainMenu();
    return 0;
};
/*

// Prototypes
void testDriver();
void gameDriver();
void shopDriver();
void screenDriver();

// JPO: This function asks which test to drive.
void testDriver() {
    char choice;
    do {
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
};

// JPO: This function drives the map.
void gameDriver() {
    GameManager game;
    game.processMainMenu();
};

// JPO: This function drives the shop for testing.
void shopDriver() {
    Shop::getInstance()->runShop();
};

// JPO: This function drives the screens for testing.
void screenDriver() {
    system("cls");
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
            // screens.processMainMenu(); broken
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
        case 27:
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
};
*/