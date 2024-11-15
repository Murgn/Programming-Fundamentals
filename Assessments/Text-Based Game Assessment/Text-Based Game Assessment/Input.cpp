#include "Input.h"

const void Input::Get(std::string& input)
{
	ErrorHandler::ClearInput();
	Logging::Log(">> ", false);
	std::getline(std::cin, input);
}
