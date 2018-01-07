#include "Powerups.h"

Powerups::Powerups()
{
	nrOfPowerups = 2;
	powerupSize = 30.0f;
	if (!ligthning.loadFromFile("Ligthning.png"))
	{
		ligthning.create(powerupSize, powerupSize);
		//Texture not loaded
	}
	if (!slow.loadFromFile("Slow.png"))
	{
		slow.create(powerupSize, powerupSize);
	}
	if (!Inverted.loadFromFile("Inverted.png"))
	{
		Inverted.create(powerupSize, powerupSize);
	}
	

	//ligthningSprite.setTexture(ligthning);
	rect.setSize({ powerupSize, powerupSize });

}

Powerups::~Powerups()
{
}

void Powerups::SetBorder(sf::RectangleShape & border)
{
	this->border = border;
	newPowerup();
}

int Powerups::GetPowerupID()
{
	return powerUpID;
}

void Powerups::newPowerup()
{
	sf::Vector2f borderpositioned = { float(rand() % int(border.getSize().x)/2 + border.getPosition().x) /*+ powerupSize*/, float(rand() % int(border.getSize().y)/2 + border.getPosition().y /*- powerupSize*/) };
	rect.setPosition(borderpositioned);
	powerUpID = ((rand() % nrOfPowerups)+1);
	switch (powerUpID)
	{
		case 1: //ligthning
		rect.setTexture(&ligthning);
		break;

		case 2: //Slow
			rect.setTexture(&slow);
			break;

		//case 3: //inverted controls
		//	rect.setTexture(&Inverted);
		//	break;

		//case 4: pass through kurves

		//case 5: spawn ball

		//case 6: removeKurves

	default:
		powerUpID = 1;
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
