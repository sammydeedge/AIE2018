#include "AIController.h"
#include "Agent.h"

//Seeks to a certain location
void AIController::seek(Vector2& targetPos)
{
	Vector2 myPos		= m_user->getPosition();					//Get my position
	Vector2 toTarget	= Vector2(targetPos - myPos);
	toTarget.normalise();											//Create a normalised vector from my position to the target

	float mySpeed = m_user->getMaxSpeed();							//Make a variable for movement to that vector, multiplied by my maxspeed
	m_user->setVelocity(toTarget * mySpeed);						//And set that as the user's velocity

}

void AIController::flee(Vector2& targetPos)
{
	Vector2 myPos = m_user->getPosition();							//Get my position
	Vector2 toTarget = Vector2(targetPos - myPos);
	toTarget.normalise();											//Create a normalised vector from my position to the target

	float mySpeed = m_user->getMaxSpeed();								//Make a variable for movement to that vector, multiplied by my maxspeed
	m_user->setVelocity(toTarget * -mySpeed);						//And set that as the user's velocity, with a negative speed so it moves away from target
}

void AIController::wander(Vector2& targetPos)
{
	float sphere_size = 10.0f;											//Set sphere_size
	Vector2 target = Vector2(rand() % 10, rand() % 10);					//And a random direction
	target = target.normalised() * sphere_size;							//Put a target point in that direction on a circle with a radius of sphere_size
																	
	auto facing = m_user->getVelocity() * m_user->getMaxSpeed();		//Create a vector of that direction with max speed
	float sphere_displace = 20.0f;										//Displace the sphere a distance
	m_user->setVelocity(Vector2(facing.x, facing.y + sphere_displace));						//And set the velocity to the displacement plus the facing vector
}