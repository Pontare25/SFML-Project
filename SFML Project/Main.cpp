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
	sf::RenderWindow window(sf::VideoMode(1200, 900), "Achtung Die Kurve");
	srand(time(0));
	Game game1;
	
	string name1 = "Pontus";
	game1.AddPlayer(name1, sf::Keyboard::Right, sf::Keyboard::Left, sf::Color::Red);
	string name2 = "Jim";
	game1.AddPlayer(name2, sf::Keyboard::D, sf::Keyboard::A, sf::Color::Green);

	while (window.isOpen())
	{
		float dt = clock.restart().asSeconds();



		window.clear();
		game1.Update(dt);
		window.draw(game1);

		window.display();

	}
	cin.get();
	return 0;
}