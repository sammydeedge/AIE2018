#include "Food.h"
#include "Renderer2D.h"

//Makes food at a given position and with a given texture
Food::Food(Vector2 position, aie::Texture* texture)
{
	m_position = position;
	m_texture = texture;
}

//Renders food item
void Food::render(aie::Renderer2D* renderer) const
{
	renderer->drawSprite(m_texture, m_position.x, m_position.y, 32, 32);
}

//Returns position of food as a Vector 2
Vector2 Food::getPosition() const
{
	return m_position;
}