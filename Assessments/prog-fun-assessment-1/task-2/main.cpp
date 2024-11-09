 #include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    string name, username, clantag;
    unsigned int exp, currentLevel = 0;

    cout << "What's your name?: ";

    // We were taught that this can be used to read more than one word of input, however
    // We weren't told what library getline was found in, so I started researching myself
    // and found out that getline can be found by including the string library.
    getline(cin, name);
    cout << endl;

    cout << "What's your username?: ";
    getline(cin, username);
    cout << endl;

    cout << "What's your clantag?: ";
    getline(cin, clantag);
    cout << endl;

    cout << "How much exp do you have?: ";
    cin >> exp;
    cout << endl;

    cout << "Your name is " << name << " and your in-game name is [" << clantag << "]" << username << "." << endl;
    cout << "You have " << exp << " experience points." << endl;

    currentLevel = exp / 100;
    cout << "You are level " << currentLevel << "." << endl;
    cout << "You need " << 100 - (exp % 100) << " more exp to reach the next level, which would be level " << currentLevel + 1 << endl;

    return 0;
}