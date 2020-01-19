#pragma once
#include "entity.h"

class enemy : public entity
{
public:
	float movementSpeed = 1.5;
	float attackDamage = 5;
	int counterWalking = 0;
	int movementLength = 100;
	int hpMax = 50;
	int hp = 50;
	int direction=0;
	int counter = 0;
	enemy();
	void update();
	void updateMovement();

	bool alive = true;
	bool destroy=false;

	bool canMoveUp = true;
	bool canMoveDown = true;
	bool canMoveLeft = true;
	bool canMoveRight = true;
};