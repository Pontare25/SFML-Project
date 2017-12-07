#include "Player.h"

void Player::draw(sf::RenderTarget & t, sf::RenderStates s) const
{
	t.draw(playerDot);
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
}

Player::~Player()
{
	//Empty
}

void Player::update(float dt)
{
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
	sf::Vector2f position = { float(rand() % int(1200.0)), float(rand() % int(900.0))}; //slumpar fram en ny position
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
