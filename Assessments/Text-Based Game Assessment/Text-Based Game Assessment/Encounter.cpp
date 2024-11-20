#include "Encounter.h"

void Encounter::main()
{
	Utilities::clear();

	if (Game::settings.encounter == 1) Tutorial();

	Utilities::clear();

	Logging::LogRepeat("...", 500);
	Logging::EndLine();

	int enemyAmount = ceil(Game::settings.encounter / 5.0f);
	std::vector<Enemy> aliveEnemies;
	for (int i = 0; i < enemyAmount; i++)
	{
		Sleep(50);
		aliveEnemies.push_back(enemyCreator());
	}

	LogEnemy(aliveEnemies);

	Logging::Log("   Your party: ");
	Sleep(500);
	Game::LogParty(false);
	Logging::Log("___________________________________", Colors::BrightBlack);
	Logging::EndLine();

	Sleep(500);

	std::vector<Game::Player> alivePlayers;
	for (Game::Player player : Game::settings.party)
	{
		alivePlayers.push_back(player);
	}

	while(true)
	{
		for (Game::Player& player : alivePlayers)
		{
			// Check if enemies are dead
			if (CheckEnemyState(aliveEnemies)) break;

			Logging::Log("   " + player.name + " it's your turn to fight!", Colors::BrightWhite);

			int confirm = 0;

			Logging::Log("-  (1) Attack");
			Logging::Log("-  (2) Block");
			while (true)
			{
				Input::Get<int>(confirm);

				if (ErrorHandler::HandleMenuCommand(confirm, 1, 2))
					continue;

				//Logging::EndLine();
				Sleep(250);

				if (confirm == 1) // Attack
				{
					if (aliveEnemies.size() == 1) // If only one enemy we don't need to choose who to attack
					{
						AttackEnemy(player, aliveEnemies, 0);
					}
					else
					{
						Logging::Log("   Who do you want to attack?: ");
						for (int i = 1; i <= aliveEnemies.size(); i++)
						{
							Logging::Log("-  (" + std::to_string(i) + ") " + Encounter::enemyToColor[aliveEnemies[i - 1].name] + aliveEnemies[i - 1].name + Colors::None + " " + Game::roleToStr[aliveEnemies[i - 1].weapon.role]);
						}

						while (true)
						{
							// Reusing int confirm variable
							Input::Get<int>(confirm);

							if (ErrorHandler::HandleMenuCommand(confirm, 1, aliveEnemies.size()))
								continue;

							break;
						}

						AttackEnemy(player, aliveEnemies, confirm - 1);
						// Check if enemies are dead
						if (CheckEnemyState(aliveEnemies)) break;
					}
				}
				else if (confirm == 2) // Block
				{
					Logging::Log("   " + player.name + " used Block!");
					player.blocking = true;
					Sleep(500);
					Logging::Log("   The enemy's next attack on " + player.name + " the " + Game::roleToStr[player.weapon.role] + " is reduced!");
					Logging::EndLine();
					Sleep(1000);
				}

				break;
			}
		}
		Sleep(1000);
		if (CheckEnemyState(aliveEnemies)) break;

		bool multiple = enemyAmount != 1;
		Logging::Log("   The " + std::string(multiple ? "enemies are" : "enemy is") + " about to attack!", Colors::BrightWhite);
		Logging::EndLine();

		ResetEnemyBlocks(aliveEnemies);
		for (Enemy& enemy : aliveEnemies)
		{
			Sleep(1000);
			AttackPlayer(enemy, alivePlayers);
			if (CheckPlayerState(alivePlayers)) break;
		}

		if (CheckPlayerState(alivePlayers)) break;

		Sleep(2000);

		ResetPartyBlocks(alivePlayers);
		LogBattleStats(alivePlayers, aliveEnemies);
	}

	Sleep(1000);

	if (CheckPlayerState(alivePlayers))
	{
		Die();
	}
	else if (CheckEnemyState(aliveEnemies))
	{
		Win(enemyAmount);
	}
	else
	{
		Logging::LogWarning("You shouldn't be here, restart your game.");

		Sleep(5000);
		Logging::LogRepeat("Quitting...", 500);
		exit(0);
	}
}

