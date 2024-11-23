#include "ErrorHandler.h"

const void ErrorHandler::ClearInput()
{
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}

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

const bool ErrorHandler::HandleMenuCommand(const int command, const int min, const int max)
{
    if (ErrorHandler::HandleError()) return true;
    else if (!Utilities::within(command, min, max))
    {
        ErrorHandler::ClearInput();
        Logging::LogError("Input out of range, try again.");

        return true;
    }
    return false;
}

const bool ErrorHandler::HandleString(const std::string input)
{
    if (ErrorHandler::HandleError()) return true;
    else if (input.empty())
    {
        ErrorHandler::ClearInput();
        Logging::LogError("Please provide an input, try again.");

        return true;
    }
    return false;
}

//const bool ErrorHandler::HandleShopCommand(const Game::Weapon weapon)
//{
//    if (ErrorHandler::HandleError()) return true;
//    else if (weapon.bought)
//    {
//        ErrorHandler::ClearInput();
//        Logging::LogError("This weapon has already been bought, try again.");
//
//        return true;
//    }
//    else if (Game::settings.gold >= weapon.price)
//    {
//        ErrorHandler::ClearInput();
//        Logging::LogError("You don't have enough gold, try again.");
//
//        return true;
//    }
//    return false;
//}
