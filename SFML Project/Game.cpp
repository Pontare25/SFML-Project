#include "Game.h"

void Game::draw(sf::RenderTarget & t, sf::RenderStates s) const
{
	for (int i = 0; i < playerCount; i++)
	{
		t.draw(*playerArr[i]);
	}
}

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
	return this->playerCount;
}

bool Game::RoundEnded()
{
	int deathCounter = 0;
	int aliveIndex = -1;
	for (int i = 0; i < playerCount; i++)
	{
		if (playerArr[i]->IsAlive() == false)
		{
			deathCounter++;
			aliveIndex = i;
		}
	}
	if (playerCount == (deathCounter - 1))
	{
		playerArr[aliveIndex]->AddScore(); //Adds score to the winner
		roundCount++;
	}
	return playerCount == (deathCounter - 1);
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

void Game::NewRound()
{
	//Nya positioner och vinklar skall slumpas
	for (int i = 0; i < playerCount; i++)
	{
		playerArr[i]->Resurrect();
		/////


		/////

	}


}

int Game::WinnerIndex()
{
	int max = 0;
	int winnerIndex = -1;
	for (int i = 0; i < playerCount; i++)
	{
		if (playerArr[i]->GetScore() > max)
		{
			max = playerArr[i]->GetScore();
			winnerIndex = i;
		}
	}
	return winnerIndex;
}

void Game::Update(float dt)
{
	for (int i = 0; i < playerCount; i++)
	{
		playerArr[i]->update(dt);
	}
}
