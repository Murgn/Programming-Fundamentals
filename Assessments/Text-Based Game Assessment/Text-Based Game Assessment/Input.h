#pragma once
#include <iostream>
#include <string>
#include "logging.h"
#include "ErrorHandler.h"

class Input {
public:
	template<typename T> static const void Get(T& input);
	static const void Get(std::string& input);
};

template<typename T>
inline const void Input::Get(T& input)
{
	Logging::Log(">> ", false);
	std::cin >> input;
}

