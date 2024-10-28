#include <iostream>
#include <string>
#include <Windows.h>
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

string RolesToString(int i);
void ClearInput();

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

        // Took me a while to bug fix this. I learn that the array im editing in a for each loop is a copy.
        // If I want to edit the original array I have to pass it in as a reference using the & operator.
        for (Player &player : players)
        {
            while (true)
            {
                cout << player.name << ", Please enter a weapon to buy: ";
                unsigned int input = 0;
                cin >> input;

                // Error Handling
                if (cin.fail())
                {
                    ClearInput();

                    cerr << "[!] Invalid input, try again." << endl;
                    continue;
                }
                int modifiedInput = input - 1;

                if (!(modifiedInput < sizeof(weapons) / sizeof(Weapon) && modifiedInput > -1))
                {
                    cerr << "[!] Invalid input, please choose a valid item to purchase, try again." << endl;
                    continue;
                }


                if (!weapons[modifiedInput].bought)
                {
                    if (coins >= weapons[modifiedInput].price)
                    {
                        weapons[modifiedInput].bought = true;
                        player.weapon = weapons[modifiedInput];
                        coins -= weapons[modifiedInput].price;
                        cout << player.name << " bought a " << weapons[modifiedInput].name << " for " << weapons[modifiedInput].price << " coins. The party now has " << coins << " coins." << endl;
                        break;
                    }
                    else
                    {
                        cerr << "[!] Invalid input, not enough coins, the " << weapons[modifiedInput].name << " is " << weapons[modifiedInput].price << " coins and the party only has " << coins << " coins. try again." << endl;
                        continue;
                    }
                }
                else 
                {
                    cerr << "[!] Invalid input, this weapon has already been bought, try again." << endl;
                    continue;
                }

            }
        }

        string confirmation = "";
        bool restart = false;
        ClearInput();
        while (true)
        {
            cout << "Is your party happy with your weapons? (yes/no): ";
            getline(cin, confirmation);
            if (confirmation == "yes") { break; }
            // I'm using a boolean and doing it this way because I'm not sure how to break out of this#
            // nested while loop and then continue the main while loop any other way.
            else if (confirmation == "no") { restart = true; break; }
            else 
            {
                cerr << "[!] Invalid input, unrecognised command, try again." << endl;
                continue;
            }
        }

        if (restart) continue;
        else break;
    }

    cout << "Your Party: " << endl;
    for (Player player : players)
    {
        cout << "\t" << player.name << " the " << RolesToString(player.weapon.role) << ". [Weapon: " << player.weapon.name << ", Damage: " << player.weapon.damage << "]" << endl;
    }

    string encounter = "You delve deeper into the forbidden forest. A monster appears...";

    for (char c : encounter) 
    {
        cout << c;
        Sleep(100);
    }

    return 0;
}

// Made a function to convert the roles enum numbers to strings.
string RolesToString(int i)
{
    switch (i)
    {
    default: return "No Role";
    case 1:
        return "Knight";
    case 2:
        return "Archer";
    case 3:
        return "Spearman";
    }
}

// I was having some issues with my party weapon confirmation auto-inputting and telling the
// player that there was an unrecognised command, so I made this function to clear the input
// buffer before we ask for a command.
void ClearInput()
{
    cin.clear();
    cin.ignore(1000, '\n');
}