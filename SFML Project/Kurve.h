#ifndef Kurve_h
#define Kurve_h
#include "SFML\Graphics.hpp"

class Kurve : public sf::Drawable
{
private:
	int nrOfLinePoints;
	void draw(sf::RenderTarget& t, sf::RenderStates s) const;

public:
	

	Kurve(sf::Color playerColor, sf::Vector2f direction, float dotSize, sf::Vector2f originPoint);
	~Kurve();

	void Update(sf::Vector2f position);
	void Draw();

 };

#endif // !Kurve_h
