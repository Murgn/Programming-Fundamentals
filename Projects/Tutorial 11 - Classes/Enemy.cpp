#include <iostream>
#include "Enemy.h"

void Enemy::RunDialogue()
{
	std::cout << "Hello there! My name is " << name << "! Grrrr" << std::endl;
}

void Enemy::SetPosition(Vector2 position)
{
	this->position = position;
}

Vector2 Enemy::GetPosition()
{
	return position;
}
