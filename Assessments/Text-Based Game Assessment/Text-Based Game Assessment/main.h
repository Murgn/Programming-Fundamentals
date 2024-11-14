#include <iostream>
#include "logging.h"
#include "States.h"

using namespace std;

enum GameStates
{
	UNDEFINED = 0,
	INTRO = 1,
	ENCOUNTER = 2,
	CAMPFIRE = 3
};

GameStates gameState = GameStates::UNDEFINED;

Intro intro;
Encounter encounter;
Campfire campfire;
