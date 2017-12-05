#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Game.h"
#include <ctime>

using namespace std;


int main()
{
	sf::Clock clock;
	sf::RenderWindow window(sf::VideoMode(800, 800), "Achtung");

	while (window.isOpen())
	{
		float deltaTime = clock.restart().asSeconds();

		cout << "Welcome to Achtung Die Kurve!\nHow many players? (2 minimum)";
		int nrOfPlayers;
		cin >> nrOfPlayers;
		cin.ignore();

		Game achtung1;
		//Player 1
		cout << "Enter name: \n";
		string name;
		getline(cin, name);

		sf::Keyboard::Key rightKey = sf::Keyboard::Key::S;
		sf::Keyboard::Key leftKey = sf::Keyboard::Key::A;
		sf::Color playerColor = sf::Color::Red;
		cout << "You are the color Red and will use the 'A' key to turn left and the 'S' key to turn right\n";
		achtung1.AddPlayer(name, rightKey, leftKey, playerColor);

		//Player 2
		cout << "Enter name: \n";
		string name2;
		getline(cin, name2);

		sf::Keyboard::Key rightKey2 = sf::Keyboard::Key::L;
		sf::Keyboard::Key leftKey2 = sf::Keyboard::Key::K;
		sf::Color playerColor2 = sf::Color::Green;
		cout << "You are the color Green and will use the 'K' key to turn left and the 'L' key to turn right\n";
		achtung1.AddPlayer(name2, rightKey2, leftKey2, playerColor2);

	}
	cin.get();
	return 0;
}