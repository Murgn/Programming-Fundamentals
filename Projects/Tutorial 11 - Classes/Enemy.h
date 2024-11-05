#pragma once
#include <iostream>
#include "Vector2.h"

class Enemy
{
public:
	std::string name;
	float damageAmount;

	Enemy(std::string name = "Enemy", float damageAmount = 0)
	{
		this->name = name;
		this->damageAmount = damageAmount;
	}

	void RunDialogue();
	void SetPosition(Vector2 position);
	Vector2 GetPosition();

private:
	bool inRadiusOfPlayer = false;
	bool isDead = false;
	Vector2 position = Vector2(0, 0);
};