#pragma once
#include <iostream>
#include "colors.h"

// Errors are for players, Warnings are for me
class Logging
{
public:
	static const void LogError(const std::string& output);
	static const void LogWarning(const std::string& output);
};