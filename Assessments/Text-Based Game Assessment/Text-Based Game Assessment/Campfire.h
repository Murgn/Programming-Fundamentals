#pragma once
#include "State_Base.h"

class Campfire : public State_Base
{
public:
	void main() override;
private:
	std::string campfireMessages[9] = {
		"The warmth of the fire wraps around you",
		"Flickering flames cast dancing shadows on the ground.",
		"The scent of burning wood mixes with.",
		"The fire's heat chases away the evening chill.",
		"Crackling flames offer a moment of peace.",
		"Heat from the fire seeps into your bones.",
		"The flames sway, casting a golden light.",
		"The crackle of the fire breaks the silence of the night.",
		"A comforting warmth radiates from the campfire."
	};
};