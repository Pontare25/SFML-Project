#ifndef Menu_h
#define Menu_h
#include "State.h"

class Menu : public State
{
private:
	sf::Font font;
	sf::Text title;

public:
	Menu();
	~Menu();
	States Update(float dt);
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;


};

#endif // !Menu_h
