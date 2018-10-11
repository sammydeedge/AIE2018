#pragma once
#include "Vector2.h"
#include "Pathfinder.h"

namespace aie { class Application; };

class AIController
{
public:

	AIController(class Agent* user, class aie::Application* appOwner) : m_user(user), m_OwningApp(appOwner) {}
	AIController() = delete;

	virtual void update(float deltaTime) = 0;

	void seek(Vector2& position);
	void flee(Vector2& position);
	void wander(Vector2& position);
protected:
	class Agent*				m_user		= nullptr;
	class aie::Application*		m_OwningApp = nullptr;

	
};