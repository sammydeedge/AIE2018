#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Enemy.h"
#include <vector>


class Week1_Day3App : public aie::Application {
public:

	Week1_Day3App();
	virtual ~Week1_Day3App();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	void printScore(int score);
	/*bool gameOver();*/
	void crashed();

	void EnemySpawn();
	int    livesLeft = 5;
	std::vector<enemy*>    m_enemyList;			//list of all enemies



protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	aie::Texture*		m_playertexture;		//sprite textures
	aie::Texture*		m_playerinvtexture;
	aie::Texture*		m_goldtexture;
	class sprite*		m_player;				//sprite objects
	class sprite*		m_gold;
};