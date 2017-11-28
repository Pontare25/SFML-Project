#ifndef Game_h
#define Game_h
#include "Player.h"
#include <SFML/Graphics.hpp>

class Game
{
private:
	
	std::string name;
	int playerCap = 2;
	int playerCount = 0;
	Player* playerArr = new Player[playerCap];
	int result;
	float width = 900.0;
	float height = 900.0;

public:
	Game(int nrOfPlayers);
	~Game();
	void AddPlayer(std::string& name, sf::Keyboard::Key rightKey, sf::Keyboard::Key leftKey,sf::Color playerColor);
	int GetNrOfPlayers()const;
	bool GameEnded();
	void ExpandPlayerArr();



};
#endif // !Game_h
