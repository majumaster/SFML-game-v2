#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <SFML\Audio\SoundBuffer.hpp>
using namespace std;
#include <sstream>
#include <iostream>
//#include "ResourcePath.hpp"
#include "player.h"
#include "entity.h"
#include "enemy.h"
#include "wall.h"
#include "fireball.h"
#include <ctime>
#include <time.h>
#include "level.h"
#include <fstream>
int main()
{
	//
	float playerMovementSpeed = 0.1;
	float counterWalking = 0;
	int counter;
	int counter2;
	sf::Clock clock;
	sf::Clock clock2;
	sf::Clock clock3;

	level level1;
	ifstream plik22;
	fstream plikIloZab;
	
	plikIloZab.open("iloscPrzeciwnikow.txt");
	plikIloZab << "0";
	plikIloZab.close();

	plik22.open("test.txt");
	plik22 >> level1.zmianaPoziom;
	plik22.close();



	//tworzenie okna
	sf::RenderWindow window(sf::VideoMode(1280, 720), "GAME");
	window.setFramerateLimit(60);
	

	//view widok

	sf::View view1(sf::FloatRect(200, 200, 300, 200));
	view1.setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
	view1.setCenter(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
	window.setView(view1);

	///////////////////////////////////////////////////////wczytywanie////////////////////////////////////////////////////////////




	//wczytywanie font
	sf::Font font;
	if (!font.loadFromFile("arial.ttf"))
	{
		return EXIT_FAILURE;
	}
	
	//wczytywanie dzwiekow
	sf::SoundBuffer buffer;
	if(!buffer.loadFromFile("scary1.wav"))
	{
		return EXIT_FAILURE;
	}
	sf::Sound soundDie;
	soundDie.setBuffer(buffer);
	
	//wczytywanie dzwiekow 2
	sf::SoundBuffer buffer2;
	if (!buffer2.loadFromFile("song2.wav"))
	{
		return EXIT_FAILURE;
	}
	sf::Sound sound1;
	sound1.setBuffer(buffer2);

	//wczytanie textur

	//player
	sf::Texture texturePlayer;
	if(!texturePlayer.loadFromFile("player.png"))
	{
		return EXIT_FAILURE;
	}
	//enemy1
	sf::Texture textureEnemy1;
	if (!textureEnemy1.loadFromFile("enemy1Sheet.png"))
	{
		return EXIT_FAILURE;
	}
	//fireball
	sf::Texture textureFireball;
	if (!textureFireball.loadFromFile("fireball.png"))
	{
		return EXIT_FAILURE;
	}

	///////////////////////////////////////////////////////////////////////tworzenie
	

	

	// tworzenie  enemy

	class enemy enemy1;
	enemy1.sprite.setTexture(textureEnemy1);
	enemy1.sprite.setTextureRect(sf::IntRect(50, 0, 50, 50));

	vector<enemy>::const_iterator iter;
	vector<enemy> enemyArray;
	enemy1.text.setFont(font);
	enemy1.text.setCharacterSize(12);
	enemy1.text.setColor(sf::Color::Red);
	enemy1.textName.setFont(font);
	enemy1.textName.setCharacterSize(15);
	enemy1.textName.setColor(sf::Color::Red);

	for (int i = 0; i < level1.poziom; i++) 
	{
		enemy1.rect.setPosition(400, 300);
		enemyArray.push_back(enemy1);
	}

	//enemy1.rect.setPosition(400,300);
	//enemyArray.push_back(enemy1);

    //enemy1.rect.setPosition(500, 300);
	//enemyArray.push_back(enemy1);


	//wall vector array
	vector<wall>::const_iterator iterWall;
	vector<wall> wallArray;
	class wall wall1;
	wall1.rect.setPosition(100, 100);
	wallArray.push_back(wall1);
	wall1.rect.setPosition(400, 400);
	wallArray.push_back(wall1);

	//fireball
	class fireball fireball1;
	fireball1.sprite.setTexture(textureFireball);
	fireball1.sprite.setTextureRect(sf::IntRect(0, 0, 30, 30));

	vector<fireball>::const_iterator iterFireball;
	vector<fireball> fireballArray;


	//text vector array



	class player Player1;
	Player1.sprite.setTexture(texturePlayer);
	//text licznik zabojstw
	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(18);
	text.setColor(sf::Color::Green);
	text.setPosition(Player1.rect.getPosition().x-window.getSize().x/2, Player1.rect.getPosition().y - window.getSize().y / 2);
	//text.setPosition(100, 10);
	text.setString("test");


	/////////////////////////////////////////////////////////////////////////
	while (window.isOpen()) 
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) 
			{
				window.close();
			}
		}



		window.clear();

		//clock
		sf::Time elapsed1 = clock.getElapsedTime();
		sf::Time elapsed2 = clock2.getElapsedTime();
		sf::Time elapsed3 = clock3.getElapsedTime();
		

	
		/////////////zmiana level-u////////////////////////////////////////////////////////////
		plik22.open("test.txt");
		plik22 >> level1.zmianaPoziom;
		plik22.close();
		if(level1.poziom!=level1.zmianaPoziom)
		{
			level1.iloZab = 0;
			plikIloZab.open("iloscPrzeciwnikow.txt");
			plikIloZab << level1.iloZab;
			plikIloZab.close();

			level1.iloPrzeciwnikow = level1.poziom *level1.poziom;
			if (level1.iloLifePrzeciwnikow != 0) 
			{


				

				
				for (counter = 0; counter < level1.iloPrzeciwnikow; counter++)
				{
					enemyArray[counter].destroy = true;

				}
				
			}
			level1.poziom = level1.zmianaPoziom;
			level1.iloPrzeciwnikow = level1.poziom *level1.poziom;
			level1.iloLifePrzeciwnikow = level1.iloPrzeciwnikow;
			//usuniecie starych enemy
			//delete old enemy

			
			

			
			//utworzenie enemy
			for (int i = 0; i < level1.iloPrzeciwnikow; i++)
			{
				enemy1.rect.setPosition(400, 300);
				enemyArray.push_back(enemy1);
			}
		}
		//////////////////////////////////////////////////////////////////////////////


		/*
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		{
			if (elapsed3.asSeconds() >= 0.5)
			{
				clock3.restart();
				plik22.open("test.txt");
				plik22 >> level1.poziom;
				plik22.close();
				for (int i = 0; i < level1.poziom; i++)
				{
					enemy1.rect.setPosition(400, 300);
					enemyArray.push_back(enemy1);
				}
			}
		}

		*/


		//shoot fireball
		

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
			{
				if (elapsed1.asSeconds() >= 0.5)
				{

					clock.restart();
					fireball1.rect.setPosition(Player1.rect.getPosition().x + Player1.rect.getSize().x / 2, Player1.rect.getPosition().y + Player1.rect.getSize().y / 2);
					fireball1.direction = Player1.direction;
					fireballArray.push_back(fireball1);
				}
			}

		
		
		//collides player with wall
		counter = 0;
		for (iterWall = wallArray.begin(); iterWall != wallArray.end(); iterWall++)
		{
			if(Player1.rect.getGlobalBounds().intersects(wallArray[counter].rect.getGlobalBounds()))
			{
				//hit
				if (Player1.direction == 0) 
				{
					Player1.canMoveUp = false;
					Player1.rect.move(0, 1);
				}
				else if (Player1.direction == 1)
				{
					Player1.canMoveDown = false;
					Player1.rect.move(0, -1);
				}
				else if (Player1.direction == 2)
				{
					Player1.canMoveLeft = false;
					Player1.rect.move(1, 0);
				}
				else if (Player1.direction == 3)
				{
					Player1.canMoveRight = false;
					Player1.rect.move(-1, 0);
				}
				else 
				{
				
				}
			}


			counter++;
		}
		
		//collides player with enemy
		counter = 0;
		for (iter = enemyArray.begin(); iter != enemyArray.end(); iter++)
		{
			if (Player1.rect.getGlobalBounds().intersects(enemyArray[counter].rect.getGlobalBounds()))
			{
				//hit
				if (Player1.direction == 0)
				{
					Player1.canMoveUp = false;
					Player1.rect.move(0, 1);
				}
				else if (Player1.direction == 1)
				{
					Player1.canMoveDown = false;
					Player1.rect.move(0, -1);
				}
				else if (Player1.direction == 2)
				{
					Player1.canMoveLeft = false;
					Player1.rect.move(1, 0);
				}
				else if (Player1.direction == 3)
				{
					Player1.canMoveRight = false;
					Player1.rect.move(-1, 0);
				}
				else
				{

				}
			}


			counter++;
		}
		
		//collides Enemy with wall
		counter = 0;
		counter2 = 0;
		for (iterWall = wallArray.begin(); iterWall != wallArray.end(); iterWall++)
		{
			counter2 = 0;
			for (iter = enemyArray.begin(); iter != enemyArray.end(); iter++)
			{
				if (enemyArray[counter2].rect.getGlobalBounds().intersects(wallArray[counter].rect.getGlobalBounds()))
					//if (wallArray[counter].rect.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds()))
				{
					//hit
					if (enemyArray[counter2].direction == 0)
					{
						enemyArray[counter2].canMoveUp = false;
						enemyArray[counter2].rect.move(0, 1);
					}
					else if (enemyArray[counter2].direction == 1)
					{
						enemyArray[counter2].canMoveDown = false;
						enemyArray[counter2].rect.move(0, -1);
					}
					else if (enemyArray[counter2].direction == 2)
					{
						enemyArray[counter2].canMoveLeft = false;
						enemyArray[counter2].rect.move(1, 0);
					}
					else if (enemyArray[counter2].direction == 3)
					{
						enemyArray[counter2].canMoveRight = false;
						enemyArray[counter2].rect.move(-1, 0);
					}
					else
					{

					}
				}
				counter2++;
			}

			counter++;
		}

		//collides Enemy with fireball
		counter = 0;
		for (iterFireball = fireballArray.begin(); iterFireball != fireballArray.end(); iterFireball++)
		{
			counter2 = 0;
			for(iter = enemyArray.begin(); iter != enemyArray.end(); iter++)
			{
				if (fireballArray[counter].rect.getGlobalBounds().intersects(enemyArray[counter2].rect.getGlobalBounds()))
				{

					enemyArray[counter2].hp-=fireballArray[counter].attackDamage;
					if (enemyArray[counter2].hp <= 0)
					{
						enemyArray[counter2].alive = false;
						level1.iloZab++;
						plikIloZab.open("iloscPrzeciwnikow.txt");
						plikIloZab << level1.iloZab;
						plikIloZab.close();
						level1.iloLifePrzeciwnikow--;
					}

				}
				counter2++;
			}
			counter++;
		}

		//delete dead enemy || destroy enemy (new level)
		counter = 0;
		for (iter = enemyArray.begin(); iter!= enemyArray.end(); iter++)
		{
			if (enemyArray[counter].alive==false)
			{
				soundDie.setVolume(1);
				soundDie.play();
				enemyArray.erase(iter);
				break;
			}
			
			if (enemyArray[counter].destroy == true)
			{
				enemyArray.erase(iter);
				break;
			}
			
			counter++;
		}

		//draw wall
		counter = 0;
		for (iterWall = wallArray.begin(); iterWall != wallArray.end(); iterWall++)
		{

			window.draw(wallArray[counter].rect);


			counter++;
		}

		
		//draw enemy
		counter = 0;
		for(iter=enemyArray.begin();iter!=enemyArray.end();iter++)
		{
			enemyArray[counter].text.setString("hp "+ to_string(enemyArray[counter].hp)+"/"+ to_string(enemyArray[counter].hpMax));

			window.draw(enemyArray[counter].text);
			window.draw(enemyArray[counter].textName);

			enemyArray[counter].update();
			enemyArray[counter].updateMovement();
			
			//window.draw(enemyArray[counter].rect);
			window.draw(enemyArray[counter].sprite);
			counter++;
		}

		
		//draw fireball

		counter = 0;
		for (iterFireball = fireballArray.begin(); iterFireball != fireballArray.end(); iterFireball++)
		{
			fireballArray[counter].update();
			fireballArray[counter].updateMovement();
			//window.draw(fireballArray[counter].rect);
			window.draw(fireballArray[counter].sprite);
			counter++;
		}

		//muzyka

		if (sound1.getStatus()!= sound1.Playing)
		{
			//clock2.restart();
			sound1.setVolume(2);
			sound1.play();
			
			
		}
		

		
		////////////////////////////////////////////////////////////////////////////////////
		//update
	
		fireball1.update();
		enemy1.update();
		

		Player1.update();
		Player1.updateMovement();

		//player view
		window.setView(view1);
		view1.setCenter(Player1.rect.getPosition());

		//wyswietlenie textu
		text.setPosition(Player1.rect.getPosition().x - window.getSize().x / 2, Player1.rect.getPosition().y - window.getSize().y / 2);
		window.draw(text);

		window.draw(Player1.sprite);
		window.display();
	}

}