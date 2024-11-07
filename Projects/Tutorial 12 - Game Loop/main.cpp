#include "main.h"

int main()
{
    while (true)
    {
        int input = -1;
        Choose(input);

        int cpuInput = -1;
        cpuInput = Utilities::range(0, 3);

        cout << endl << "Rock!" << endl;
        Sleep(500);
        cout << "Paper!" << endl;
        Sleep(500);
        cout << "Scissors!" << endl;
        Sleep(500);
        cout << "Shoot!" << endl << endl;
        Sleep(500);

        cout << "You used: " << numToRPS[input] << endl;
        cout << "CPU used: " << numToRPS[cpuInput] << endl << endl;
        Sleep(1000);

        Decide(input, cpuInput);
        Sleep(1000);

        cout << "You have played: " << gameStats.totalGames << " games..." << endl;
        cout << "Where you have won: " << gameStats.wins << " times," << endl;
        cout << "And the CPU has won: " << gameStats.cpuWins << " times!" << endl << endl;
        Sleep(500);

        cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << endl << endl;
    }
}

void Choose(int& input)
{
    while (true)
    {
        cout << "What hand would you like to play? (Rock/Paper/Scissors): ";

        string selection;
        cin >> selection;
        if (HandHandling(selection)) continue;
        input = rpsToNum[selection];
        break;
    }
}

void Decide(int& input, int& cpuInput)
{
    if (input == 0)
    {
        if (cpuInput == 0) Result(Results::Tie);

        else if (cpuInput == 1) Result(Results::Lost);

        else if (cpuInput == 2) Result(Results::Win);
    }

    else if (input == 1)
    {
        if (cpuInput == 0) Result(Results::Win);

        else if (cpuInput == 1) Result(Results::Tie);

        else if (cpuInput == 2) Result(Results::Lost);
    }

    else if (input == 2)
    {
        if (cpuInput == 0) Result(Results::Lost);

        else if (cpuInput == 1) Result(Results::Win);

        else if (cpuInput == 2) Result(Results::Tie);
    }
}

void Result(const Results result)
{
    switch (result)
    {
        case Results::Win:
            cout << "Congratulations, you won!" << endl << endl;
            gameStats.totalGames++;
            gameStats.wins++;
            return;

        case Results::Tie:
            gameStats.totalGames++;
            cout << "Close one, you tied!" << endl << endl;
            return;

        case Results::Lost:
            cout << "Aww, you lost!" << endl << endl;
            gameStats.totalGames++;
            gameStats.cpuWins++;
            return;
    }
}

void ClearInput()
{
    cin.clear();
    cin.ignore(1000, '\n');
}

bool ErrorHandling()
{
    if (cin.fail())
    {
        ClearInput();
        cerr << "[!] Invalid input, try again." << endl;
        return true;
    }
}

bool HandHandling(string& input)
{
    if (ErrorHandling()) return true;

    Utilities::strToLower(input);

    if (!(input == "rock" || input == "paper" || input == "scissors"))
    {
        ClearInput();
        cerr << "[!] Invalid selection, try again." << endl;
        return true;
    }

    return false;
}