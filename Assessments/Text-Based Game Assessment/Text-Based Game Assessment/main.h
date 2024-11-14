#include <iostream>
#include "logging.h"
#include "States.h"

using namespace std;

enum GameStates
{
	ERROR = 0,
	INTRO = 1,
	ENCOUNTER = 2,
	CAMPFIRE = 3
};

GameStates gameState = GameStates::ERROR;

Intro intro;
Encounter encounter;
Campfire campfire;
