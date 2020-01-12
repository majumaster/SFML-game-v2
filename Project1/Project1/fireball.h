#pragma once


#include "entity.h"

class fireball :public entity
{
	public:
		float movementSpeed = 8;
		float attackDamage = 1;
		int direction = 0;

		fireball();
		void update();
		void updateMovement();
};