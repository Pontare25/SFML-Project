#pragma once
#include "SFML\Graphics.hpp"

class Squiggly :public sf::Drawable
{
private:
	sf::VertexArray vertexArray;
	sf::Vector2f direction;

public:
	Squiggly();
	~Squiggly();
	
	void Update(float dt);

	void draw(sf::RenderTarget & target, sf::RenderStates states) const;
	
};