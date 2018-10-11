#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <vector>
#include "Ant.h"
#include "Food.h"
#include "Nest.h"
#include "Spider.h"

class AntDemoApp : public aie::Application {
public:

	AntDemoApp();
	virtual ~AntDemoApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	void updateFood();
	Food* findClosestFoodTo(const Vector2& location) const;

	Nest* getNestOfTeam(Ant::Team team);

	const Pathfinder* getPathfinder() const { return &m_pathfinder; }

	void makeWeb();

	void spawnNewAnt(Ant::Team colour);

	spider* getSpider();

protected:

	aie::Renderer2D*				m_2dRenderer;
	aie::Font*						m_font;

	aie::Texture*					m_greenAntTexture;
	aie::Texture*					m_violAntTexture;
	aie::Texture*					m_greenNestTexture;
	aie::Texture*					m_violNestTexture;
	aie::Texture*					m_foodTexture;
	aie::Texture*					m_spiderTexture;
	aie::Texture*					m_spiderWebTexture;

	spider*							m_spider			= nullptr;
	
	std::vector<Ant*>				m_ants;
	std::vector<Food*>				m_food;
	std::vector<Nest*>				m_nests;

	Vector2							greenNestPos;
	Vector2							violNestPos;

	float							m_foodTimer					= 0.0f;
	float							m_foodSpawnTime				= 1.5f;
	float							m_spiderTimer				= 0.0f;
	float							m_spiderSpawnTime			= 15.0f;
	void							spawnFood();

	Pathfinder						m_pathfinder;
	bool							m_renderPathfinder			= false;
	Pathfinder::node const*			m_selectedPathfindNode		= nullptr;

	std::vector<Pathfinder::node*>	m_web;

	bool							m_removeWeb					= false;
};