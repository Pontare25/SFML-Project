#ifndef Kurve_h
#define Kurve_h
#include <string>
#include <SFML/Graphics.hpp>
#include "Line.h"
#include <math.h>
#include "Game.h"
#include <SFML\Graphics.hpp>

class Kurve
{
private:
	sf::Vector2f size =5.0;
	sf::CircleShape dot;
	sf::Color playerColor;
	float positionX, positionY;
	float angle;
	sf::Vector2f direction;
	float speed;

public:
	void update(float deltaTime);
	Kurve(sf::Color playerColor);
	Kurve();
	~Kurve();
	
	void ChangeDir(float angleChange);

};

#endif // !Kurve_h
