#pragma once

#include "Application.h"
#include "Renderer2D.h"

class Maths_for_GamesApp : public aie::Application {
public:

	Maths_for_GamesApp();
	virtual ~Maths_for_GamesApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
};