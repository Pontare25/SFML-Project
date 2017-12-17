#include "Menu.h"

Menu::Menu()
{
	font.loadFromFile("arial.ttf");
	title.setFont(font);
	title.setCharacterSize(40);
	title.setString("This is the menu. Press enter to start game.");
	title.setPosition({ 20, 220 });
}

Menu::~Menu()
{
}

States Menu::Update(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return))
		return States::GAME;
	return States::NO_CHANGE;
}

void Menu::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(title);
}