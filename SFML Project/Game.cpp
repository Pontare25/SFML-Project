#include "Game.h"

Game::Game()
{
	roundCount = 0;
	


}

Game::~Game()
{
	
}

States Game::Update()
{
	


	return States::NO_CHANGE;
}

void Game::draw(sf::RenderTarget & target, sf::RenderStates states) const
{



}

void Game::AddPlayer(std::string & name, sf::Keyboard::Key rightKey, sf::Keyboard::Key leftKey, sf::Color playerColor)
{
	if (playerCap == playerCount)
	{
		ExpandPlayerArr();
	}
	playerArr[playerCount++] = {name, rightKey, leftKey, playerColor};

}

int Game::GetNrOfPlayers() const
{
	return playerCount;
}

bool Game::GameEnded()
{
	bool retValue = false;
	int aliveCount;
	for (int i = 0; i < playerCount; i++)
	{
		if (playerArr[i].IsAlive() == true)
		{
			aliveCount++;
		}
	}
	if (aliveCount == (playerCount - 1)) //Dvs. en spelare kvar, vinnaren
	{
		retValue = true;
		roundCount++;
	}
	return retValue;
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


