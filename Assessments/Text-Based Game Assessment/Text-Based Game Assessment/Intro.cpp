#include "Intro.h"

void Intro::main()
{
	Logging::LogRepeat("Welcome to...", 100);

	std::vector<std::string> ascii1 = AsciiGenerator::Generate("Wisteria\'s", { Colors::BrightPurple, false });
	ascii1.pop_back();
	std::vector<std::string> ascii2 = AsciiGenerator::Generate("Labyrinth", { Colors::Purple, false });
	ascii1.insert(ascii1.end(), ascii2.begin(), ascii2.end());

	Logging::LogRepeat(ascii1, 300);
	
	Logging::Log("- \t(1) New Game");
	Logging::Log("- \t(2) Load Game", Colors::BrightBlack);
	Logging::Log("- \t(3) Quit");

	while (true)
	{
		int input = 0;
		Input::Get<int>(input);

		if (ErrorHandler::HandleMenuCommand(input, 1, 3))
			continue;

		switch (input)
		{
		case 1: // New Game
			NewGame();
			break;
		case 2: // Load Game
			LoadGame();
			break;
		case 3: // Quit
			Quit();
		}	

		break;
	}
}

void Intro::NewGame()
{
	Utilities::clearLines(5);
	std::string name = "";
	//Utilities::clear();	
	while (true)
	{
		name = "";
		Logging::Log("   What's your name?");
		while (true)
		{
			// Reusing int confirm variable
			Input::Get(name);

			if (ErrorHandler::HandleString(name))
				continue;

			break;
		}
		Logging::Log("   You said: " + name);
		Logging::Log("   Are you sure this is your name?");

		int confirm = 0;
		Logging::Log("-  (1) Yes");
		Logging::Log("-  (2) No");
		Input::Get<int>(confirm);

		if (ErrorHandler::HandleMenuCommand(confirm, 1, 2))
			continue;

		if (confirm == 1) break;
		else continue;
	}
	 
	Utilities::clear();
	
	Game::settings.gold = 10;
	Game::settings.party.push_back({ name, { "Stick", Game::ItemType::NoType, 0, 3, Game::Roles::Human, true }, 10});
	//Game::settings.party.push_back({ "Arthur", { "Excalibur", Game::ItemType::Sword, 0, 2, Game::Roles::Knight, true }, 10 });
	//Game::settings.party.push_back({ "Merlin", { "Tome of Explosion", Game::ItemType::Spell, 0, 5, Game::Roles::Wizard, true }, 10 });
	Game::HealParty();

	Game::LogParty();

	Sleep(500);

	Logging::LogRepeat("   The labyrinth opens,", 100);
	Logging::LogRepeat("   You delve deeper within...", 150);

	Sleep(1250);

	Game::gameState = Game::GameStates::ENCOUNTER;
}

void Intro::LoadGame()
{
	Logging::LogWarning("Unimplemented");
}

void Intro::Quit()
{
	Logging::Log("Quitting", false);
	Logging::LogRepeat("...", 150);
	exit(0);
}