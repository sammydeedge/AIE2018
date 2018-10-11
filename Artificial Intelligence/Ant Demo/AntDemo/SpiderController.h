#pragma once
#include "AIController.h"
#include "Agent.h"
#include <list>

class SpiderController : public AIController
{
public:
	SpiderController(class Agent* user, class aie::Application* owningApp) : AIController(user, owningApp) {}

	virtual void update(float deltaTime) override;

	Vector2 getTargetLocation();

private:
	std::list<Vector2> m_path;
};