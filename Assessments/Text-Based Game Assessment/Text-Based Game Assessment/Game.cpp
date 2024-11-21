#include "Game.h"

Game::GameStates Game::gameState = Game::GameStates::UNDEFINED;

Game::GameSettings Game::settings;
int Game::GameSettings::encounter = 1;
int Game::GameSettings::gold = 0;
std::vector<Game::Player> Game::GameSettings::party;

const std::string Game::directions[25] = 
{
			"Turn the corner",
			"Keep walking",
			"Go straight ahead",
			"Take the left path",
			"Take the right path",
			"Stop and look around",
			"Head towards the faint light",
			"Follow the trail of footprints",
			"Move towards the sound of dripping water",
			"Follow the flickering torches",
			"Stay close to the wall",
			"Choose the path with no footprints",
			"Ignore the whispering voices",
			"Cross the stone bridge",
			"Descend the staircase",
			"Ascend the staircase",
			"Fight through the vines blocking the path",
			"Follow the strange carvings on the wall",
			"Push through the heavy door",
			"Crawl through the opening",
			"Retrace your steps carefully",
			"Navigate through the mist",
			"Ignore the footsteps behind you",
			"Follow the sound of laughter",
			"Chase the echoes calling your name",
};

std::map<Game::Roles, std::string> Game::roleToStr =
{
	{Game::Roles::Human, "Human"},
	{Game::Roles::Knight, "Knight"},
	{Game::Roles::Archer, "Archer"},
	{Game::Roles::Wizard, "Wizard"}
};

std::map<Game::ItemType, std::string> Game::itemTypeToStr =
{
	{Game::ItemType::NoType, "None"},
	{Game::ItemType::Sword, "Sword"},
	{Game::ItemType::Bow, "Bow"},
	{Game::ItemType::Spell, "Spell"}
};

std::map<Game::Roles, Game::ItemType> Game::roleToItemType =
{
	{Game::Roles::Human, Game::ItemType::NoType},
	{Game::Roles::Knight, Game::ItemType::Sword},
	{Game::Roles::Archer, Game::ItemType::Bow},
	{Game::Roles::Wizard, Game::ItemType::Spell}
};

Game::Weapon Game::shopWeapons[30] =
{
		// Swords
		{ "Rusty Sword", Game::ItemType::Sword, 10, 5, Game::Roles::Knight, false },
		{ "Dagger", Game::ItemType::Sword, 20, 6, Game::Roles::Knight, false },
		{ "Old Longsword", Game::ItemType::Sword, 30, 7, Game::Roles::Knight, false },
		{ "Iron Blade", Game::ItemType::Sword, 40, 8, Game::Roles::Knight, false },
		{ "Flame Sword", Game::ItemType::Sword, 50, 9, Game::Roles::Knight, false },
		{ "Frost Sword", Game::ItemType::Sword, 60, 10 , Game::Roles::Knight, false },
		{ "Sunsteel Blade", Game::ItemType::Sword, 70, 11, Game::Roles::Knight, false },
		{ "Kingslayer", Game::ItemType::Sword, 80, 12, Game::Roles::Knight, false },
		{ "Lightbringer", Game::ItemType::Sword, 90, 13, Game::Roles::Knight, false },
		{ "Excalibur", Game::ItemType::Sword, 100, 15, Game::Roles::Knight, false },

		// Bows
		{ "Broken Bow", Game::ItemType::Bow, 10, 5, Game::Roles::Archer, false },
		{ "Wooden Bow", Game::ItemType::Bow, 20, 6, Game::Roles::Archer, false },
		{ "Old Longbow", Game::ItemType::Bow, 30, 7, Game::Roles::Archer, false },
		{ "Handmade Bow", Game::ItemType::Bow, 40, 8, Game::Roles::Archer, false },
		{ "Flame Bow", Game::ItemType::Bow, 50, 9, Game::Roles::Archer, false },
		{ "Frost Bow", Game::ItemType::Bow, 60, 10, Game::Roles::Archer, false },
		{ "Light Bow", Game::ItemType::Bow, 70, 11, Game::Roles::Archer, false },
		{ "Skyshot", Game::ItemType::Bow, 80, 12, Game::Roles::Archer, false },
		{ "Voidshot", Game::ItemType::Bow, 90, 13, Game::Roles::Archer, false },
		{ "Eternal Bow", Game::ItemType::Bow, 100, 15, Game::Roles::Archer, false },

		// Spells
		{ "Dull Flame", Game::ItemType::Spell, 10, 5, Game::Roles::Wizard, false },
		{ "Weak Bolt", Game::ItemType::Spell, 20, 6, Game::Roles::Wizard, false },
		{ "Frostspark", Game::ItemType::Spell, 30, 7, Game::Roles::Wizard, false },
		{ "Ember Glow", Game::ItemType::Spell, 40, 8, Game::Roles::Wizard, false },
		{ "Wind Gust", Game::ItemType::Spell, 50, 9, Game::Roles::Wizard, false },
		{ "Ice Barrage", Game::ItemType::Spell, 60, 10, Game::Roles::Wizard, false },
		{ "Thunderclap", Game::ItemType::Spell, 70, 11, Game::Roles::Wizard, false },
		{ "Soulfire Vortex", Game::ItemType::Spell, 80, 12, Game::Roles::Wizard, false },
		{ "Eternal Spark", Game::ItemType::Spell, 90, 13, Game::Roles::Wizard, false },
		{ "Starfall", Game::ItemType::Spell, 100, 15, Game::Roles::Wizard, false },
};

void Game::LogParty(bool printAscii)
{
	if (printAscii)
	{
		std::vector<std::string> partyText = AsciiGenerator::Generate("Party:", { Colors::BrightGreen, false });
		Logging::LogRepeat(partyText, 200);
		Logging::Log("___________________________________", Colors::Green);
		Logging::EndLine();
	}

	for (Game::Player player : Game::settings.party)
	{
		Logging::Log("\t" + player.name + " the " + Game::roleToStr[player.weapon.role]);
		Logging::Log("\t->   Health: " + std::to_string(player.health));
		Logging::Log("\t->   Weapon: " + player.weapon.name);
		Logging::Log("\t->   Damage: " + std::to_string(player.weapon.damage));
		Logging::Log("\t->   Type: " + Game::itemTypeToStr[player.weapon.itemType]);
		Logging::EndLine();
		if(Game::settings.party.size() > 1) Sleep(1000);
	}


	if (printAscii)
	{
		LogGold();
		Logging::Log("___________________________________", Colors::Green);
		Logging::EndLine();
		Sleep(1000);
	}

}

void Game::HealParty()
{
	for (Player& player : settings.party)
	{
		player.health = player.maxHealth;
	}
}

void Game::LogGold()
{
	Sleep(500);
	Logging::Log("   Your party currently has " + std::string(Colors::BrightYellow) + std::to_string(Game::settings.gold) + Colors::None + " gold!");
}

void Game::SplitChoice()
{
	int confirm = 0;
	int choices = Utilities::range(2, 4);
	std::vector<std::string> list(std::begin(directions), std::end(directions));

	for (int i = 1; i <= choices; i++)
	{
		int direction = Utilities::range(0, list.size());
		Logging::Log("-  (" + std::to_string(i) + ") " + directions[direction]);
		list.erase(list.begin() + direction);
	}

	while (true)
	{
		Input::Get<int>(confirm);

		if (ErrorHandler::HandleMenuCommand(confirm, 1, choices))
			continue;

		break;
	}
}
