#ifndef State_h
#define State_h
#include "SFML\Graphics.hpp"

enum class States
{
	NO_CHANGE = 0,
	GAME = 1,
	MENU = 2
};


class State: public sf::Drawable
{
public:
	virtual ~State() {};

	virtual States Update(float dt) = 0;
};

#endif
