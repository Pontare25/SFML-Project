#ifndef Powerups_h
#define Powerups_h
#include "SFML\Graphics.hpp"
#include <math.h>

class Powerups : public sf::Drawable
{
private:
	sf::Texture ligthning;
	sf::Sprite ligthningSprite;
	sf::Sprite powerup;
	const int nrOfPowerups = 1;
	float powerupSize;

	sf::RectangleShape rect;
	int powerUpID;
	sf::RectangleShape border;

public:
	Powerups();
	~Powerups();

	void SetBorder(sf::RectangleShape& border);
	int GetPowerupID();
	void newPowerup();

	sf::FloatRect GetSpriteBounds();

	void update(float dt);
	void draw(sf::RenderTarget& t, sf::RenderStates s) const;
};

#endif // !Powerups_h
