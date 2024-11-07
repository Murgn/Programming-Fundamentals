#pragma once

#include <cstdlib>
#include <ctime>
#include <iostream>

class Utilities
{
public:
	static int range(int minInclusive, int maxExclusive);
	static void strToLower(std::string& input);
	static void strToUpper(std::string& input);
};