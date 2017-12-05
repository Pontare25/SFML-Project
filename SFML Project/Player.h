#ifndef Player_h
#define Player_h
#include <string>
#include "Dot.h"
#include <SFML\Graphics.hpp>


class Player
{
private:
	//int playerId //nödvändig??
	std::string name;
	int score;
	sf::Color playerColor;
	bool alive;

	sf::Keyboard::Key rightKey;
	sf::Keyboard::Key leftKey;
	Dot playerDot;

public:
	Player(const std::string& name, sf::Keyboard::Key rightKey, sf::Keyboard::Key leftKey, sf::Color playerColor);

	~Player();

	void update(float dt, sf::Vector2f distance);

	bool IsAlive();
	void Kill();

	sf::Keyboard:: Key GetRightKey()const;
	sf::Keyboard::Key GetLeftKey()const;
	std::string GetName() const;
	sf::Color GetPlayerColor();
	int GetScore() const;
	std::string ToString() const;

};

#endif // !Player_h
