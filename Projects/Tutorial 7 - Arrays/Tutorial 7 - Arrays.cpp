#include <iostream>
using namespace std;

struct Player
{
	string name;
	unsigned int age;
};

int main()
{
	int numbers[3] = { -5, -10, -15 };

	for (int num : numbers) cout << num << endl;

	// -------------------------------------------------------

	Player players[4] = {
		{"Morgan", 19},
		{"Dan", 21},
		{"Alice", 19},
		{"Jay", 19}
	};

	// -------------------------------------------------------

	float floats[100] = { 0.0 };

	for (float f : floats)
	{
		cout << f << ", ";
	}

	cout << endl;

	// -------------------------------------------------------

	bool boolean[] = { true };

	cout << boolean[5] << endl;
	cout << boolean[-1] << endl;

	// -------------------------------------------------------

	cout << sizeof(players) << ", " << _countof(players) << endl;
}