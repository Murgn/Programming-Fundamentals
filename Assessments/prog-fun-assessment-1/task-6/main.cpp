#include "main.h"

using namespace std;

int main(int argc, char* argv[])
{
    int num = random(0, 100);
    cout << "Psst! The correct answer is " << num << endl;

    while (true)
    {
        int guess = 0;

        cout << "Enter a guess: ";
        cin >> guess;

        // Error Handling
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');

            cerr << "[!] Invalid input, try again." << endl;

            continue;
        }
    }

    return 0;
}