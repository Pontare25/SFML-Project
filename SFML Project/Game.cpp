#include "Game.h"

Game::Game()
{
	this->playerCap = 2;
	this->playerCount = 0;
	this->roundCount = 1;
	playerArr = new Player*[playerCap];
}

Game::~Game()
{
	for (int i = 0; i < playerCount; i++)
	{
		delete playerArr[i];
	}
	delete[] playerArr;
}

void Game::AddPlayer(std::string & name, sf::Keyboard::Key rightKey, sf::Keyboard::Key leftKey, sf::Color playerColor)
{
	if (playerCount == playerCap)
	{
		ExpandPlayerArr();
	}
	
	playerArr[playerCount] = new Player(name, rightKey, leftKey, playerColor);
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
		if (playerArr[i]->IsAlive() == false)
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
	Player** temp = new Player*[playerCap];
	for (int i = 0; i < playerCount; i++)
	{
		temp[i] = playerArr[i];
	}
	delete[] playerArr;
	playerArr = temp;
}

void Game::Update(float dt)
{

	//Här skall avståndet avgöras för playerArr. for loop
	sf::Vector2f distance;

	//
	//
	//



	//
	//





	playerArr[0]->update(dt, distance);
}
