#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

#include "Game.h"
#include <ctime>
#include "math.h"

using namespace std;


int main()
{
	sf::Clock clock;
	sf::RenderWindow window(sf::VideoMode(1200, 900), "Achtung");
	srand(time(0));
	Game game1;
	
	string name = "Pontus";
	game1.AddPlayer(name, sf::Keyboard::Right, sf::Keyboard::Left, sf::Color::Red);

	while (window.isOpen())
	{
		float dt = clock.restart().asSeconds();

		

		window.clear();
		//Draw funktioner


		window.display();

	}
	cin.get();
	return 0;
}