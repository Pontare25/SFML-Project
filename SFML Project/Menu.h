#ifndef Menu_h
#define Menu_h
#include "Istate.h"

class Menu : public Istate
{
private:
	sf::Font font;
	sf::Text text;
public:
	Menu();
	~Menu();
	states Update(float deltaTime);
	void draw() // (sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif // !Menu_h
