#include "Kurve.h"
#include "Game.h"



Kurve::Kurve(sf::Color playerColor)
{
	this->dot.setRadius(5);
	this->playerColor = playerColor;
	dot.setFillColor(playerColor);
	this->speed = 2.0;
	this->direction = { cos(angle), sin(angle) };
	this->positionX = rand() % int(800) - 50; //width from Game -100 för att spelaren inte skall spawna i väggen
	this->positionY = rand() % int(800) -50; //height from game
}

Kurve::Kurve()
{
}

Kurve::~Kurve()
{
	//Empty
}

void Kurve::ChangeDir(float angleChange)
{
	this->angle = angleChange;
}
