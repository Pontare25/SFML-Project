#include "Kurve.h"
#include "Game.h"



Kurve::Kurve(sf::Color playerColor, float width, float height)
{
	this->playerColor = playerColor;
	this->speed = 2.0;
	this->direction = { cos(angle), sin(angle) };
	this->positionX = rand() % int(width); //width from Game
	this->positionY = rand() % int(height); //height from game
}

Kurve::~Kurve()
{
	//Empty
}

void Kurve::ChangeDir(float angleChange)
{
	this->angle = angleChange;
}
