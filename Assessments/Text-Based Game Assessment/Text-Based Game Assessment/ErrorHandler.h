#pragma once
#include <iostream>
#include "logging.h"
#include "utilities.h"

class ErrorHandler
{
public:
	static const void ClearInput();
	static const bool HandleError();
	static const bool HandleMenuCommand(const int command, const int min, const int max);
	static const bool HandleString(const std::string input);
private:
};
