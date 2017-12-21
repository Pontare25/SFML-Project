#include "Powerups.h"

Powerups::Powerups(sf::RectangleShape& border)
{
	this->border = border;
	powerupSize = 30.0f;
	if (!ligthning.loadFromFile("Ligthning.png"))
	{
		ligthning.create(powerupSize, powerupSize);
		//Texture not loaded
	}
	//ligthningSprite.setTexture(ligthning);
	rect.setSize({ powerupSize, powerupSize });

	newPowerup();
}

Powerups::Powerups()
{
}

Powerups::~Powerups()
{
}

int Powerups::GetPowerupID()
{
	return powerUpID;
}

void Powerups::newPowerup()
{
	sf::Vector2f borderpositioned = { float(rand() % int(border.getSize().x) + border.getPosition().x) + powerupSize, float(rand() % int(border.getSize().y) + border.getPosition().y - powerupSize) };
	rect.setPosition(borderpositioned);
	powerUpID = (rand() % nrOfPowerups + 1);
	switch (powerUpID)
	{
	case 1:
		rect.setTexture(&ligthning);
		break;

		//case 2: snail

		//case 3: inverted controls

		//case 4: pass through kurves

	default:
		rect.setTexture(&ligthning);
		break;
	}

}

sf::FloatRect Powerups::GetSpriteBounds()
{
	return rect.getGlobalBounds();
}

void Powerups::update(float dt)
{
}

void Powerups::draw(sf::RenderTarget & t, sf::RenderStates s) const
{
	t.draw(rect);
}
