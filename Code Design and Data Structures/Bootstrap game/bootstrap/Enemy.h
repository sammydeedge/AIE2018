#pragma once
#include "Sprite.h"
#include "Application.h"
#include "Renderer2D.h"
<<<<<<< HEAD
#include <random>
#include <ctime>

=======
>>>>>>> 743611b5c5a55a637547fe8cd86b648d4b645c77

class enemy : public sprite
{
public:
<<<<<<< HEAD
	enemy() : sprite(new aie::Texture("../bin/textures/enemy.png"), 640.0f, 360.0f, 4.5f)
	{
		srand((unsigned int)time(nullptr));
		m_rotation = (rand() % 360);

		m_upX_coeff = cos(m_rotation);
		m_upY_coeff = sin(m_rotation);

		m_updateX = m_upX_coeff * m_speed;
		m_updateY = m_upY_coeff * m_speed;

	}

	//Use to alter and return the m_speed value
	void setSpeed(float speed);
	float getSpeed();

	//Returns the coefficients. Essentially determines angle via X&Y movement.
	float getXcoeff();
	float getYcoeff();

	//Reverses the X or Y Movement to allow sprites to "reflect" off edges
	void reflectX();
	void reflectY();
	
	//hitEdge returns an enum value, leftRight for hitting the left or right edge, upDown for the top or bottom edge, Null when no collision occurs
	enum wall {
		leftRight,
		upDown,
		Null
	};
	wall hitEdge(int screenXmax, int screenYmax);
=======
	void Week1_Day3App::EnemySpawn();

>>>>>>> 743611b5c5a55a637547fe8cd86b648d4b645c77


private:
	float m_time = 0;
<<<<<<< HEAD
	float m_rotation, m_upX_coeff, m_upY_coeff, m_updateX, m_updateY;
	

=======
>>>>>>> 743611b5c5a55a637547fe8cd86b648d4b645c77

};