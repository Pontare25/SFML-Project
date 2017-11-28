#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace std;

void Update();
void Draw();

int main()
{
	cout << "Welcome to Achtung Die Kurve!\nHow many players? (2 minimum)";
	int nrOfPlayers;
	cin >> nrOfPlayers;
	cin.ignore();

	Game achtung1(nrOfPlayers);

	cout << "Enter name: \n";
	string name;
	getline(cin, name);

	sf::Keyboard::Key rightKey = sf::Keyboard::Key::S;
	sf::Keyboard::Key leftKey = sf::Keyboard::Key::A;
	sf::Color playerColor = sf::Color::White;
	
	achtung1.AddPlayer(name, rightKey, leftKey, playerColor);



	cin.get();
	return 0;
}

