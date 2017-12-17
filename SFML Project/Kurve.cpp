#include "Kurve.h"

void Kurve::draw(sf::RenderTarget & t, sf::RenderStates s) const
{
	t.draw(vArray);
}

Kurve::Kurve(sf::Color playerColor, float dotSize, sf::Vector2f originPoint, sf::Vector2f direction)
{
	this->playerColor = playerColor;
	this->size = dotSize;
	this->direction = direction;
	sf::Vertex v;
	v.color = playerColor;
	v.position =  originPoint;
	vArray.append(v);
	v.position = originPoint;
	vArray.append(v);
	vArray.setPrimitiveType(sf::PrimitiveType::LinesStrip);
}

Kurve::Kurve() 
{
}

Kurve::~Kurve()
{ 
}

float Kurve::VectorLength(sf::Vector2f v)
{
	return sqrt(v.x*v.x + v.y*v.y); //Pytaghoras sats för längden av vektorn
}

void Kurve::SetstartPoint(sf::Vector2f startPoint)
{
	vArray.clear();
	sf::Vertex v;
	v.color = playerColor;
	v.position = startPoint;
	vArray.append(v);
	v.position = startPoint;
	vArray.append(v);
}

sf::VertexArray Kurve::GetKurveArray()
{
	return vArray;
}

void Kurve::Update(float dt, sf::Vector2f position)
{
	//if (vArray.getVertexCount() < 5000)
	//{
		if (VectorLength(vArray[vArray.getVertexCount() - 1].position - vArray[vArray.getVertexCount() - 2].position) > 5.0f)
		{
			sf::Vertex newVertex = vArray[vArray.getVertexCount() - 1];
			vArray.append(newVertex);
		}
	//}
	
	vArray[vArray.getVertexCount() - 1].position = position;
}

void Kurve::draw()
{
}


