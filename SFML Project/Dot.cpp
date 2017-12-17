#include "Dot.h"


void Dot::draw(sf::RenderTarget & t, sf::RenderStates s) const
{
	t.draw(dot);
	t.draw(kurve);
}

Dot::Dot(float width, float height, sf::Color playerColor, sf::Keyboard::Key rightKey, sf::Keyboard::Key leftKey)	
{
	this->rightKey = rightKey;
	this->leftKey = leftKey;
	size = 5.0f;
	speed = 10.0f;
	float angle = float(rand() % 360 + 50);
	//this->position = sf::Vector2f((rand() % int(width) + 100), (rand() % int(height) + 100));

	dot.setPosition((rand() % int(width) + 100), (rand() % int(height) + 100));
	dot.setFillColor(playerColor);
	dot.setRadius(size);
	windowSize = { width, height };
	kurve = Kurve(playerColor, GetSize(), GetPosition(), GetDirection());
}

void Dot::SetPosition(sf::Vector2f newPosition, float angle)
{
	dot.setPosition(newPosition);
	kurve.SetstartPoint(newPosition);
	//this->position = newPosition;
	this->angle = angle;
}

sf::Vector2f Dot::GetPosition()
{
	return dot.getPosition();
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

float Dot::GetSpeed()
{
	return this-> speed;
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
	this->angle = newAngle;
}

sf::VertexArray Dot::GetKurveArr()
{
	return kurve.GetKurveArray();
}



void Dot::Update(float dt)
{
	if (angle > 360)
	{
		angle -= 360;
	}
	if (sf::Keyboard::isKeyPressed(rightKey))
	{
		angle -= speed*dt*PI*20 / 180.0f;
	}
	else if (sf::Keyboard::isKeyPressed(leftKey))
	{
		angle += speed*dt*PI*20 / 180.0f;
	}
	float factor = GetSpeed()*dt;

	direction = {  sin(angle)*speed, cos(angle)*speed };

	//move(direction*factor);
	dot.move(direction*factor);

	kurve.Update(dt, dot.getPosition());
}

void Dot::move(sf::Vector2f distance)
{ 
	dot.move(distance);
}

void Dot::Draw()
{
}
