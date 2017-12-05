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

	Player** playerArr;

public:
	Game();
	~Game();
	float PI = 3.1456;
	//States Update();
	
	void AddPlayer(std::string& name, sf::Keyboard::Key rightKey, sf::Keyboard::Key leftKey,sf::Color playerColor);
	int GetNrOfPlayers()const;
	bool RoundEnded();
	void ExpandPlayerArr();

	void Update(float dt);
	void Draw()const;

};
#endif // !Game_h
