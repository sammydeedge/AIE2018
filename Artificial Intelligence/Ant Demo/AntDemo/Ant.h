#pragma once
#include "Agent.h"
#include "AntController.h"

namespace aie
{
	class Application;
}

class Ant : public Agent
{
public:
	enum Team
	{
		Green,
		Violet
	};

	Ant(class aie::Application* owner, Team team, aie::Texture* texture) : Agent(texture)
	{
		m_team = team;
		setController(new AntController(this, owner));
	}

	Team getTeam() const { return m_team; }

	void holdFood() { m_holdsFood = true; }
	void dropFood() { m_holdsFood = false; }

	bool hasFood() { return m_holdsFood; }
	
private:
	Team	m_team;
	bool	m_holdsFood			= false;
	int		m_foodpiecesCarried = 0;
}; 
