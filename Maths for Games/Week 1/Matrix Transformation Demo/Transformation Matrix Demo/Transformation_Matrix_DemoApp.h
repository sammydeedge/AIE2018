#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "scene_object.h"
#include "Sprite.h"

class Transformation_Matrix_DemoApp : public aie::Application {
public:

	Transformation_Matrix_DemoApp();
	virtual ~Transformation_Matrix_DemoApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();
	
protected:

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	aie::Texture*		m_tankbodyTexture;
	aie::Texture*		m_tankbarrelTexture;
	sprite*				m_tankbody;
	sprite*				m_tankbarrel;
};