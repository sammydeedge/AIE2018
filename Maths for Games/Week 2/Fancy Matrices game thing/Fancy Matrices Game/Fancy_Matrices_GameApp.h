#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "scene_object.h"
#include "Sprite.h"
#include "player_data.h"

class Fancy_Matrices_GameApp : public aie::Application {
public:

	Fancy_Matrices_GameApp();
	virtual ~Fancy_Matrices_GameApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	void showPlayerstats();
	void clearBullets();

protected:

	aie::Renderer2D*			m_2dRenderer;
	aie::Font*					m_font;
	aie::Font*					m_titlefont;

	scene_object*				m_P1body;
	scene_object*				m_P1barrel;
	scene_object*				m_P2body;
	scene_object*				m_P2barrel;
	scene_object*				m_bullet			= nullptr;
	std::vector<scene_object*>	m_bulletVector;

	player_data*				m_P1data;
	player_data*				m_P2data;
	struct m_walls
	{
		plane*					left, right, up, down;
	};
};