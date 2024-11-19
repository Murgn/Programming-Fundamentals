#pragma once

#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "AsciiGenerator.h"
#include "logging.h"
#include "Input.h"
#include "colors.h"
#include "ErrorHandler.h"

class Utilities
{
public:
	static void initRand();
	static int range(int minInclusive, int maxExclusive);
	static void strToLower(std::string& input);
	static void strToUpper(std::string& input);
	static void clear();
	static bool within(int num, int min, int max);
	static bool within(float num, float min, float max);

	// Taken from https://stackoverflow.com/a/61921163
	static void clearLines(int count);

	template<typename T> static T clamp(T num, T min, T max);
private:
	static bool randInit;
};

// Have to make this myself since std::clamp is implemented in C++17 and we are using C++14
template<typename T>
inline T Utilities::clamp(T num, T min, T max)
{
	const T temp = num < min ? min : num;
	return temp > max ? max : temp;
}
