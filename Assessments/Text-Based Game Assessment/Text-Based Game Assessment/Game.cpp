#include "Game.h"

Game::GameStates Game::gameState = Game::GameStates::UNDEFINED;

Game::GameSettings Game::settings;
int Game::GameSettings::encounter = 0;
std::vector<Game::Player> Game::GameSettings::party;

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
