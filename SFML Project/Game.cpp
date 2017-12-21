#include "Game.h"

void Game::draw(sf::RenderTarget & t, sf::RenderStates s) const
{ 
	t.draw(title);
	t.draw(border);
	if (pausing == true)
	{
		t.draw(pressSpace);
	}
	t.draw(roundText);
	t.draw(playerText);
	for (int i = 0; i < playerCount; i++)
	{
		t.draw(*playerArr[i]);
	}
	if (powerupExists == true)
	{
		t.draw(pow);
	}
}

Game::Game()
{
	this->playerCap = 2;
	this->playerCount = 0;
	this->roundCount = 1;
	playerArr = new Player*[playerCap];
	
	this->pausing = false;

	if (!font.loadFromFile("arial.ttf"))
	{
		//std::cout << "Failure to load text\n";
	}
	if (!font2.loadFromFile("old_stamper.ttf"))
	{
		font2 = font;
		//std::cout << "Failure to load text\n";
	}
	if (!font3.loadFromFile("plasdrip.ttf"))
	{
		font3 = font;
		//std::cout << "Failure to load text\n";
	}
	title.setFont(font2);
	title.setString("Welcome to Achtung Die Kurve");
	title.setCharacterSize(30);
	title.setColor(sf::Color::Yellow);
	title.setPosition(175.0f, 0.0f);
	title.setStyle(sf::Text::Bold);

	pressSpace.setFont(font);
	pressSpace.setString("Press Space to continue");
	pressSpace.setCharacterSize(60);
	pressSpace.setColor(sf::Color::White);
	pressSpace.setPosition(140.0f, 425.0f);
	pressSpace.setStyle(sf::Text::Bold);

	roundText.setFont(font3);
	roundText.setString("Round\t" + std::to_string(roundCount));
	roundText.setCharacterSize(30);
	roundText.setColor(sf::Color::Yellow);
	roundText.setPosition(950.0f, 40.0f);

	playerText.setFont(font);
	playerText.setString("Players\n\n" + GetAllPlayerInfo()); // funkar ej!
	playerText.setCharacterSize(30);
	playerText.setColor(sf::Color::Yellow);
	playerText.setPosition(950.0f, 80.0f);

	border.setSize({ 900.0f, 835.0f });
	border.setOutlineColor(sf::Color::Yellow);
	border.setPosition({ 10.0f, 50.0f });
	border.setOutlineThickness(3.0f);
	border.setFillColor(sf::Color::Black);
	
	this->powerTime = 0.0f;
	this->playerPowerTime = 0.0f;
	this->powerupExists = false;
	this->playerHasPowerup = false;
	this->powerPlayer = -1;
	pow.SetBorder(border);
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
	
	playerArr[playerCount] = new Player(name, rightKey, leftKey, playerColor, border);
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
	return playerCount == (deathCounter + 1);
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

void Game::otherPlayerCollision()
{
	for (int i = 0; i < playerCount; i++)
	{
		for (int k = 0; k < playerCount; k++)
		{
			if (i != k)
			{
				if (playerArr[i]->otherCollision(playerArr[k]->GetPlayerDot().GetDotBounds()))
				{
					playerArr[k]->Kill();
				}
			}
		}
	}
}

std::string Game::GetAllPlayerInfo() const
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
	playerText.setString("Players\n" + GetAllPlayerInfo());
	roundText.setString("Round\t" + std::to_string(roundCount));
	if (RoundEnded() == false)
	{
		otherPlayerCollision();
		for (int i = 0; i < playerCount; i++)
		{
			playerArr[i]->update(dt);
		}

		powerTime += dt;
		if (powerTime >= 3.0f && playerHasPowerup == false)
		{
			if (powerupExists == false)
			{
				pow.newPowerup();//spawna in en ny powerup
				powerupExists = true;
				powerTime = 0.0f;
			}
		}

		if (powerupExists)
		{
			for (int i = 0; i < playerCount; i++)
			{
				if (playerArr[i]->otherCollision(pow.GetSpriteBounds()))
				{
					powerPlayer = i;
					playerHasPowerup = true;
					powerupExists = false;
					switch (pow.GetPowerupID())
					{
					case 1://ligthning
						playerArr[powerPlayer]->SetPlayerSpeed(15.0f);
						break;

						case 2: //snail
						for (int i = 0; i < playerCount; i++)
						{
							if (i != powerPlayer)
							{
								playerArr[i]->GetPlayerDot().SetSpeed(5.0f);
							}
						}

						
					default: //ligthning
						playerArr[i]->GetPlayerDot().SetSpeed(15.0f);
						break;
					}
				}
			}
		}
		if (playerHasPowerup)
		{
			playerPowerTime += dt;
		}
		if (playerPowerTime >= 3.0f)
		{
			for (int i = 0; i < playerCount; i++)
			{
				playerArr[i]->Normalize();
			}
			playerHasPowerup = false;
			playerPowerTime = 0.0f;
		}
	}


	else
	{
		pausing = true;
		pausing = PausSegment();
		if (pausing == false)
		{
			for (int i = 0; i < playerCount; i++)
			{
				if (playerArr[i]->IsAlive())
				{
					playerArr[i]->AddScore();
						i = playerCount;
				}
			}
			NewRound(); // Resurrects every player, randomizes new positions and angles
		}
	}
}
