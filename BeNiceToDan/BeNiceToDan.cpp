#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    while (true)
    {
        // you can loop k higher to see more color choices
        for (int k = 1; k < 255; k++)
        {
            // pick the colorattribute k you want
            SetConsoleTextAttribute(hConsole, k);
            cout << " I'm going to be nice to dan today" << endl;
            Sleep(10);
        }
    }
}
