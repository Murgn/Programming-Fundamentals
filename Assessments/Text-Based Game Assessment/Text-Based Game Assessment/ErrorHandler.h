#pragma once
#include "./Game.h"
#include "utilities.h"

class ErrorHandler
{
public:
	static const void ClearInput();
	static const bool HandleError();
	static const bool HandleMenuCommand(const int command, const int min, const int max);
	static const bool HandleString(const std::string input);
	//static const bool HandleShopCommand(const Game::Weapon weapon);
private:
};
