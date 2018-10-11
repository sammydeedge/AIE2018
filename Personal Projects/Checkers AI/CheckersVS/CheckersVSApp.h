#pragma once

#include "Application.h"
#include "Renderer2D.h"

class CheckersVSApp : public aie::Application {
public:

	CheckersVSApp();
	virtual ~CheckersVSApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	aie::Texture*		m_boardTexture;
	aie::Texture*		m_orangepieceTexture;
	aie::Texture*		m_orangekingTexture;
	aie::Texture*		m_violetpieceTexture;
	aie::Texture*		m_violetkingTexture;


};