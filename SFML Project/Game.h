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
	int result;
	float width = 800.0, height = 600.0;
	Player* playerArr;
public:
	Game(int nrOfPlayers);
	~Game();
	void AddPlayer(std::string& name, sf::Keyboard::Key rightKey, sf::Keyboard::Key leftKey,sf::Color playerColor);
	int GetNrOfPlayers()const;
	bool GameEnded();
	void ExpandPlayerArr();
	float GetWidth()const;
	float GetHeight()const;



};
#endif // !Game_h
