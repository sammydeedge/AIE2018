#pragma once
#include "AIController.h"
#include "Food.h"

class Ant;

class AntController : public AIController
{
public:
	enum states
	{
		SeekFood,
		SeekNest,
		FleeSpider
	};

	AntController(class Agent* owner, class aie::Application* appOwner) : AIController(owner, appOwner) {}

	virtual void update(float deltaTime) override;

	void run_foodSeeking();
	bool spiderNearby(float distance);

	void run_spiderFlee();

protected:
	states m_state = SeekFood;
	void run_nestSeeking();
	
};