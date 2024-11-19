	#pragma once
	#include <iostream>
	#include <vector>
	#include <map>
	#include "utilities.h"

	class Game
	{
	public:
		enum GameStates
		{
			UNDEFINED = 0,
			INTRO = 1,
			ENCOUNTER = 2,
			CAMPFIRE = 3
		};

		enum Roles
		{
			Human,
			Knight,
			Archer,
			Wizard
		};

		enum ItemType
		{
			NoType,
			Sword,
			Bow,
			Spell
		};

		struct Weapon
		{
			std::string name = "";
			ItemType itemType = ItemType::NoType;
			int price = 0;
			int damage = 0;
			Roles role = Roles::Human;
			bool bought = false;
		};

		struct Player
		{
			std::string name;
			Weapon weapon;
			int maxHealth = 10;
			int health = 0;
			bool blocking = false;
		};

		struct GameSettings
		{
			static int gold;
			static std::vector<Player> party;
			static int encounter;
		};

		static GameStates gameState;
		static GameSettings settings;

		static std::map<Roles, std::string> roleToStr;
		static std::map<ItemType, std::string> itemTypeToStr;
		static std::map<Roles, ItemType> roleToItemType;

		static void LogParty(bool printAscii = true);
		static void HealParty();
		static void LogGold();
	};