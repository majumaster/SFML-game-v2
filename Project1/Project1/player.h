#pragma once

#include "entity.h"

class player : public entity
{
public:
	float movementSpeed = 3;
	float attackDamage = 5;
	int counterWalking = 0;
	int direction = 0;
	int hp=400;
	int hpMax = 400;

	bool canMoveUp = true;
	bool canMoveDown = true;
	bool canMoveLeft = true;
	bool canMoveRight = true;




	player();
	void update();
	void updateMovement();
};