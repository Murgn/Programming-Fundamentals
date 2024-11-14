#include "utilities.h"

int Utilities::range(int minInclusive, int maxExclusive)
{
	srand(time(0)); // Providing a new seed everytime
	return rand() % maxExclusive;
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
