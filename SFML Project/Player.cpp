#include "Player.h"

void Player::draw(sf::RenderTarget & t, sf::RenderStates s) const
{
	t.draw(playerDot);
	t.draw(bounds);
}

Player::Player(const std::string& name, sf::Keyboard::Key rightKey, sf::Keyboard::Key leftKey, sf::Color playerColor)
	: playerDot(1200.0, 900.0, playerColor, rightKey,leftKey)
{
	this->name = name; 
	this->playerColor = playerColor;
	this->score = 0;
	this->alive = true;
	sf::Vector2f position = { float(rand() % int(1200.0)), float(rand() % int(900.0)) };
	playerDot.SetPosition(position, float(rand()%360));

	bounds.setScale(1200.0f, 900.0f);
	bounds.setPosition(600, 450);
	bounds.setFillColor(sf::Color::Green);
}

Player::~Player()
{
	//Empty
}

void Player::update(float dt)
{
	checkCollision();
	playerDot.Update(dt);
}

bool Player::IsAlive()
{
	return alive;
}

void Player::Kill()
{
	alive = false;
	playerDot.SetSpeed(0.0f);
}

void Player::Resurrect()
{
	alive = true;
	sf::Vector2f position = { float(rand() % int(1000.0)+100), float(rand() % int(700.0)+50)}; //slumpar fram en ny position
	playerDot.SetPosition(position, float(rand() % 360)); //sätter positionen och slumpar en ny vinkel
	playerDot.SetSpeed(0.01f);
}

void Player::AddScore()
{
	score++;
}

std::string Player::GetName() const
{
	return this-> name;
}

sf::Color Player::GetPlayerColor()
{
	return this-> playerColor;
}

int Player::GetScore() const
{
	return score;
}

std::string Player::ToString() const
{
	std::string retString;
	retString += "Name:\t" + name + "\n";
	//retString += "Color:\t" + std:: to_string(playerColor) + "\n";
	retString += "Score:\t" + std:: to_string(score) + "\n";
	
	return retString;
}

bool Player::checkCollision()
{
	bool retValue = false;
	
	sf::Vector2f rightXX(1200.0f, 0.0f);
	sf::Vector2f leftXX(0.0f, 0.0f);
	sf::Vector2f upperYY(0.0f, 900.0f);
	sf::Vector2f lowerYY(0.0f, 0.0f);


	float rightX(1200.0f);
	float leftX(0.0f);
	float upperY(900.0f);
	float lowerY(0.0f);

	//if (playerDot.GetPosition() >= rightXX || playerDot.GetPosition() <= leftXX || playerDot.GetPosition() >= upperYY || playerDot.GetPosition() <= lowerYY)
	//if (playerDot.GetPosition().x >= rightX || playerDot.GetPosition().x <= leftX || playerDot.GetPosition().y >= upperY || playerDot.GetPosition().y <= lowerY)
	if(playerDot.GetPosition().x >= rightXX.x || playerDot.GetPosition().x <= leftXX.x || playerDot.GetPosition().y >= upperYY.y || playerDot.GetPosition().y <= lowerYY.y)
	{
		Kill();
		retValue = true;
	}


	 
		/*if (playerDot.CheckBounds(bounds) == true)
		{
			retValue = true;
			Kill();
		}*/
	return retValue;
} 
