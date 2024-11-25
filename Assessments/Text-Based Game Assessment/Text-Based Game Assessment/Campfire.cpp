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
	if (Game::settings.encounter % 5 == 0) // Add a party member
	{
		Logging::EndLine();
		JoinParty();
	}
	Sleep(500);

	bool shopAvailable = Utilities::range(0, 5) != 0;
	const int itemCount = 6;
	std::vector<Game::Weapon> weapons;

	if(shopAvailable)
	{
		Logging::EndLine();
		Logging::Log("Amidst the fog... A travelling merchant appears...", Colors::BrightBlack);

		for (int i = 0; i < itemCount; i++)
		{
			weapons.push_back(RandomiseWeapon());
		}
	}

	while (true)
	{
		Logging::EndLine();
		Logging::Log("   What do you want to do?");
		Sleep(500);

		int confirm = 0;

		Logging::Log("-  (1) Rest");
		if(shopAvailable) Logging::Log("-  (2) Visit the Merchant");
		while (true)
		{
			Input::Get<int>(confirm);

			if (ErrorHandler::HandleMenuCommand(confirm, 1, shopAvailable ? 2 : 1))
				continue;

			//Logging::EndLine();
			Sleep(250);

			if (confirm == 1)
			{
				Logging::EndLine();
				Logging::Log("Your party rests at the campfire and wakes up renewed");
				Sleep(1000);
				Game::SplitChoice();
				Game::gameState = Game::GameStates::ENCOUNTER;
				return;
			}
			else if (confirm == 2)
			{
				// Shop Code
				Logging::EndLine();
				Logging::Log("   The travelling merchant welcomes you...", Colors::BrightBlack);
				Sleep(1000);
				Game::LogGold(false);
				Logging::Log(" You can buy the following items:");
				Sleep(1500);

				int i = 0;
				for (Game::Weapon weapon : weapons)
				{
					i++;
					Logging::Log("- (" + std::to_string(i) + ") " + weapon.name + " (" + Game::itemTypeToStr[weapon.itemType] + ") [" + std::string(Colors::BrightYellow) + std::to_string(weapon.price) + Colors::None + " gold, " + std::to_string(weapon.damage) + " damage]");
					Sleep(500);
				}

				Logging::Log("- (" + std::to_string(itemCount + 1) + ") Return to camp");

				while (true)
				{
					Logging::EndLine();
					Logging::Log("   What would you like to purchase?");
					Input::Get<int>(confirm);
					if (ErrorHandler::HandleMenuCommand(confirm, 1, itemCount + 1))
						continue;

					if (confirm == itemCount + 1) // Return to camp
					{
						Logging::EndLine();
						Logging::Log("   Your party makes their way back to the camp.");
						Sleep(1000);
						break;
					}
					else
					{
						if (HandleShopCommand(weapons[confirm - 1]))
							continue;
						
						if (Game::settings.party.size() == 1) // Don't need to specify who to give to
						{
							Logging::Log("   " + Game::settings.party[0].name + " bought: " + weapons[confirm - 1].name + "!");
							Game::settings.party[0].weapon = weapons[confirm - 1];
							Game::settings.gold -= weapons[confirm - 1].price;
							weapons[confirm - 1].bought = true;

							Game::LogGold();
							Sleep(500);
						}
						else
						{
							Logging::EndLine();
							Logging::Log("   Who do you want to give the " + weapons[confirm - 1].name + " to?");
							int j = 0;
							for (Game::Player player : Game::settings.party)
							{
								j++;
								Logging::Log("- (" + std::to_string(j) + ") " + player.name + " the " + Game::roleToStr[player.weapon.role]);
							}

							int input = 0;
							while (true)
							{
								Input::Get<int>(input);

								if (ErrorHandler::HandleMenuCommand(input, 1, j))
									continue;

								Logging::EndLine();
								Logging::Log("   " + Game::settings.party[input - 1].name + " bought the " + weapons[confirm - 1].name + "!");

								Game::settings.party[input - 1].weapon = weapons[confirm - 1];
								Game::settings.gold -= weapons[confirm - 1].price;
								weapons[confirm - 1].bought = true;

								Game::LogGold();
								Sleep(500);

								break;
							}
						}
					}
					if (confirm == itemCount + 1) // Return to camp
						break;
				}				
			}
			break;
		}
		//break;
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
		RandomiseWeapon(),
		health,
		health,
		false
	};

	Logging::EndLine();
	Logging::Log("   " + newPlayer.name + partyJoinMessages[Utilities::range(0, sizeof(partyJoinMessages) / sizeof(partyJoinMessages[0]))]);

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

Game::Weapon Campfire::RandomiseWeapon()
{
	Game::Weapon weapon;

	int weaponType = Utilities::range(0, 3);

	if (weaponType == 0) // Sword
		weapon = Game::shopWeapons[Utilities::range(0, Utilities::clamp(Game::settings.encounter - 1, 0, 10))];
	else if (weaponType == 1) // Bow
		weapon = Game::shopWeapons[Utilities::range(10, Utilities::clamp(Game::settings.encounter + 9, 10, 20))];
	else if (weaponType == 2) // Spell
		weapon = Game::shopWeapons[Utilities::range(20, Utilities::clamp(Game::settings.encounter + 19, 20, 30))];

	weapon.damage += Utilities::range(-2, 3);
	weapon.price += Utilities::range((weapon.price * -1) / 5, weapon.price / 20);

	return weapon;
}

// I have to put this here because I'm getting really annoying errors
const bool Campfire::HandleShopCommand(const Game::Weapon weapon)
{
	if (ErrorHandler::HandleError()) return true;
	else if (weapon.bought)
	{
		ErrorHandler::ClearInput();
		Logging::LogError("This weapon has already been bought, try again.");

		return true;
	}
	else if (Game::settings.gold < weapon.price)
	{
		ErrorHandler::ClearInput();
		Logging::LogError("You don't have enough gold, try again.");

		return true;
	}
	return false;
}
 