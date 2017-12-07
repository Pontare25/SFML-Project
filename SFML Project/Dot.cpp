#include "Dot.h"


void Dot::draw(sf::RenderTarget & t, sf::RenderStates s) const
{
	t.draw(dot);
}

Dot::Dot(float width, float height, sf::Color playerColor, sf::Keyboard::Key rightKey,
sf::Keyboard::Key leftKey)
{
	this->rightKey = rightKey;
	this->leftKey = leftKey;
	size = 5.0f;
	speed = 100.0f;
	float angle = float(rand() % 360 + 50);
	dot.setPosition((rand() % int(width) + 100), (rand() % int(height) + 100));
	dot.setFillColor(playerColor);
	dot.setRadius(size);
	windowSize = { width, height };
}

void Dot::SetPosition(sf::Vector2f newPosition, float angle)
{
	this->position = newPosition;
	this->angle = angle;
}

sf::Vector2f Dot::GetPosition()
{
	return this-> position;
}

sf::Vector2f Dot::GetDirection()
{
	return this-> direction;
}

float Dot::GetSize()
{
	return size;
}

void Dot::SetSize(float newSize)
{
	this->size = newSize;
}

void Dot::SetSpeed(float newSpeed)
{
	this->speed = newSpeed;
}

float Dot::GetAngle()
{
	return this->angle;
}

void Dot::SetAngle(float newAngle)
{
	this->angle += newAngle;
}

void Dot::Update(float dt)
{
	if (sf::Keyboard::isKeyPressed(rightKey))
	{
		SetAngle(dt*speed*PI / 180.0f);
	}
	else if (sf::Keyboard::isKeyPressed(leftKey))
	{
		SetAngle(-dt*speed*PI / 180.0f);
	}
	direction = { sin(angle)*speed, cos(angle)*speed };
	move(direction);
}
