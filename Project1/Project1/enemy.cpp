#include "enemy.h"
#include "random.h"
enemy::enemy()
{
	rect.setSize(sf::Vector2f(50, 50));
	rect.setPosition(500, 400);
	rect.setFillColor(sf::Color::Blue);
	text.setPosition(rect.getPosition());
	text.setString("hp " + to_string(hp) + "/" + to_string(hpMax));
	textName.setPosition(rect.getPosition());
	textName.setString("maly ninja");

}


void enemy::update()
{
	
	sprite.setPosition(rect.getPosition());
	text.setPosition(rect.getPosition().x + 6 / 2, rect.getPosition().y - rect.getSize().y / 2);
	textName.setPosition(rect.getPosition().x - textName.getScale().x, rect.getPosition().y - rect.getSize().y);
}
void enemy::updateMovement() 
{
	if (direction==0) 
	{
		if (canMoveUp == true)
		{
			rect.move(0, -movementSpeed);
			sprite.setTextureRect(sf::IntRect(counterWalking * 50, 50 * 1, 50, 50));
		}
	}
	else if (direction == 1) 
	{
		if (canMoveDown == true)
		{
			rect.move(0, movementSpeed);
			sprite.setTextureRect(sf::IntRect(counterWalking * 50, 50 * 0, 50, 50));
		}
	}

	else if (direction == 2) 
	{
		if (canMoveLeft == true)
		{
			rect.move(-movementSpeed, 0);
			sprite.setTextureRect(sf::IntRect(counterWalking * 50, 50 * 2, 50, 50));
		}

	}
	else if (direction == 3) 
	{
		if (canMoveRight == true)
		{
			rect.move(movementSpeed, 0);
			sprite.setTextureRect(sf::IntRect(counterWalking * 50, 50 * 3, 50, 50));
		}
	}
	else {
		//ma nic nie robic
	}

	canMoveUp = true;
	canMoveDown = true;
	canMoveLeft = true;
	canMoveRight = true;

	if (counterWalking == 3)
	{
		counterWalking = 0;
	}
	counterWalking++;

	if (counter >= movementLength)
	{
		counter = 0;
		direction = generateRandom(10);
		//direction = 2;
	}
	counter++;


}