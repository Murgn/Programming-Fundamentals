#pragma once
#include "State_Base.h"

class Encounter : public State_Base
{
public:
	void main() override;
private:
	const float strongMulti = 1.25f;
	const float weakMulti = 0.75f;

	std::string enemyNames[20] = {
		"Goblin",
		"Bandit",
		"Thug",
		"Hobgoblin",
		"Troll",
		"Barbarian",
		"Skeleton",
		"Zombie",
		"Ghoul",
		"Phantom",
		"Spider",
		"Slime",
		"Golem",
		"Spirit",
		"Dark Elf",
		"Gargoyle",
		"Minotaur",
		"Cyclops",
		"Gremlin",
		"Dragon"
	};

	std::string directions[25]
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

	std::string appearances[7] =
	{
		"blocks the path!",
		"appeared!",
		"stands in your way!",
		"emerges from the shadows!",
		"lunges towards you!",
		"comes into view!",
		"drops down from above!",
	};

	std::string gameOverMessages[7] =
	{
		"Don't lose hope!",
		"You cannot give up now!",
		"Stay determined!",
		"This is not the end!",
		"Try again!",
		"Rise up and fight once more!",
		"The journey isn't over yet!"
	};

	Game::Weapon enemyWeapons[30] =
	{
		// Swords
		{ "Dirty Knife", Game::ItemType::Sword, 0, 0, Game::Roles::Knight, true },
		{ "Longsword", Game::ItemType::Sword, 0, 0, Game::Roles::Knight, true },
		{ "Dagger", Game::ItemType::Sword, 0, 0, Game::Roles::Knight, true },
		{ "Iron Blade", Game::ItemType::Sword, 0, 0, Game::Roles::Knight, true },
		{ "Flame Sword", Game::ItemType::Sword, 0, 0, Game::Roles::Knight, true },
		{ "Frost Sword", Game::ItemType::Sword, 0, 0, Game::Roles::Knight, true },
		{ "Thunder Blade", Game::ItemType::Sword, 0, 0, Game::Roles::Knight, true },
		{ "Venom Blade", Game::ItemType::Sword, 0, 0, Game::Roles::Knight, true },
		{ "Blood Sword", Game::ItemType::Sword, 0, 0, Game::Roles::Knight, true },
		{ "Stone Sword", Game::ItemType::Sword, 0, 0, Game::Roles::Knight, true },

		// Bows
		{ "Broken Bow", Game::ItemType::Bow, 0, 0, Game::Roles::Archer, true },
		{ "Longbow", Game::ItemType::Bow, 0, 0, Game::Roles::Archer, true },
		{ "Wooden Bow", Game::ItemType::Bow, 0, 0, Game::Roles::Archer, true },
		{ "Darkwood Bow", Game::ItemType::Bow, 0, 0, Game::Roles::Archer, true },
		{ "Flame Bow", Game::ItemType::Bow, 0, 0, Game::Roles::Archer, true },
		{ "Frost Bow", Game::ItemType::Bow, 0, 0, Game::Roles::Archer, true },
		{ "Light Bow", Game::ItemType::Bow, 0, 0, Game::Roles::Archer, true },
		{ "Venom Bow", Game::ItemType::Bow, 0, 0, Game::Roles::Archer, true },
		{ "Bone Bow", Game::ItemType::Bow, 0, 0, Game::Roles::Archer, true },
		{ "Light Bow", Game::ItemType::Bow, 0, 0, Game::Roles::Archer, true },

		// Spells
		{ "Fireball", Game::ItemType::Spell, 0, 0, Game::Roles::Wizard, true },
		{ "Explosion", Game::ItemType::Spell, 0, 0, Game::Roles::Wizard, true },
		{ "Ice Shard", Game::ItemType::Spell, 0, 0, Game::Roles::Wizard, true },
		{ "Lightning Bolt", Game::ItemType::Spell, 0, 0, Game::Roles::Wizard, true },
		{ "Wind Gust", Game::ItemType::Spell, 0, 0, Game::Roles::Wizard, true },
		{ "Frostbite", Game::ItemType::Spell, 0, 0, Game::Roles::Wizard, true },
		{ "Thunderclap", Game::ItemType::Spell, 0, 0, Game::Roles::Wizard, true },
		{ "Conjure Gun", Game::ItemType::Spell, 0, 0, Game::Roles::Wizard, true },
		{ "Magic Missile", Game::ItemType::Spell, 0, 0, Game::Roles::Wizard, true },
		{ "Nuclear Warhead", Game::ItemType::Spell, 0, 0, Game::Roles::Wizard, true },
	};

	std::string deathMessages[13] =
	{
		" died!",
		" is defeated!",
		" falls!",
		" is slain!",
		" collapses!",
		" is no more!",
		" perishes!",
		" is vanquished!",
		" falls to the ground!",
		" is cut down!",
		" disintegrates into dust!",
		"'s life fades away!",
		" meets it's end!",
	};

	std::map <std::string, std::string> enemyToColor = {
		{ "Goblin", Colors::Green},
		{ "Bandit", Colors::BrightRed},
		{ "Thug", Colors::Red},
		{ "Hobgoblin", Colors::Green},
		{ "Troll", Colors::BrightGreen},
		{ "Barbarian", Colors::BrightRed},
		{ "Skeleton", Colors::BrightWhite},
		{ "Zombie", Colors::BrightGreen},
		{ "Ghoul", Colors::BrightGreen},
		{ "Phantom", Colors::BrightCyan},
		{ "Spider", Colors::BrightPurple},
		{ "Slime", Colors::BrightGreen},
		{ "Golem", Colors::BrightBlack},
		{ "Spirit", Colors::BrightPurple},
		{ "Dark Elf", Colors::Purple},
		{ "Gargoyle", Colors::BrightBlack},
		{ "Minotaur", Colors::Yellow},
		{ "Cyclops", Colors::BrightBlack},
		{ "Gremlin", Colors::Yellow},
		{ "Dragon", Colors::Red},
	};

	struct Enemy
	{
		Enemy(std::string name, Game::Weapon weapon, int maxHealth)
		{
			this->name = name;
			this->weapon = weapon;
			this->maxHealth = maxHealth;
			this->currentHealth = maxHealth;
		}

		std::string name;
		Game::Weapon weapon;
		int maxHealth = 10;
		int currentHealth = 0;
		bool blocking = false;
	};

	Enemy enemyCreator();
	void Tutorial();
	void SplitChoice();
	void LogEnemy(const std::vector<Enemy>& enemies);
	float TypeMultiplier(Game::ItemType attacker, Game::ItemType opponent);
	void AttackEnemy(Game::Player player, std::vector<Enemy>& enemies, int index);
	void AttackPlayer(Enemy& enemy, std::vector<Game::Player>& players);
	bool CheckEnemyState(std::vector<Enemy>& aliveEnemies);
	bool CheckPlayerState(std::vector<Game::Player>& alivePlayers);
	void LogBattleStats(std::vector<Game::Player>& alivePlayers, std::vector<Enemy>& aliveEnemies);
	void ResetEnemyBlocks(std::vector<Enemy>& aliveEnemies);
	// This is implemented here instead of Game.h because my aliveParties vector is a copy of Game::settings.party
	void ResetPartyBlocks(std::vector<Game::Player>& alivePlayers);
	void Die();

};
