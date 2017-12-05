#ifndef Game_h
#define Game_h
#include "Player.h"
#include <SFML/Graphics.hpp>

class Game
{
private:
	int roundCount;
	std::string name;
	int playerCap;
	int playerCount;

	Player* playerArr;

public:
	Game();
	~Game();
	
	//States Update();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	void AddPlayer(std::string& name, sf::Keyboard::Key rightKey, sf::Keyboard::Key leftKey,sf::Color playerColor);
	int GetNrOfPlayers()const;
	bool GameEnded();
	void ExpandPlayerArr();



};
#endif // !Game_h
