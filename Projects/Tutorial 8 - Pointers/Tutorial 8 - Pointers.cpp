 #include <iostream>
using namespace std;

int main()
{
    int integer = 10;
    bool boolean = true;
    float floating = 2.5;
 
    int* intptr = nullptr;
    bool* boolptr = nullptr;
    float* floatptr = nullptr;

    // -------------------------------------------------------

    float player1Health = 50.0f;
    float player2Health = 25.0f;
    cout << "player1Health: " << player1Health << endl;
    cout << "player2Health: " << player2Health << endl;

    float* currentHealth = &player1Health;
    cout << "currentHealth Address: " << currentHealth << " player1Health Address: " << &player1Health << endl;
    currentHealth = &player2Health;
    cout << "currentHealth Address: " << currentHealth << " player1Health Address: " << &player2Health << endl;




}
