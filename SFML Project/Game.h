#ifndef Game_h
#define Game_h
#include "Player.h"
//#include "Dot.h"
#include <SFML/Graphics.hpp>
#include <string>

class Game: public sf::Drawable
{
private:
	int roundCount;
	int playerCap;
	int playerCount;

	void draw(sf::RenderTarget& t, sf::RenderStates s) const;

	Player** playerArr;
	sf::Text title;
	sf::Text pressSpace;
	sf::Font font;
	sf::Text roundText;
	sf::Text playerText;

	bool pausing;


public:
	Game();
	~Game();
	float PI = 3.1456;
	//States Update();
	
	
	void AddPlayer(std::string& name, sf::Keyboard::Key rightKey, sf::Keyboard::Key leftKey,sf::Color playerColor);
	int GetNrOfPlayers()const;
	bool RoundEnded() const;
	void ExpandPlayerArr();
	void NewRound();
	int WinnerIndex();
	bool PausSegment();
	bool kurveCollision();

	std::string GetAllPlayerInfo();
	void Update(float dt);
	

};
#endif // !Game_h
