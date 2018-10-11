#include "Enemy.h"

void enemy::updateMovement(float oldspeed, float newspeed)
{
	m_updateX = (m_updateX / oldspeed) * newspeed;
	m_updateY = (m_updateX / oldspeed) * newspeed;

}

//Function that checks if sprite has hit the edge of screen
enemy::wall enemy::hitEdge(int screenXmax, int screenYmax)
{
	float myWidth = m_image->getWidth();			//Intialising all the sprites values
	float myHeight = m_image->getHeight();
	float myMinX = m_x - myWidth * 0.25f;
	float myMaxX = m_x + myWidth * 0.25f;
	float myMinY = m_y - myWidth * 0.25f;
	float myMaxY = m_y + myWidth * 0.25f;

	if (myMaxX >= screenXmax || myMinX <= 0) { return leftRight; }
	else if (myMaxY >= screenYmax || myMinY <= 0) { return upDown; }
	else { return Null; }
}


