#pragma once
#include "colors.h"
#include "utilities.h"
#include "AsciiGenerator.h"
#include "logging.h"

class State_Base 
{
public:
	virtual void main() = 0;
};