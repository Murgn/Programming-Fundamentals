#include "Encounter.h"

void Encounter::main()
{
	Utilities::clear();

	for (int i = 0; i < 25; i++)
	{
		Enemy enemy = enemyCreator();

		Logging::Log("A " + Encounter::enemyToColor[enemy.name] + enemy.name + Colors::None + " " + Game::roleToStr[enemy.role] + " appeared!");
		Sleep(250);
	}
}

Encounter::Enemy Encounter::enemyCreator()
{
	std::string name = enemyNames[Utilities::range(0, sizeof(enemyNames) / sizeof(enemyNames[0]))];

	int role = Utilities::range(1, 4);
	Enemy enemy = Enemy(name, (Game::Roles)role, 10);

	return enemy;
	
}
