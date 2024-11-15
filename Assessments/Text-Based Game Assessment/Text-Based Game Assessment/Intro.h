#pragma once
#include "State_Base.h"

class Intro : public State_Base
{
public:
	void main() override;
private:
	bool HandleMenuCommand(const int command, const int min, const int max);
	void NewGame();
	void LoadGame();
	void Quit();
};