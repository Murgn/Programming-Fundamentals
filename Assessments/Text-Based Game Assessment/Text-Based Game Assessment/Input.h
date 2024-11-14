#pragma once
#include <iostream>
#include "logging.h"

class Input {
public:
	template<typename T> static const void Get(T& input);
};

template<typename T>
inline const void Input::Get(T& input)
{
	Logging::Log(">> ", false);
	std::cin >> input;
}
