#pragma once
#include "utilities.h"
#include "Game.h"
#include "ErrorHandler.h"

class State_Base 
{
public:
	virtual void main() = 0;
};