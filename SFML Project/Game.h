#ifndef Game_h
#define Game_h
#include "Player.h"
//#include "Dot.h"
#include <SFML/Graphics.hpp>

class Game: public sf::Drawable
{
private:
	int roundCount;
	int playerCap;
	int playerCount;

	void draw(sf::RenderTarget& t, sf::RenderStates s) const;

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
	void NewRound();
	int WinnerIndex();
	void Update(float dt);
	bool checkCollision();

};
#endif // !Game_h
