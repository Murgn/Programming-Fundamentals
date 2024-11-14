#include <iostream>
#include "logging.h"
#include "States.h"

enum GameStates
{
	UNDEFINED = 0,
	INTRO = 1,
	ENCOUNTER = 2,
	CAMPFIRE = 3
};

// Values I want to pass through gameStates
struct GameSettings
{
	std::vector<Player> party;
	int encounter;
};
	
struct Player
{
	std::string name;
	int maxHealth;
};

GameStates gameState = GameStates::UNDEFINED;
GameSettings settings;

Intro intro(settings);
Encounter encounter;
Campfire campfire;
