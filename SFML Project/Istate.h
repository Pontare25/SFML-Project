#ifndef Istate_h
#define Istate_h
#include <SFML/Graphics.hpp>

enum class States
{
	NO_CHANGE = 0,
	GAME = 1,
	MENU = 2
};

class Istate : public sf::Drawable
{
private:
	//Behövs något på Private?

public:
	virtual ~Istate() {};

	virtual States Update(float dt) = 0;
};

#endif