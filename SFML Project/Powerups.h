#ifndef Powerups_h
#define Powerups_h
#include "SFML\Graphics.hpp"
#include <math.h>

class Powerups : public sf::Drawable
{
private:
	sf::Texture ligthning;
	sf::Texture slow;
	sf::Texture Inverted;
	/*sf::Sprite ligthningSprite;
	sf::Sprite powerup;*/
	int nrOfPowerups;
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
