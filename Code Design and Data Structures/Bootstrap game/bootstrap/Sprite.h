#pragma once
#include "Texture.h"

class sprite
{
public:
<<<<<<< HEAD
	
	aie::Texture* m_image;
	float m_x, m_y, m_rotation, m_speed;
	

	
	sprite(aie::Texture* image, float x, float y, float speed);
	bool collisionCheck (sprite & other);
	bool invulnerable = false;
=======
	aie::Texture* m_image;
	float m_x, m_y, m_rotation, m_speed;

	
	sprite(aie::Texture* image, float x, float y, float speed);
	bool operator == (sprite & other);
>>>>>>> 743611b5c5a55a637547fe8cd86b648d4b645c77
	//void setRandomNewLocation();

protected:
	int m_time = 0;
<<<<<<< HEAD

=======
>>>>>>> 743611b5c5a55a637547fe8cd86b648d4b645c77
};