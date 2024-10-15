#include <iostream>
#include <Windows.h>
#include <random>

using namespace std;

int Square(int num);
int MultiplyByThree(int num);
void DadJoke();
int Multiply(int a, int b);
int Add(int a, int b);
void PrintName();
bool IsEven(int num);

int main()
{
    cout << boolalpha; // Turns 0 and 1 into false and true

    cout << Square(2) << endl;
    cout << Square(10) << endl;
    cout << Square(20) << endl;
    cout << Square(25) << endl;
    cout << Square(35) << endl;
    cout << Square(40) << endl;

    // -------------------------------------------------------

    cout << MultiplyByThree(3) << endl;
    cout << MultiplyByThree(6) << endl;
    cout << MultiplyByThree(10) << endl;

    // -------------------------------------------------------

    Sleep(1000);
    DadJoke();

    // -------------------------------------------------------

    cout << "2384 * 2497 = " << Multiply(2384, 2497) << endl;
    cout << "64 + 32 = " << Add(64, 32) << endl;
    PrintName();
    int number = 0;

    cout << "Tell me a random number!" << endl;
    cin >> number;
    cout << "Is " << number << " an even number? " << (IsEven(number) ? "Yes it is!" : "No it's not!") << endl;

    // -------------------------------------------------------

    cout << powf(2, 3) << endl; // Power to
    cout << sqrtf(8) << endl; // Square root
    cout << fabsf(-8) << endl; // Returns the absolute number, turns negative numbers positive
    cout << sinf(8) << endl; // Sine 
    cout << cosf(8) << endl; // Cos

    // -------------------------------------------------------

    for (int i = 0; i < 5; i++)
    {
        MessageBeep(0xFFFFFFFF);
        Sleep(500);
        MessageBeep(0x00000010L);
        Sleep(500);
        MessageBeep(100);
        Sleep(500);
    }

    MessageBoxA(0, "hello there", "a title", 0);

    for (int i = 0; i < 10; i++)
    {
        cout << GetTickCount() << endl;
    }
    
    while (true)
    {
        HDC dc = GetDC(GetDesktopWindow());
        Rectangle(dc, 100, 100, 200, 200);
    }

}

int Square(int num) 
{
    return num * num;
}

int MultiplyByThree(int num) { return num * 3; }

void DadJoke()
{
    cout << "What do you call a man with no shins?" << endl;
    Sleep(1000);
    for (int i = 0; i < 3; i++)
    {
        cout << ".";
        Sleep(1000);
    }
    cout << endl << "Tony!" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "ha!";
        Sleep(300);
    }
    cout << endl;
}

int Multiply(int a, int b) { return a * b; }
int Add(int a, int b) { return a + b; }
void PrintName() { cout << "My name is Morgan Murphy!" << endl; }
bool IsEven(int num) { return num % 2 == 0; }


