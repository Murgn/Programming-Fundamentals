#pragma once
#include "State_Base.h"

class Intro : public State_Base
{
public:
	void main() override;
private:
	void NewGame();
	void LoadGame();
	void Quit();
};