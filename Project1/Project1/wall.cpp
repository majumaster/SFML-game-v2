#include "wall.h"

wall::wall()
{
	rect.setSize(sf::Vector2f(50, 200));
	rect.setPosition(0, 0);
	rect.setFillColor(sf::Color::White);
}