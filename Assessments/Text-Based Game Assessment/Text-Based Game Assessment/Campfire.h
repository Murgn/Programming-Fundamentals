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

	std::string partyJoinMessages[10] = {
		" approaches the campfire and joins your party!",
		" steps into the light of the campfire and decides to join you!",
		" is drawn to the warmth of the fire and joins your party!",
		" sits by the campfire and pledges to aid you!",
		" finds their way to the campfire and becomes part of your party!",
		" approaches cautiously but agrees to join your journey!",
		" is lured by the flames and joins your quest!",
		" shares a quiet moment by the fire before joining your party!",
		" takes a seat by the fire and decides to join the adventure!",
		" steps out of the shadows and joins your party!"
	};

	void JoinParty();
};