#pragma once
#include "Sphere.h"
#include "Matrix4.h"
#include "Pathfinder.h"

class AntController;
class Pathfinder;

namespace aie
{
	class Texture;
	class Renderer2D;
}
class Agent
{
public:
	Agent(aie::Texture* texture);

	void setPosition(const Vector2& position);
	void setVelocity(const Vector2& velocity);
	void setController(class AIController* controller) { m_controller = controller; }
	

	Vector2 getPosition() const;
	Vector2 getVelocity() const;
	float getMaxSpeed() const;

	void update(float deltaTime);
	void render(aie::Renderer2D* renderer);

	void translate(float x, float y, float deltaTime);
	void updateTransform();



protected:
	aie::Texture*				m_texture;
	class AIController* m_controller = nullptr;
	


	void updateFacing();

	Matrix4			m_transform;
	Vector2			m_velocity;

	float			m_maxSpeed = 150.0f;

	union
	{
		sphere*					sphere;
	} m_collider;
};
