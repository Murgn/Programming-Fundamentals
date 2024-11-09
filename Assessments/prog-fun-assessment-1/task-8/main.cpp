#include "main.h"

int main(int argc, char* argv[])
{
    while (true)
    {
        // Setting up, which allows us to restart without complications.
        bool restart = false;
        inventory.clear();

        cout << "- Please enter an inventory size (1-16): ";
        cin >> inventorySize;
        if (IntCheck(inventorySize, 1, 16)) continue;

        for (int i = 0; i < inventorySize; i++)
            inventory.push_back(0);

        cout << ">> Initialised inventory with " << inventory.size() << " slots." << endl;
        cout << ">> Type \"help\" for a list of all commands." << endl;

        while (true)
        {
            cout << "- ";
            string command = "";

            cin >> command;

            int selected = CommandCheck(command);
            if (selected == -1) continue;

            // In some cases I have to surround them in brackets, this is to make sure the variables I define
            // in each case are restricted to their respective scope.
            switch (selected)
            {
            case 0: // view 
            {
                // A problem with implementing commands with paramaters this way is that 
                // if the user doesn't supply a param, it asks for an input on the next line without
                // prompting them for any input. It looks like a bug and is confusing however I haven't found
                // a better way to implement this yet.
                int param1 = 0;
                cin >> param1;
                if (IntCheck(param1, 1, inventorySize)) break;

                cout << ">> - Slot " << param1 << ": " << items[inventory[param1 - 1]] << endl;
                break;
            }
            case 1: // show_all
            {
                int i = 0;
                cout << ">> Inventory: " << endl;
                for (int item : inventory)
                {
                    cout << ">> - Slot " << i + 1 << ": " << items[item] << endl;
                    i++;
                }
                break;
            }
            case 2: // set
            {
                int param1 = 0;
                int param2 = 0;
                cin >> param1;
                cin >> param2;
                if (IntCheck(param1, 1, inventorySize) || IntCheck(param2, 0, sizeof(items) / sizeof(items[0]) - 1)) break;
                inventory[param1 - 1] = param2;
                cout << ">> Set Slot " << param1 << " to item: " << items[param2] << endl;
                break;
            }
            case 3: // search_item
            {
                string param1 = "";
                vector<Vector2> results;

                cin >> param1;
                if (ErrorCheck()) break;

                int i = 0;
                for (int item : inventory)
                {
                    if (ToLower(items[item]).find(ToLower(param1)) != string::npos)
                        results.push_back(Vector2{i, item});

                    i++;
                }

                cout << ">> Search results: " << endl;
                for (Vector2 result : results)
                {
                    cout << ">> - Item index " << result.x + 1 << ": " << items[result.y] << endl;
                }
                break;
            }
            case 4: // items
            {
                int i = 0;
                for (string item : items)
                {
                    cout << ">> " << i << ": " << item << endl;
                    i++;
                }
                break;
            }
            case 5: // exit
                cout << ">> Exiting..." << endl;
                return 0;
            case 6: // restart
                cout << ">> Restarting... " << endl;
                restart = true;
                break;
            case 7: // help

                for (Command command : commands)
                {
                    string output = "";
                    output += "\t- ";
                    output += command.name;
                    for (string param : command.parameters)
                    {
                        output += " <";
                        output += param;
                        output += ">";
                    }
                    output += ": ";
                    output += command.description;

                    cout << output << endl;
                }
                break;
            case 8: // clear
                inventory.clear();
                cout << ">> Cleared inventory" << endl;
                break;
            }

            if (restart) break;
        }

        if (restart) continue;
    }

    return 0;
}

bool ErrorCheck()
{
    if (cin.fail())
    {
        ClearInput();

        cerr << warn << "Invalid input, try again." << endl;
        return true;
    }

    return false;
}

bool IntCheck(int input, int min, int max)
{
    if (ErrorCheck()) return true;
    else if (!(min <= input && max >= input))
    {
        ClearInput();

        cerr << warn << "Input out of range, try again." << endl;
        return true;
    }

    return false;
}

int CommandCheck(string input)
{
    if (ErrorCheck()) return -1;

    // I wanted to try and optimise here, originally I had a boolean which would check if input == command.name
    // But then I realised that i could use my i variable which I would need regardless to also take on the role
    // of a boolean.
    int i = 0;
    for (Command command : commands)
    {
        if (ToLower(input) == command.name) break;
        i++;
    }

    // i == 9 means the command is out of range / not recognised.
    if (i == 9)
    {
        cerr << warn << "Command not recognised, try again." << endl;
        return -1;
    }

    //cout << "Received command: " << i << endl;
    return i;
}

void ClearInput()
{
    cin.clear();
    cin.ignore(1000, '\n');
}

string ToLower(string input)
{
    string lower = "";
    for (char c : input)
        lower += tolower(c);

    return lower;
}