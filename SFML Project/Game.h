#ifndef Game_h
#define Game_h
#include "Player.h"
#include <SFML/Graphics.hpp>
#include "Istate.h"
class Game
{
private:
	int roundCount;
	std::string name;
	int playerCap = 2;
	int playerCount = 0;
	int result;

	Player* playerArr;
	//sf::CircleShape dot;

public:
	Game();
	~Game();
	
	States Update();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	void AddPlayer(std::string& name, sf::Keyboard::Key rightKey, sf::Keyboard::Key leftKey,sf::Color playerColor);
	int GetNrOfPlayers()const;
	bool GameEnded();
	void ExpandPlayerArr();



};
#endif // !Game_h
