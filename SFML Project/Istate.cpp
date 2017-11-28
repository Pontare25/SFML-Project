#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace std;

void Update();
void Draw();

int main()
{
	cout << "Welcome to Achtung Die Kurve!\n How many players? (2 minimum)";
	int nrOfPlayers;
	cin >> nrOfPlayers;
	cin.ignore();

	Game achtung1(nrOfPlayers);




	cin.get();
	return 0;
}

