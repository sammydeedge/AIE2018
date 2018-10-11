#include "Sprite.h"
#include "Texture.h"
#include "Renderer2D.h"
#include "Application.h"


sprite::sprite(aie::Texture* image, float x, float y, float speed)
{
	m_image = image;
	m_x = x;
	m_y = y;
	m_speed = speed;

}

//Overloaded operator checks if two sprites have collided
bool sprite::collisionCheck (sprite & other)
{
	float myWidth = m_image->getWidth();                //Intialising values of the width and height of sprites
	float theirWidth = other.m_image->getWidth();
	float myHeight = m_image->getHeight();
	float theirHeight = other.m_image->getHeight();

	float myMinX = m_x - myWidth * 0.25f;                //Getting minimum and maxmimum values of sprites position
	float myMaxX = m_x + myWidth * 0.25f;
	float theirMinX = other.m_x - myWidth * 0.25f;
	float theirMaxX = other.m_x + myWidth * 0.25f;

	float myMinY = m_y - myWidth * 0.25f;
	float myMaxY = m_y + myWidth * 0.25f;
	float theirMinY = other.m_y - myWidth * 0.25f;
	float theirMaxY = other.m_y + myWidth * 0.25f;

	/*if ones max is smaller than another's min, they don't overlap in that axis, so if they don't overlap in either axis, they
	aren't touching. We reverse this with the ! at the front*/
	
	return !((myMaxX < theirMinX) || (theirMaxX < myMinX) || (myMaxY < theirMinY) || (theirMaxY < myMinY));
}