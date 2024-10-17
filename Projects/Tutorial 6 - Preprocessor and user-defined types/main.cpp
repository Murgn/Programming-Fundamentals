#include <iostream>
#include "Windows.h"
#include "Math.h"
#include "Console.h"


using namespace std;

#define PI 3.141592
#define DEGREES * 0.0174533
#define COUNTDOWN for (int i = 0; i < 10; i++) { cout << i << endl; }
#define PRINT cout <<
#define FORLOOP(a, b) for (int i = a; i < b; i++) { cout << i << endl; }

int main()
{

    std::cout << Add(1, 3) << endl;
    std::cout << Multiply(1, 3) << endl;
    std::cout << Subtract(1, 3) << endl;

    // -------------------------------------------------------

    cout << "a";
    SetCursor(10, 10);
    cout << "b";
    SetCursor(20, 20);
    cout << "c" << endl;
    for (int i = 0; i < 20; i++)
    {
        cout << "spam " << i << endl;
    }
    ClearRows(20); 
    // For some reason I can't get ClearRows() to work, when I call the function nothing happens.
    // I also looked through the escape sequences documentation to find the right code and it says
    // "Deletes <n> lines from the buffer, starting with the row the cursor is on.", however it doesn't do this.

    // -------------------------------------------------------

    //SetWindowColor("FF/00/00");

    // -------------------------------------------------------

    cout << PI << endl;
    cout << 180 DEGREES << endl;
    COUNTDOWN
    PRINT "hi \n";
    PRINT "hello there \n";

    FORLOOP(0, 10)

    // -------------------------------------------------------
}