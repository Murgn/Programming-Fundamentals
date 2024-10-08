#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    cout << boolalpha; // Turns 0 and 1 into false and true

    bool a = 5 < 1;
    cout << a << endl; // False 0
    bool b = 5 > 1;
    cout << b << endl; // True 1
    bool c = 5 == 1;
    cout << c << endl; // False 0
    bool d = 90 != 90;
    cout << d << endl; // False 0
    bool e = (-5 * 2) == (5 * 2);
    cout << e << endl; // False 0

    // -------------------------------------------------------

    float grade;
    cout << "What's your grade percentage?: ";
    cin >> grade;
    
    bool passed = grade >= 40;

    string classification;
    if (grade >= 70) classification = "First class grade";
    else if (grade >= 60) classification = "Upper Second class grade";
    else if (grade >= 50) classification = "Lower second class grade";

    cout << endl;
    string passedText = "You passed with a: " + classification;
    cout << (passed ? passedText : "You failed. :(");
    cout << endl << endl;

    // -------------------------------------------------------

    string name;
    bool isBob;

    cout << "What's your name?" << endl;
    cin >> name;

    isBob = name == "bob" || name == "Bob";

    cout << (isBob ? "YOU ARE BOB!!!" : "You aren't bob...") << endl;

    // With these two, I think it's comparing the number value of each letter added together. 

    bool f = "bob" > "car";
    cout << f << endl;

    bool g = "bob" < "car";
    cout << g << endl;


    // -------------------------------------------------------

    int playerAmmo;
    const int MAX_AMMO = 10;
    bool isPlayerOutOfAmmo = false;

    playerAmmo = MAX_AMMO; // Reloading the gun

    while (!isPlayerOutOfAmmo)
    {
        playerAmmo--;
        cout << "Bang! " << playerAmmo << '/' << MAX_AMMO << endl;;
        isPlayerOutOfAmmo = playerAmmo == 0;
        cout << "Is player out of ammo? " << isPlayerOutOfAmmo << endl;
        Sleep(1000);
    }

    // -------------------------------------------------------

    cout << !false << endl; // True 1
    cout << !true << endl; // False 0

    int num;
    cout << "Give me a random number: " << endl;
    cin >> num;
    bool between = num >= 70 && num <= 100;
    cout << "Your number " << (between ? "is " : "not ") << "between 70 & 100!";
}
