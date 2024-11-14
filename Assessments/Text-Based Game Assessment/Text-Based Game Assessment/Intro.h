#pragma once
#include "State_Base.h"

class Intro : public State_Base
{
public:
	// Inherited via State_Base
	void main() override;
private:
	bool HandleMenuCommand(const int command);
	void NewGame();
	void LoadGame();
	void Quit();
};