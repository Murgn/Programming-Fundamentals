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
