#pragma once
#include "State_Base.h"

class Encounter : public State_Base
{
public:
	// Inherited via State_Base
	void main() override;
};
