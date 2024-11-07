#pragma once

#include <iostream>
#include <map>
#include <Windows.h>
#include "utilities.h"

using namespace std;

struct GameStats
{
	int wins = 0;
	int cpuWins = 0;
	int totalGames = 0;
};

map<int, string> numToRPS =
{
	{ 0, "Rock" },
	{ 1, "Paper" },
	{ 2, "Scissors" }
};

map<string, int> rpsToNum =
{
	{ "rock", 0 },
	{ "paper", 1},
	{ "scissors", 2}
};

enum Results
{
	Win,
	Lost,
	Tie
};

GameStats gameStats;

void Choose(int& input);
void Decide(int& input, int& cpuInput);
void Result(const Results result);
void ClearInput();
bool ErrorHandling();
bool HandHandling(string& input);