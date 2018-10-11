#include "Nest.h"
#include "Renderer2D.h"

//Sets nest at a given position, for a given team, with a given texture
Nest::Nest(Vector2 position,Ant::Team colour, aie::Texture* texture)
{
	m_position		= position;
	m_texture		= texture;
	m_teamcolour	= colour;
}

//Renders the nest
void Nest::render(aie::Renderer2D* renderer) const
{
	renderer->drawSprite(m_texture, m_position.x, m_position.y, 70, 70);
}

//Returns position as a Vector 2
Vector2 Nest::getPosition()
{
	return m_position;
}

//Increments food stockpile value
void Nest::AddFoodtoStockpile()
{
	m_foodStockpileCounter++;
}

//Returns number of food items in inventory
int Nest::CheckFoodInventory()
{
	return m_foodStockpileCounter;
}

//Returns the nest's team 
Ant::Team Nest::getTeam()
{
	return m_teamcolour;
}