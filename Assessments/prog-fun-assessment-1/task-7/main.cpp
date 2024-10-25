#include <iostream>
#include <string>
using namespace std;

// In this task, I learnt how to use enums in C++, I am used to C# so it took a while to learn
// that I have to use :: to pick an enum type, the same way I do with namespaces.
// I also originally tried to have a "None" value in both Roles and ItemType, but learnt that it creates an error,
// So i had to rename them to NoRole and NoType.

enum Roles 
{
    NoRole,
    Knight,
    Archer,
    Spearman
};

enum ItemType 
{
    NoType,
    Sword,
    Bow,
    Spear
};

struct Weapon
{
    string name = "";
    ItemType itemType = ItemType::NoType;
    int price = 0;
    int damage = 0;
    Roles role = Roles::NoRole;
    bool bought = false;
};

struct Player 
{
    string name = "";
    Weapon weapon;
};

const unsigned int playerCount = 3;
Player players[playerCount];
Weapon weapons[] = {
    { "Great Sword", ItemType::Sword, 40, 100, Roles::Knight },
    { "Scimitar", ItemType::Sword, 35, 75, Roles::Knight },
    { "Dagger", ItemType::Sword, 10, 35, Roles::Knight },
    { "Longbow", ItemType::Bow, 20, 55, Roles::Archer },
    { "Crossbow", ItemType::Bow, 40, 100, Roles::Archer },
    { "Rusty Spear", ItemType::Spear, 10, 35, Roles::Spearman },
    { "Iron Spear", ItemType::Spear, 20, 65, Roles::Spearman },
};

unsigned int coins = 100;

int main(int argc, char* argv[])
{
    for (int i = 0; i < playerCount; i++)
    {
        cout << "Enter Player #" << i + 1 << "'s Name: ";
        string name = "";
        getline(cin, name);
        players[i].name = name;
    }

    while (true)
    {
        string welcome = "Welcome ";
        // I have to use a for loop here and not a foreach loop as I need to know what iteration im on.
        for (int i = 0; i < playerCount; i++)
            welcome += players[i].name + (i == playerCount - 1 ? " " : i == playerCount - 2 ? " and " : ", ");
        cout << endl << welcome << "to the shop!" << endl;

        cout << "You currently have " << coins << " coins. You can buy the following items:" << endl;

        // This is another method I could use to work out what iteration I am on using a foreach loop
        int i = 0;
        for (Weapon weapon : weapons)
        {
            cout << i + 1 << ". " << weapon.name << " [" << weapon.price << " coins, " << weapon.damage << " damage]" << endl;
            i++;
        }

        for (Player player : players)
        {
            while (true)
            {
                cout << player.name << ", Please enter a weapon to buy: ";
                unsigned int input = 0;
                cin >> input;

                // Error Handling
                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(1000, '\n');

                    cerr << "[!] Invalid input, try again." << endl;
                    continue;
                }

                if ((input - 1 < sizeof(weapons) / sizeof(Weapon) && input > -1))
                {
                    cerr << "[!] Invalid input, please choose a valid item to purchase, try again." << endl;
                    continue;
                }

            }
        }
    }

    return 0;
}