#include "Game.h"

void Game::draw(sf::RenderTarget & t, sf::RenderStates s) const
{ 
	t.draw(title);
	/*if (pausing == true)
	{
		t.draw(pressSpace);
		pausing =PausSegment();
	}
*/

//	t.draw(pressSpace);
	t.draw(roundText);
	t.draw(playerText);
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
	playerArr  = new Player*[playerCap];
	this->pausing = true;

	if (!font.loadFromFile("arial.ttf"))
	{
		//std::cout << "Failure to load text\n";
	}
	title.setFont(font);
	title.setString("Welcome to Achtung Die Kurve");
	title.setCharacterSize(24);
	title.setColor(sf::Color::Yellow);
	title.setPosition(450.0f, 0.0f);
	title.setStyle(sf::Text::Bold);

	pressSpace.setFont(font);
	pressSpace.setString("Press Space to continue");
	pressSpace.setCharacterSize(42);
	pressSpace.setColor(sf::Color::White);
	pressSpace.setPosition(450.0f, 450.0f);

	roundText.setFont(font);
	roundText.setString("Round:\t" + std::to_string(roundCount));
	roundText.setCharacterSize(24);
	roundText.setColor(sf::Color::Yellow);
	roundText.setPosition(950.0f, 20.0f);


	playerText.setFont(font);
	playerText.setString("Players\n" + GetAllPlayerInfo() + "hej"); // funkar ej!
	playerText.setCharacterSize(24);		
	playerText.setColor(sf::Color::White);
	playerText.setPosition(950.0f, 50.0f);

	
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

bool Game::RoundEnded() const
{
	int deathCounter = 0;
	int aliveIndex = -1;
	for (int i = 0; i < playerCount; i++)
	{
		if (playerArr[i]->IsAlive() == false)
		{
			deathCounter++;
		}
		else 
		{
			aliveIndex = i;
		}
	}
	if (deathCounter == (playerCount-1))
	{
		playerArr[aliveIndex]->AddScore(); //Adds score to the winner
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
	roundCount++;
	for (int i = 0; i < playerCount; i++)
	{
		playerArr[i]->Resurrect(); 	//alive = true, nya positioner och vinklar slumpas
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

bool Game::PausSegment()
{
	bool retValue = true;
	if (sf::Keyboard::isKeyPressed(sf:: Keyboard:: Space))
	{

		retValue = false;
	}
	return retValue;
}

bool Game::kurveCollision()
{
	bool retValue = false;

	

	playerArr[0]->GetKurveArr();

	for (int i = 0; i < playerCount; i++)
	{
		//if (collision between lines)
		{
			playerArr[i]->Kill();
			retValue = true;
		}
	}

	return retValue;
}

std::string Game::GetAllPlayerInfo()
{
	std::string retString;
	for (int i = 0; i < playerCount; i++)
	{
		retString += playerArr[i]->ToString() + "\n\n";
	}
	return retString;
}


void Game::Update(float dt)
{
	if (RoundEnded() == false)
	{
		for (int i = 0; i < playerCount; i++)
		{
			playerArr[i]->update(dt);
		}
	}
	else
	{
	//	pausing = PausSegment();//Någon pausruta. typ, "To start next round press space."
		NewRound(); // Resurrects every player, randomizes new positions and angles
		Update(dt);
	}
}
