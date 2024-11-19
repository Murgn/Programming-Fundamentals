#include "utilities.h"


bool Utilities::randInit = false;

// Need to call this at start of every program
void Utilities::initRand()
{
	srand(time(0));
	Utilities::randInit = true;
}

int Utilities::range(int minInclusive, int maxExclusive)
{
	if (!Utilities::randInit)
	{
		std::cout << "\033[0;31mrand has not been init\033[0m" << std::endl;
		return 0;
	}
	return minInclusive + rand() % (maxExclusive - minInclusive);
}

void Utilities::strToLower(std::string& input)
{
	std::string temp;

	for (char c : input)
		temp += std::tolower(c);

	input = temp;
}

void Utilities::strToUpper(std::string& input)
{
	std::string temp;

	for (char c : input)
		temp += std::toupper(c);

	input = temp;
}

void Utilities::clear() { system("CLS"); }

bool Utilities::within(int num, int min, int max)
{
	return min <= num && max >= num;
}

bool Utilities::within(float num, float min, float max)
{
	return min <= num && max >= num;
}

// Erases `count` lines, including the current line
void Utilities::clearLines(int count) {
	if (count > 0) {
		std::cout << "\x1b[2K"; // Delete current line
		// i=1 because we included the first line
		for (int i = 1; i < count; i++) {
			std::cout
				<< "\x1b[1A" // Move cursor up one
				<< "\x1b[2K"; // Delete the entire line
		}
		std::cout << "\r"; // Resume the cursor at beginning of line
	}
}
