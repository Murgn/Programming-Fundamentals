#pragma once
#include "utilities.h"
#include "main.h"

class State_Base 
{
public:
	GameSettings settings;

	State_Base(GameSettings settings)
	{
		this->settings = settings;
	}

	virtual void main() = 0;
};