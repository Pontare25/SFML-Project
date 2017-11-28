#include "Kurve.h"

Kurve::Kurve(sf::Color playerColor)
{
	this->playerColor = playerColor;
	this->speed = 2.0;
	this->direction = {cos(angle), sin(angle)};
	this->positionX = rand() % 900;
	this->positionY = rand() % 900;

}

Kurve::~Kurve()
{
	//Empty
}

void Kurve::ChangeDir(float angleChange)
{
	this->angle = angleChange;
}
