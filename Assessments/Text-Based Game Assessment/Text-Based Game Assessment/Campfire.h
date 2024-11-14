#pragma once
#include "State_Base.h"

class Campfire : public State_Base
{
public:
	// Inherited via State_Base
	void main() override;
};