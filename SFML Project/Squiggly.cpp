#include "Squiggly.h"

//Linjär algebra. Räknar ut längden av en vektor. (Vi använder detta för att få reda på avståndet mellan två punkter)
static float VecLen(sf::Vector2f v)
{
	return sqrt(v.x * v.x + v.y*v.y);
}


Squiggly::Squiggly()
{
	//vertexArray är en medlemsvertexArrayriabel i Squiggly av typen sf::VertexArray
	//Här sätter vi den primitivertexArray topologin till att vertexArrayra en linestrip
	//Det betyder att en linje kommer att dras mellan vertexArrayrje Vertex i arrayen när vi ritar ut den.
	//Använder man lines så dras en linje mellan vertexArrayrje par av punkter.
	//LineStrip: *-----*------*------*
	//Lines:	 *-----*      *------*
	vertexArray.setPrimitiveType(sf::PrimitiveType::LineStrip);
	//Lägg till två "startpunkter" i vår squiggly
	sf::Vertex v;
	v.position = { 300.0f, 300.0f };
	v.color = sf::Color::Yellow;
	vertexArray.append(v);
	v.position = { 305.0f, 300.0f };
	vertexArray.append(v);
	
	direction = {0,0}; //Stå still i början
}

Squiggly::~Squiggly()
{
}

void Squiggly::Update(float dt)
{
	//Här rör vi oss bara längs med x, och y axelns. Inga mjuka kurvor.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		direction = { -1.0f, 0.0f };
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		direction = { 1.0f, 0.0f };
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		direction = { 0.0f, -1.0f };
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		direction = { 0.0f, 1.0f };

	//KurvertexArrayn fortsätter växa tills att den består av 50 punkter.
	if (vertexArray.getVertexCount() < 500)
	{
		//Skapa en ny punkt när vi är på ett avstånd på 5 pixlar från punkten bakom "huvudet"
		//Huvudet ligger i detta fall längst bak i arrayen, och svertexArraynsen först.
		if (VecLen(vertexArray[vertexArray.getVertexCount() - 1].position - vertexArray[vertexArray.getVertexCount() - 2].position) > 5.0f)
		{
			sf::Vertex newVertex = vertexArray[vertexArray.getVertexCount() - 1];
			vertexArray.append(newVertex);
		}
	}
	else
	{
		//Om avståndet mellan huvudet och den närmsta punkten är större än 5 pixlar så förflyttar vi alla punkter framåt. (utom huvudet)
		if (VecLen(vertexArray[vertexArray.getVertexCount() - 1].position - vertexArray[vertexArray.getVertexCount() - 2].position) > 5.0f)
		{
			for (int i = 0; i < vertexArray.getVertexCount() - 1; i++)
			{
				vertexArray[i].position = vertexArray[i + 1].position;
			}
		}
		sf::Vector2f tailMovement = vertexArray[1].position - vertexArray[0].position;
		tailMovement /= VecLen(tailMovement);
		vertexArray[0].position += tailMovement * dt * 100.0f;
	}
	//Flytta fram huvudet
	
}

void Squiggly::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(vertexArray);
}