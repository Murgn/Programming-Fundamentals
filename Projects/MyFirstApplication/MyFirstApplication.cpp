
#include <iostream>


int main()
{
    std::cout << "-----------\nName: Morgan\nCourse: Games Design and Programming\nStudent ID: m018857n\n-----------";

	int triangle_size = 5;
	std::cout << "\nGive a triangle size:";
	std::cin >> triangle_size;
	
	for (int i = 0; i < triangle_size; i++)
	{
		std::cout << std::string(i + 1, '*');
		std::cout << "\n";
	}

	/*
	string wantBoat;
	std::cout << "Do you want a boat?";
	std::cin >> wantBoat;

	if (wantBoat == "No")
	{
		std::cout << "Okay, goodbye. >:(";
	}
	else
	{
		std::cout << std::string(triangle_size + 1, ' ') + '|' + "\n";
		std::cout << std::string((triangle_size * 3), '*');
		}
	*/

	std::cout << "2 + 2" << " = " << "4";

}
