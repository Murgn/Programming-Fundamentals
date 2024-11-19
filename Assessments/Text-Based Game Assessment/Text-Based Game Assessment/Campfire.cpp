#include "Campfire.h"

void Campfire::main()
{
	Utilities::clear();
	Logging::Log(campfireMessages[Utilities::range(0, sizeof(campfireMessages) / sizeof(campfireMessages))], Colors::BrightYellow);

	for (Game::Player& player : Game::settings.party)
	{
		int increase = Utilities::range(0, 1);
		if (increase)
		{
			player.maxHealth += increase;
			Logging::Log("   " + player.name + " the " + Game::roleToStr[player.weapon.role] + "'s max health was increased by " + std::to_string(increase) + "!");
		}
		else
		{
			Logging::Log("   " + player.name + " the " + Game::roleToStr[player.weapon.role] + " max health wasn't increased!", Colors::BrightBlack);
		}
		Game::
		Logging
	}
}
