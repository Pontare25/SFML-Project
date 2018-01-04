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
	//_crtBreakAlloc = 161;

	//State* currentState = new Menu();

	/*sf::Clock clock;
	sf::RenderWindow window(sf::VideoMode(1200, 900), "Achtung Die Kurve");
	srand(time(0));*/
	Game game1;

	cout << "Enter the number of players (minimum of two, maximum of four)\n";
	int players;
	cin >> players;
	cin.ignore();

	if (players < 2)
	{
		cout << "Two is the minimum!\n";
		players = 2;
	}
	if (players > 4)
	{
		cout << "Four is the maximum!\n";
		players = 4;
	}
	for (int i = 0; i < players; i++)
	{
		cout << "Enter name of player " << to_string(i + 1) << "\n";
		string name;
		getline(cin, name);

		switch (i)
		{
		case 0:
			game1.AddPlayer(name, sf::Keyboard::Right, sf::Keyboard::Left, sf::Color::Red);
			cout << name << " added with right key: RightKey, left key: LeftKey and the color: Red\n";
				break;
		case 1:
			game1.AddPlayer(name, sf::Keyboard::D, sf::Keyboard::A, sf::Color::Green);
			cout << name << " added with right key: D, left key: A and the color: Green\n";
			break;
		case 2:
			game1.AddPlayer(name, sf::Keyboard::L, sf::Keyboard::J, sf::Color::Blue); 
			cout << name << " added with right key: L, left key: J and the color: Blue\n";
			break;
		case 3:
			game1.AddPlayer(name, sf::Keyboard::B, sf::Keyboard::C, sf::Color::Magenta);
			cout << name << " added with right key: B, left key: C and the color: Magenta\n";
			break;
		default:
			break;
		}
		
	
	}

	cout << "Press Enter to start\n";
	cin.get();

	sf::Clock clock;
	sf::RenderWindow window(sf::VideoMode(1200, 900), "Achtung Die Kurve");
	srand(time(0));

	//string name1 = "Pontus";
	//game1.AddPlayer(name1, sf::Keyboard::Right, sf::Keyboard::Left, sf::Color::Red);
	//string name2 = "Ludvig";
	//game1.AddPlayer(name2, sf::Keyboard::D, sf::Keyboard::A, sf::Color::Green);
	///*string name3 = "Eric";
	//game1.AddPlayer(name3, sf::Keyboard::L, sf::Keyboard::K, sf::Color::Blue);*/

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

	system("cls");
	cout << "Rounds played: " << to_string(game1.GetRound()) << "\nThe winner is:\n" << game1.WinnerString() << "\n";
	cin.get();
	return 0;
}