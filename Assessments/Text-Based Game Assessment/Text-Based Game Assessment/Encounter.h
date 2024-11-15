#pragma once
#include "State_Base.h"

class Encounter : public State_Base
{
public:
	void main() override;
private:

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
		Enemy(std::string name, Game::Roles role, int maxHealth)
		{
			this->name = name;
			this->role = role;
			this->itemType = Game::roleToItemType[this->role];
			this->maxHealth = maxHealth;
		}

		std::string name;
		Game::Roles role = Game::Roles::Human;
		Game::ItemType itemType = Game::ItemType::NoType;
		int maxHealth = 10;
	};

	Enemy enemyCreator();
};
