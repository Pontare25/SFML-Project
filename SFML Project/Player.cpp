#include "Player.h"

void Player::draw(sf::RenderTarget & t, sf::RenderStates s) const
{
	t.draw(playerDot);
}

Player::Player(const std::string& name, sf::Keyboard::Key rightKey, sf::Keyboard::Key leftKey, sf::Color playerColor, sf::RectangleShape& border)
	: playerDot(playerColor, rightKey,leftKey, border)
{
	this->name = name; 
	this->playerColor = playerColor;
	this->score = 0;
	this->alive = true;
	this->border = border;

	sf::Vector2f borderpositioned = { float(rand() % int(border.getSize().x) + border.getPosition().x) + 40.0f, float(rand() % int(border.getSize().y) + border.getPosition().y - 40.0f) };
	playerDot.SetPosition(borderpositioned, float(rand() % 360));
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
	sf::Vector2f position = { float(rand() % int(border.getSize().x) + border.getPosition().x) + 40.0f, float(rand() % int(border.getSize().y) + border.getPosition().y - 40.0f) }; //slumpar fram en ny position
	playerDot.SetPosition(position, float(rand() % 360)); //sätter positionen och slumpar en ny vinkel
	playerDot.SetSpeed(10.0f);
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

sf::VertexArray Player::GetKurveArr()
{
	return playerDot.GetKurveArr();
}

Dot Player::GetPlayerDot()
{
	return playerDot;
}


bool Player::checkCollision()
{
	bool retValue = false;

	sf::Vector2f xBounds(border.getPosition().x, border.getPosition().x +border.getSize().x);
	sf::Vector2f yBounds(border.getPosition().y, border.getPosition().y + border.getSize().y);

	//Checks if it hits the border
	if ((playerDot.GetPosition().x + playerDot.GetSize()) >= xBounds.y || (playerDot.GetPosition().x + playerDot.GetSize()) <= xBounds.x || (playerDot.GetPosition().y + playerDot.GetSize()) >= yBounds.y || (playerDot.GetPosition().y + playerDot.GetSize()) <= yBounds.x)
	{
		Kill();
		retValue = true;
	}
	//Checks if dot hits it's own kurve
	if (playerDot.selfIntersect())
	{
		Kill();
		retValue = true; 
	}
	return retValue;
}

//Checks from Game if another dot hits it's kurve
bool Player::otherCollision(const sf::FloatRect & box)
{
	return playerDot.intersects(box);
}

void Player::Normalize()
{
	playerDot.SetSpeed(10.0f);


	//Här kan andra grejer från powerups normaliseras
}

