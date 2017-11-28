#include "Kurve.h"



Kurve::Kurve(sf::Color playerColor)
{
	this->playerColor = playerColor;
	this->speed = 2.0;
	this->direction = { cos(angle), sin(angle) };
}

Kurve::~Kurve()
{
	//Empty
}



void Kurve::Dead() //Bör denna ligga i player istället?
{
	alive = false;
}

bool Kurve::IsAlive()//Bör denna ligga i player istället?
{
	return alive;
}

void Kurve::ChangeDir(float angleChange)
{
	this->angle = angleChange;
}
