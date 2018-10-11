#pragma once
#include "Agent.h"
#include "Pathfinder.h"
#include "SpiderController.h"
#include <ctime>

namespace aie
{
	class Application;
}

class spider : public Agent
{
public:


	spider(class aie::Application* owner, aie::Texture* texture) : Agent(texture)
	{
		setController(new SpiderController(this, owner));
	}

	void debugrender(aie::Renderer2D* renderer);

protected:
	Vector2								m_position;
	std::vector<Pathfinder::node*>		web;
	std::list<Vector2>					m_path;
	Pathfinder							m_pathfinder;
};