Encounter::Enemy Encounter::enemyCreator()
{
	std::string name = enemyNames[Utilities::range(0, sizeof(enemyNames) / sizeof(enemyNames[0]))];

	Game::Weapon weapon = enemyWeapons[Utilities::range(0, sizeof(enemyWeapons) / sizeof(enemyWeapons[0]))];

	// Need to adjust this to scale with encounters, for now left it as 3 + encounter / 3 + random range between -2 to 2
	weapon.damage = 3 + (Game::settings.encounter / 2.0f) + Utilities::range(-1, 2);

	Enemy enemy = Enemy(name, weapon, 10);

	return enemy;
	
}

void Encounter::Tutorial()
{
	std::vector<std::string> tutorial = AsciiGenerator::Generate("TUTORIAL", { Colors::BrightBlack, false });
	tutorial.pop_back();
	Logging::LogRepeat(tutorial, 300);
	Logging::Log("__________________________________________________________", Colors::BrightBlack);
	Logging::EndLine();

	std::vector<std::string> text = {
		"   Opponents in the labyrinth take turns battling eachother.",
		"   Each turn you can either Attack to deal damage or Block to reduce the damage taken.",
		"",
		"   Depending on your weapon type you can have an attack advantage or disadvantage!",
		"   Swords beat spells, spells beat bows and bows beats swords!",
		"",
		"   Knights -> Wizards -> Archers -> Knights",
		"   Will you be able find Wisteria's treasures?",
		"   \033[1;33mGood Luck!\033[0m"
	};
	Logging::LogRepeat(text, 2500);

	Logging::EndLine();
	SplitChoice();
}

