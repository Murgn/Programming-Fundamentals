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
	static int range(int minInclusive, int maxExclusive);
	static void strToLower(std::string& input);
	static void strToUpper(std::string& input);
	static void clear();
	static bool within(int num, int min, int max);
	static bool within(float num, float min, float max);

};