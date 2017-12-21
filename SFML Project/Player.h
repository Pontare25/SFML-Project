#ifndef Player_h
#define Player_h
#include <string>
#include "Dot.h"
#include <SFML\Graphics.hpp>


class Player : public sf::Drawable
{
private: 
	std::string name;
	int score;
	sf::Color playerColor;
	bool alive;
	void draw(sf::RenderTarget& t, sf::RenderStates s) const;
	
	Dot playerDot;
	sf::RectangleShape bounds;
	sf::RectangleShape playerDotBounds;

public:
	Player(const std::string& name, sf::Keyboard::Key rightKey, sf::Keyboard::Key leftKey, sf::Color playerColor, sf::RectangleShape& border);

	~Player();

	void update(float dt);

	sf::RectangleShape border;
	bool IsAlive();
	void Kill(); //Called upon when a player hits a wall or kurve
	void Resurrect(); //Resets alive when a ew round begins (also possibly for potential powerup like extra life)
	void AddScore();

	std::string GetName() const;
	sf::Color GetPlayerColor();
	int GetScore() const;
	std::string ToString() const;
	sf::VertexArray GetKurveArr();
	
	Dot GetPlayerDot();

	bool checkCollision();

	bool otherCollision(const sf::FloatRect & box);

	void Normalize();

};

#endif // !Player_h
