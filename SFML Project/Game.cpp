#include "Game.h"

Game::Game()
{
	this->playerCap = 2;
	this->playerCount = 0;
	this->roundCount = 1;

	playerArr = new Player[playerCap];

}

Game::~Game()
{
	delete[] playerArr;
}

void Game::AddPlayer(std::string & name, sf::Keyboard::Key rightKey, sf::Keyboard::Key leftKey, sf::Color playerColor)
{
	if (playerCount == playerCap)
	{
		ExpandPlayerArr();
	}
	Player toAdd(name, rightKey, leftKey, playerColor);
	playerArr[playerCount] = toAdd;
	playerCount++;
}

int Game::GetNrOfPlayers() const
{
	return playerCount;
}

bool Game::RoundEnded()
{
	int deathCounter = 0;
	for (int i = 0; i < playerCount; i++)
	{
		if (playerArr[i].IsAlive() == false)
		{
			deathCounter++;
		}

	}
	roundCount++;
	return playerCount == deathCounter - 1;
}

void Game::ExpandPlayerArr()
{
	playerCap = playerCap + 2;
	Player* temp = new Player[playerCap];
	for (int i = 0; i < playerCount; i++)
	{
		temp[i] = playerArr[i];
	}
	delete[] playerArr;
	playerArr = temp;
}
