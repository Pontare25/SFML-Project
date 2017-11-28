#ifndef Player_h
#define Player_h
#include <string>
#include <SFML\Graphics.hpp>
#include "Kurve.h"
#include "Line.h"

class Player
{
private:
	//int playerId //nödvändig??
	std::string name;
	int score;
	sf::Color playerColor;
	bool alive;

	enum eDirection {STOP=0, LEFT, RIGHT};
	eDirection direction;

	sf::Keyboard:: Key rightKey;
	sf::Keyboard::Key leftKey;


	std::string hej = "hej";
	


public:
	Player(const std::string name, sf::Keyboard::Key rightKey, sf::Keyboard::Key leftKey, sf::Color playerColor);
	Player();
	~Player();

	bool IsAlive();
	void Dead();

	sf::Keyboard:: Key GetRightKey()const;
	sf::Keyboard::Key GetLeftKey()const;
	std::string GetName() const;
	int GetScore() const;
	std::string ToString() const;

};

#endif // !Player_h
