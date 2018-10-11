#pragma once
#include "Vector2.h"

namespace aie
{
	class Texture;
	class Renderer2D;
}

class Food
{
public:
	Food(Vector2 position, aie::Texture* texture);

	void render(aie::Renderer2D*) const;

	Vector2 getPosition() const;

private:

	Vector2			m_position;
	aie::Texture*	m_texture;

};