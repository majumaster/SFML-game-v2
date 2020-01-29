#pragma once
#include "entity.h"
#include "player.h"

class enemy : public entity
{
public:
	float movementSpeed = 1.5;
	float attackDamage = 1;
	bool attacked = false;
	int counterWalking = 0;
	int movementLength = 100;
	int hpMax = 50;
	int hp = 50;
	int direction=0;
	int counter = 0;
	enemy();
	void update();
	void updateMovement(player &player);

	bool alive = true;
	bool destroy=false;

	bool canMoveUp = true;
	bool canMoveDown = true;
	bool canMoveLeft = true;
	bool canMoveRight = true;
};