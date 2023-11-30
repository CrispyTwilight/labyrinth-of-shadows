//Auth: Will
//Date: 11/30/2023
//Desc: Creating a superclass for the player, npcs, and enemies
#include <iostream>
#include <string>
using namespace std;

class Character
{
private:
    //Fields
    int health;
    string name;
public:
//Setters
void setHealth(int value)
{
    health = value;
}
void setName(string n)
{
    name = n;
}
//Getters
int getHealth()
{
    return health;
}

string getName()
{
    return name;
}
};
