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
	sf::Vector2f size =({5})
	sf::CircleShape dot;
	sf::Color playerColor;
	float positionX, positionY;
	float angle;
	sf::Vector2f direction;
	float speed;

public:
	Kurve(sf::Color playerColor, float width, float height);
	~Kurve();
	
	void ChangeDir(float angleChange);

};

#endif // !Kurve_h
