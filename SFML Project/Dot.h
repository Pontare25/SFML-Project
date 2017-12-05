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
	float PI = 3.145;
	sf::Vector2f position;
	sf::CircleShape dot;
	sf::Vector2f direction;
	sf::Vector2f windowSize;
	sf::Keyboard::Key rightKey;
	sf::Keyboard::Key leftKey;

public:
	Dot(float width, float height, sf:: Color playerColor, sf::Keyboard::Key rightKey, sf::Keyboard::Key leftKey);

	void SetPosition(sf::Vector2f newPosition, float angle=0);
	sf::Vector2f GetPosition();
	sf::Vector2f GetDirection();
	float GetSize();
	void SetSize(float newSize);
	void SetSpeed(float newSpeed);
	
	void move(sf::Vector2f distance)
	{
		dot.move(distance);
	}
	
	void Draw()
	{
		
	}
};


#endif