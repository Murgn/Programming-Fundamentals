#include "Campfire.h"

void Campfire::main()
{
	Utilities::clear();
	Logging::Log("   " + campfireMessages[Utilities::range(0, sizeof(campfireMessages) / sizeof(campfireMessages[0]))], Colors::BrightYellow);

	bool endLine = false;
	for (Game::Player& player : Game::settings.party)
	{
		int increase = Utilities::range(0, 2);
		if (increase)
		{
			if (!endLine)
			{
				// Adds the endline once
				Sleep(1000);
				Logging::EndLine();
				endLine = true;
			}

			player.maxHealth += increase;
			Logging::Log("   " + player.name + " the " + Game::roleToStr[player.weapon.role] + "'s max health was increased by " + std::to_string(increase) + "!");
			Sleep(500);

		}
		/*else 
		{
			Logging::Log("   " + player.name + " the " + Game::roleToStr[player.weapon.role] + " max health wasn't increased!", Colors::BrightBlack);
		}*/
	}
	Sleep(500);
	Logging::EndLine();
	Game::HealParty();
	Logging::Log("   Your party was healed!");

	Sleep(1000);
	Logging::EndLine();
	if (Game::settings.encounter % 5 == 0) // Add a party member
	{
		JoinParty();
	}
	Sleep(500);

	Logging::EndLine();
	Logging::Log("Amidst the fog... A travelling merchant appears...", Colors::BrightBlack);

	while (true)
	{
		Logging::EndLine();
		Logging::Log("   What do you want to do?");
		Sleep(500);

		int confirm = 0;

		Logging::Log("-  (1) Rest");
		Logging::Log("-  (2) Visit the Merchant");
		while (true)
		{
			Input::Get<int>(confirm);

			if (ErrorHandler::HandleMenuCommand(confirm, 1, 2))
				continue;

			//Logging::EndLine();
			Sleep(250);

			if (confirm == 1)
			{
				Logging::Log("You party rests at the campfire and wakes up renewed");
				Game::SplitChoice();
				return;
			}
			else if (confirm == 2)
			{

			}
		}
		break;
	}
}

void Campfire::JoinParty()
{
	Logging::Log("   *crunch*", Colors::BrightBlack);
	Sleep(500);
	Logging::Log("   *rustle*", Colors::BrightBlack);
	Sleep(500);
	Logging::Log("   *snap*", Colors::BrightBlack);

	Sleep(1000);

	int health = Game::settings.party[0].maxHealth + Utilities::range(-2, 2);
	Game::Player newPlayer = {
		"Someone",
		Game::shopWeapons[Utilities::range(0, Utilities::clamp(Game::settings.encounter, 0, (int)(sizeof(Game::shopWeapons) / sizeof(Game::shopWeapons[0]))))],
		health,
		health,
		false
	};

	Logging::Log(newPlayer.name + partyJoinMessages[Utilities::range(0, sizeof(partyJoinMessages) / sizeof(partyJoinMessages[0]))]);

	Logging::EndLine();
	Logging::Log("   What's their name?");
	std::string name = "";
	while (true)
	{
		Input::Get(name);

		if (ErrorHandler::HandleString(name))
			continue;

		break;
	} 
	newPlayer.name = name;
	Game::settings.party.push_back(newPlayer);

	Sleep(1000);
	Game::LogParty();
	Sleep(1000);
}
 