void Encounter::SplitChoice()
{
	int confirm = 0;
	int choices = Utilities::range(2, 4);
	std::vector<std::string> list(std::begin(directions), std::end(directions));

	for (int i = 1; i <= choices; i++)
	{
		int direction = Utilities::range(0, list.size());
		Logging::Log("-  (" + std::to_string(i) +") " + directions[direction]);
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

void Encounter::LogEnemy(const std::vector<Enemy>& enemies)
{
	for (Enemy enemy : enemies)
	{
		Sleep(500);
		Logging::Log("   A " + Encounter::enemyToColor[enemy.name] + enemy.name + Colors::None + " " + Game::roleToStr[enemy.weapon.role] + " " + Encounter::appearances[Utilities::range(0, sizeof(appearances) / sizeof(appearances[0]))]);
		Sleep(500);
		Logging::Log("\t->   Health: " + std::to_string(enemy.currentHealth));
		Logging::Log("\t->   Weapon: " + enemy.weapon.name);
		Logging::Log("\t->   Damage: " + std::to_string(enemy.weapon.damage));
		Logging::Log("\t->   Type: " + Game::itemTypeToStr[enemy.weapon.itemType]);
		Logging::EndLine();
		Sleep(1500);
	}
}

float Encounter::TypeMultiplier(const Game::ItemType attacker, const Game::ItemType opponent)
{
	if (attacker == Game::ItemType::Sword)
	{
		if (opponent == Game::ItemType::Sword) return 1.0f;

		else if (opponent == Game::ItemType::Bow) return weakMulti;

		else if (opponent == Game::ItemType::Spell) return strongMulti;
	}

	else if (attacker == Game::ItemType::Bow)
	{
		if (opponent == Game::ItemType::Sword) return strongMulti;

		else if (opponent == Game::ItemType::Bow) return 1.0f;

		else if (opponent == Game::ItemType::Spell) return weakMulti;
	}

	else if (attacker == Game::ItemType::Spell)
	{
		if (opponent == Game::ItemType::Sword) return weakMulti;

		else if (opponent == Game::ItemType::Bow) return strongMulti;

		else if (opponent == Game::ItemType::Spell) return 1.0f;
	}

	return 1;
}

void Encounter::AttackEnemy(Game::Player player, std::vector<Enemy>& enemies, int index)
{
	Enemy& enemy = enemies[index];

	bool blocked = enemy.blocking;
	float blockMulti = blocked ? 0.7f : 1.0f;
	enemy.blocking = false;

	float multi = TypeMultiplier(player.weapon.itemType, enemy.weapon.itemType);
	int dmg = player.weapon.damage * multi * blockMulti;

	enemy.currentHealth = Utilities::clamp<int>(enemy.currentHealth - dmg, 0, 1000);
	Logging::EndLine();
	Logging::Log("   " + player.name + " the " + Game::roleToStr[player.weapon.role] + " used " + player.weapon.name + " on the " + Encounter::enemyToColor[enemy.name] + enemy.name + Colors::None + " " + Game::roleToStr[enemy.weapon.role] + "!");
	Sleep(1000);
	if (multi == strongMulti)
	{
		Logging::Log("   CRITICAL HIT!", Colors::BrightRed);
		Sleep(1000);
	}
	else if (multi == weakMulti) 
	{
		Logging::Log("   critical fumble...", Colors::BrightBlack);
		Sleep(1000);
	}
	if(blocked) 
	{
		Logging::Log("   The enemy's block reduced it's damage!", Colors::BrightBlack);
		Sleep(1000);
	}
	Logging::Log("   " + Encounter::enemyToColor[enemy.name] + enemy.name + Colors::None + " " + Game::roleToStr[enemy.weapon.role] + " took " + std::to_string(dmg) + " damage!");
	if (enemy.currentHealth <= 0)
	{
		Sleep(1000);
		Logging::Log("   " + Encounter::enemyToColor[enemy.name] + enemy.name + Colors::None + " " + Colors::Red + Game::roleToStr[enemy.weapon.role] + deathMessages[Utilities::range(0, sizeof(deathMessages) / sizeof(deathMessages[0]))] + Colors::None);
		enemies.erase(enemies.begin() + index);
	}
	Sleep(1000);
	Logging::EndLine();
}

void Encounter::AttackPlayer(Enemy& enemy, std::vector<Game::Player>& players)
{
	// 1/4 chance to block, 3/4 chance to attack
	int decide = Utilities::range(0, 4);

	if (decide != 0)
	{
		// add blocking
		int selectedPlayer = Utilities::range(0, players.size());
		Game::Player& player = players[selectedPlayer];

		bool blocked = player.blocking;
		float blockMulti = blocked ? 0.7f : 1.0f;
		player.blocking = false;

		float multi = TypeMultiplier(enemy.weapon.itemType, player.weapon.itemType);
		int dmg = enemy.weapon.damage * multi * blockMulti;

		player.health = Utilities::clamp<int>(player.health - dmg, 0, 1000);
		Logging::Log("   " + Encounter::enemyToColor[enemy.name] + enemy.name + Colors::None + " " + Game::roleToStr[enemy.weapon.role] + " used " + enemy.weapon.name + " on " + player.name + "!");
		Sleep(1000);
		if (multi == strongMulti) 
		{
			Logging::Log("   CRITICAL HIT!", Colors::BrightRed);
			Sleep(1000);
		}
		else if (multi == weakMulti) 
		{
			Logging::Log("   critical fumble...", Colors::BrightBlack);
			Sleep(1000);
		}
		if (blocked)
		{
			Logging::Log("   The player's block reduced it's damage!", Colors::BrightBlack);
			Sleep(1000);
		}
		
		Logging::Log("   " + player.name + " the " + Game::roleToStr[player.weapon.role] + " took " + std::to_string(dmg) + " damage!");
		if (player.health <= 0)
		{
			Sleep(1000);
			Logging::Log("   " + player.name + " the " + Game::roleToStr[player.weapon.role] + deathMessages[Utilities::range(0, sizeof(deathMessages) / sizeof(deathMessages[0]))], Colors::Red);
			players.erase(players.begin() + selectedPlayer);
		}
		Logging::EndLine();
		Sleep(1000);
	}
	else
	{
		Logging::Log("   " + Encounter::enemyToColor[enemy.name] + enemy.name + Colors::None + " " + Game::roleToStr[enemy.weapon.role] + " used Block!");
		enemy.blocking = true;
		Sleep(500);
		Logging::Log("   Your party's next attack on " + Encounter::enemyToColor[enemy.name] + enemy.name + Colors::None + " " + Game::roleToStr[enemy.weapon.role] + " is reduced!");
		Logging::EndLine();
		Sleep(1000);
	}
}

bool Encounter::CheckEnemyState(std::vector<Enemy>& enemies)
{
	bool allDead = true;
	for (Enemy enemy : enemies)
	{
		if (enemy.currentHealth > 0) allDead = false;
	}
	return allDead;
}

bool Encounter::CheckPlayerState(std::vector<Game::Player>& alivePlayers)
{
	bool allDead = true;
	for (Game::Player player : alivePlayers)
	{
		if (player.health > 0) allDead = false;
	}
	return allDead;
}

void Encounter::LogBattleStats(std::vector<Game::Player>& alivePlayers, std::vector<Enemy>& aliveEnemies)
{
	Logging::Log("___________________________________", Colors::BrightBlack);
	Logging::EndLine();


	for (Game::Player player : alivePlayers)
	{
		Logging::Log("\t" + player.name + " the " + Game::roleToStr[player.weapon.role]);
		Logging::Log("\t->   Health: " + std::to_string(player.health));
		Logging::EndLine();
		Sleep(1000);
	}

	for (Enemy enemy : aliveEnemies)
	{
		Logging::Log("\t" + Encounter::enemyToColor[enemy.name] + enemy.name + Colors::None + " " + Game::roleToStr[enemy.weapon.role]);
		Logging::Log("\t->   Health: " + std::to_string(enemy.currentHealth));
		Logging::EndLine();
		Sleep(1000);
	}
	
	Logging::Log("___________________________________", Colors::BrightBlack);
	Logging::EndLine();
}

void Encounter::ResetEnemyBlocks(std::vector<Enemy>& aliveEnemies)
{
	Sleep(500);
	bool atleastOneBlock = false;
	for (Enemy& enemy : aliveEnemies)
	{
		if (enemy.blocking)
		{
			atleastOneBlock = true;

			Logging::Log("   " + Encounter::enemyToColor[enemy.name] + enemy.name + Colors::BrightBlack + " " + Game::roleToStr[enemy.weapon.role] + "'s block wore off!", Colors::BrightBlack);
			enemy.blocking = false;
			Sleep(500);
		}
	}
	if(atleastOneBlock)	Logging::EndLine();
}

void Encounter::ResetPartyBlocks(std::vector<Game::Player>& alivePlayers)
{
	Sleep(500);
	for (Game::Player& player : alivePlayers)
	{
		if (player.blocking)
		{
			Logging::Log("   " + player.name + " the " + Game::roleToStr[player.weapon.role] + "'s block wore off!", Colors::BrightBlack);
			player.blocking = false;
			Sleep(500);
		}
	}
}

void Encounter::Die()
{
	Logging::LogRepeat(std::string(Colors::Red) + "   Everyone in your party has perished...", 100);
	Logging::EndLine();
	Logging::EndLine();
	Sleep(500);
	std::vector<std::string> deathMessage = AsciiGenerator::Generate("GAME OVER", { Colors::BrightWhite, false });
	Logging::LogRepeat(deathMessage, 300);
	Sleep(500);
	Logging::LogRepeat("   " + gameOverMessages[Utilities::range(0, sizeof(gameOverMessages) / sizeof(gameOverMessages[0]))], 100, Colors::White);
	Logging::EndLine();
	Logging::EndLine();
	Sleep(5000);
	Logging::LogRepeat("Quitting...", 500);
	exit(0);
}

void Encounter::Win(int enemyAmount)
{
	Logging::Log("   The enemies have all been slain!", Colors::BrightYellow);
	Logging::EndLine();
	Logging::EndLine();
	Sleep(500);
	std::vector<std::string> victory = AsciiGenerator::Generate("VICTORY", { Colors::BrightWhite, false });
	Logging::LogRepeat(victory, 300);
	Sleep(500);

	int gold = (enemyAmount * 5) + Utilities::range(-2, 4);
	Logging::Log("   From the ashes of your enemies, you gain " + std::string(Colors::BrightYellow) + std::to_string(gold) + Colors::None + " gold!");
	Game::settings.gold += gold;
	Sleep(1000);
	Game::LogGold();
	Sleep(1000);

	Logging::EndLine();
	SplitChoice();

	Logging::LogRepeat("Deep in the labyrinth, you come across a campfire.", 50);
	Game::settings.encounter++;
	Sleep(1000);

	Game::gameState = Game::GameStates::CAMPFIRE;
}
