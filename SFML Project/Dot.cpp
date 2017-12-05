#include "Dot.h"

Dot::Dot(float width, float height, sf::Color playerColor)
{
	size = 5.0f;
	speed = 100.0f;
	float angle = rand() % 360 + 50;
	dot.setPosition((rand() % int(width) + 100), (rand() % int(height) + 100));
	dot.setFillColor(playerColor);
	dot.setRadius(size);
	windowSize ={width, height};

}
