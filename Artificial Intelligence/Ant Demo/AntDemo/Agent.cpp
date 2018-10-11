#include "Agent.h"
#include "Renderer2D.h"
#include "AntController.h"
#include "Vector3.h"
#include "Matrix4.h"

//Agent set up with texture and empy transform and velocity
Agent::Agent(aie::Texture* texture)
{
	m_texture = texture;
	m_transform = Matrix4();
	m_velocity = Vector2(0,0);
}

//Sets agent position based on vector 2 passed in
void Agent::setPosition(const Vector2& position)
{
	m_transform.setPosition(position.x, position.y, 0);
}

//Sets agent velocity based on vector 2 passed in
void Agent::setVelocity(const Vector2& velocity)
{
	m_velocity = velocity;
}

//Returns agent location as a vector of 2 points
Vector2 Agent::getPosition() const
{
	Vector2 result = Vector2(m_transform.transform[0], m_transform.transform[1]);
	return result;
}

//Returns agent velocity as a vector of 2 points
Vector2 Agent::getVelocity() const
{
	return m_velocity;
}

//Returns agent speed as a float
float Agent::getMaxSpeed() const
{
	return m_maxSpeed;
}

//Calls update functions on whatever it is called on
void Agent::update(float deltaTime)
{
	if (m_controller)	{ m_controller->update(deltaTime); }

	Vector2 XYmov = m_velocity * deltaTime;
	Vector4 movement = Vector4(XYmov, 0.0f, 0.0f);
	m_transform.transform = m_transform.transform + movement;
	updateFacing();
}

//Renders agent
void Agent::render(aie::Renderer2D* renderer)
{
	renderer->drawSpriteTransformed4x4(m_texture, m_transform);
}

//Translates agent a certain distance over a period of deltaTime
void Agent::translate(float x, float y, float deltaTime)
{
	float trans_speed = 200 * deltaTime;
	m_transform.transform.x = m_transform.transform[0] + (x * trans_speed);
	m_transform.transform.y = m_transform.transform[1] + (y * trans_speed);
}

//Updates the direction the agent is facing
void Agent::updateFacing()
{
	Vector4 newUp = Vector4(m_velocity, 0.0f, 0.0f);
	if (newUp.magnitude() == 0.0f)
	{
		newUp = { 0,1,0, 0 };
	}
	newUp.normalise();

	m_transform.up = newUp;
	m_transform.right = Vector4(newUp.cross(m_transform.backward));
}
