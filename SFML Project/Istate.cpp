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

	cin.get();
	return 0;
}

