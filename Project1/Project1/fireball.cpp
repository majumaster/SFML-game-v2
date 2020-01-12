#include "fireball.h"

fireball::fireball()
{
	rect.setSize(sf::Vector2f(20, 20));
	rect.setPosition(0, 0);
	rect.setFillColor(sf::Color::Blue);
	//sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));

}

void fireball::update()
{
	sprite.setPosition(rect.getPosition());
}


void fireball::updateMovement()
{
	if (direction == 0)
	{
		rect.move(0, -movementSpeed);
	}
	if (direction == 1)
	{
		rect.move(0, movementSpeed);
	}
	if (direction == 2)
	{
		rect.move(-movementSpeed, 0);
	}
	if (direction == 3)
	{
		rect.move(movementSpeed, 0);
	}
}