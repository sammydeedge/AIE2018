#pragma once
#include "Vector2.h"
#include "Ant.h"

namespace aie
{
	class Texture;
	class Renderer2D;
}

class Nest
{
public:
	Nest(Vector2 position, Ant::Team colour, aie::Texture* texture);

	void render(aie::Renderer2D*) const;

	Vector2 getPosition();

	void AddFoodtoStockpile();

	int CheckFoodInventory();

	Ant::Team getTeam();


private:

	Vector2		m_position;
	aie::Texture*	m_texture;
	Ant::Team		m_teamcolour;

	int m_foodStockpileCounter = 0;


};
