#pragma once
#include "Sprite.h"
#include "Texture.h"
#include <random>
#include <ctime>

class enemy : public sprite
{
public:

	enemy() : sprite(m_enemytexture, 300.0f, 400.0f, 5)
	{
		srand((unsigned int)time(nullptr));
		float randRotate = rand() % 360;
		m_rotation = randRotate;
	}

	enum wall
	{
		leftRight,
		upDown,
		Null
	};

	float m_updateX, m_updateY;

	void updateMovement(float oldspeed, float newspeed);

	wall hitEdge(int screenXmax, int screenYmax);
	void setXYUpdate();

protected:
	int					m_enemyCount = 0;
	aie::Texture*		m_enemytexture = new aie::Texture("../bin/textures/enemy.png");
	float				m_rotation;
};