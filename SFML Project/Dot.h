#ifndef Dot_h
#define Dot_h
#include "SFML\Graphics.hpp"
#include "math.h"


class Dot
{
private:
	float size;
	float speed;
	float angle;
	sf::Vector2f position;
	sf::CircleShape dot;
	sf::Vector2f direction;
	sf::Vector2f windowSize;

public:
	Dot(float width, float height, sf:: Color playerColor);

	void SetPosition(sf::Vector2f newPosition, float angle=0);
	sf::Vector2f GetPosition();
	sf::Vector2f GetDirection();
	float GetSize();
	void SetSize(float newSize);
	void SetSpeed(float newSpeed);
	void SetAngle(float newAngle);

	void move(sf::Vector2f distance)
	{
		dot.move(distance);
	}
	
	void DrawTo(sf::RenderWindow &window)
	{
		window.draw(dot);
	}
};


#endif