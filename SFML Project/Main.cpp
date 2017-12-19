#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Game.h"
#include "Menu.h"
#include <ctime>
#include "math.h"

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	State* currentState = new Menu();

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
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		float dt = clock.restart().asSeconds();

		/*States nextState = currentState->Update(dt);
		window.clear();
		window.draw(*currentState);
		window.display();

		switch (nextState)
		{
		case States::MENU:
			delete currentState;
			currentState = new Menu();
			break;
		case States::GAME:
			delete currentState;
			currentState = new Game();
			break;
		case States::NO_CHANGE:
			break;
		}
		delete currentState;*/

		window.clear();
		game1.Update(dt);
		window.draw(game1);
		window.display();


	}
	return 0;
}