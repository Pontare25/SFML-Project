#ifndef Game_h
#define Game_h
#include "Player.h"
//#include "Dot.h"
#include <SFML/Graphics.hpp>

class Game
{
private:
	int roundCount;
	int playerCap;
	int playerCount;

	Player* playerArr;

public:
	Game();
	~Game();
	
	//States Update();
	
	void AddPlayer(std::string& name, sf::Keyboard::Key rightKey, sf::Keyboard::Key leftKey,sf::Color playerColor);
	int GetNrOfPlayers()const;
	bool RoundEnded();
	void ExpandPlayerArr();

	void Update();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};
#endif // !Game_h
