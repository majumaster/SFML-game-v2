#include "player.h"

player::player()
{
	rect.setSize(sf::Vector2f(64, 64));
	rect.setPosition(400,300);
	rect.setFillColor(sf::Color::Blue);
	sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	text.setPosition(rect.getPosition());
	text.setString("hp " + to_string(hp) + "/" + to_string(hpMax));
	textName.setPosition(rect.getPosition());
	textName.setString("Player");
	
}
void player::update() 
{
	sprite.setPosition(rect.getPosition());
	text.setPosition(rect.getPosition().x + 6 / 2, rect.getPosition().y - rect.getSize().y /5);
	textName.setPosition(rect.getPosition().x +10- textName.getScale().x/2, rect.getPosition().y - rect.getSize().y/2);
}

void player::updateMovement() 
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) 
	{
		if (canMoveUp == true) 
		{
			rect.move(0, -movementSpeed);
			sprite.setTextureRect(sf::IntRect(counterWalking * 64, 64 * 3, 64, 64));
			direction = 0;//up

			
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) 
	{
		if (canMoveDown == true)
		{
			rect.move(0, movementSpeed);
			sprite.setTextureRect(sf::IntRect(counterWalking * 64, 64 * 0, 64, 64));
			direction = 1;
		}
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
	{
		if (canMoveLeft == true)
		{
			rect.move(-movementSpeed, 0);
			sprite.setTextureRect(sf::IntRect(counterWalking * 64, 64 * 1, 64, 64));
			direction = 2;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
	{
		if (canMoveRight == true)
		{
			rect.move(movementSpeed, 0);
			sprite.setTextureRect(sf::IntRect(counterWalking * 64, 64 * 2, 64, 64));
			direction = 3;
		}
	}
	else 
	{
	
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
}