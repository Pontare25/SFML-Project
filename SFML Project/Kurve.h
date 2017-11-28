#ifndef Kurve_h
#define Kurve_h
#include <string>
#include <SFML/Graphics.hpp>
#include "Line.h"
#include <math.h>
#include "Game.h"

class Kurve
{
private:
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
