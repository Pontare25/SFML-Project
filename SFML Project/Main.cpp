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
	sf::RenderWindow window(sf::VideoMode(800, 800), "Achtung");
	srand(time(0));
	Game game1;

	cout << "TEst";

	while (window.isOpen())
	{
		float dt = clock.restart().asSeconds();

		

		window.clear();
		
		window.display();

	}
	cin.get();
	return 0;
}