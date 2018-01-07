#ifndef Game_h
#define Game_h
#include "Player.h"
#include "Powerups.h"
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
	sf::Font font2;
	sf::Font font3;
	sf::Text roundText;
	sf::Text playerText;
	//sf::Text player1;
	//sf::Text player2;
	//sf::Text player3;
	//sf::Text player4;


	sf::RectangleShape border;
	Powerups pow;
	//sf::Clock powerClock;
	float powerTime;
	float playerPowerTime;
	bool powerupExists;
	bool playerHasPowerup;
	int powerPlayer;

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
	std::string WinnerString();
	int GetRound();
	bool PausSegment();
	void otherPlayerCollision();

	std::string GetAllPlayerInfo() const;
	void Update(float dt);
	

};
#endif // !Game_h
