#ifndef Kurve_h
#define Kurve_h
#include "SFML\Graphics.hpp"

class Kurve : public sf::Drawable
{
private:
	
	sf::Color playerColor;
	float size;
	
	sf::VertexArray vArray;

	sf::Vector2f direction;

	void draw(sf::RenderTarget& t, sf::RenderStates s) const;


public:
	Kurve(sf::Color playerColor, float dotSize, sf::Vector2f originPoint, sf::Vector2f direction);
	Kurve();
	~Kurve();
	//void SetPosition(sf::Vector2f position);
	static float VectorLength(sf::Vector2f v);

	void SetstartPoint(sf::Vector2f startPoint);


	sf::VertexArray GetKurveArray();

	void Update(float dt, sf::Vector2f position);
	void draw();

 };

#endif // !Kurve_h
