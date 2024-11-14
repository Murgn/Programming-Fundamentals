#include "ErrorHandler.h"

const bool ErrorHandler::HandleError()
{
    if (std::cin.fail())
    {
        ClearInput();

        Logging::LogError("Invalid input, try again.");
        return true;
    }
    return false;
}

const void ErrorHandler::ClearInput()
{
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}
