#include <iostream>
#include <Windows.h>
using namespace std;

void input();

int main()
{
	cout << boolalpha; // Turns 0 and 1 into false and true

	int countdown = 0;
	cout << "What number should we countdown from? " << endl;
	cin >> countdown;

	if (countdown < 5) countdown = 5;


	while (countdown > 0 || cin.fail())
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
		}

		cout << "T-" << countdown << endl;
		countdown--;
		Sleep(1000);
	}

	cout << "Blast off!" << endl;

	// -------------------------------------------------------

	input();

	// -------------------------------------------------------

	int numbers = 0;
	int i = 0;

	cout << "Give me lots of numbers, use a negative number to finish: " << endl;

	while (true)
	{
		int num;
		cout << "Number " << i + 1 << ": ";
		cin >> num;
		cout << endl;

		numbers += num;
		i++;

		if (num < 0)
		{
			cout << "The sum of all of your numbers is: " << numbers << endl;
			cout << "The mean of all of your numbers is: " << numbers / i << endl;
			break;
		}
	}

	// -------------------------------------------------------

	for (int i = 1; i <= 10; i++)
	{
		if (i == 5 || i == 7) continue;
		cout << i << endl;
	}

	// -------------------------------------------------------
}

void input()
{
	string text;
	cout << "Beep Boop. Input Required:" << endl;
	cin >> text;

	if (text == "hi")
		cout << "Hello!";
	else if (text == "joke")
	{
		cout << "What's a robot's favourite type of music?" << endl;
		Sleep(1000);
		for (int i = 0; i < 3; i++)
		{
			cout << ".";
			Sleep(1000);
		}
		cout << endl;
		cout << "Heavy metal!!" << endl;
		for (int i = 0; i < 3; i++)
		{
			cout << "Ha!" << endl;
			Sleep(1000);
		}
	}
	else if (text == "quit" || text == "exit" || text == "stop")
		cout << "Terminating RoboBot-9000" << endl << "Goodbye." << endl;
	else
	{
		cout << "Input not recognised, please try again." << endl;
		input();
	}
}