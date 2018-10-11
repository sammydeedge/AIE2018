#pragma once
#include "scene_object.h"
#include "Renderer2D.h"
#include "Texture.h"

class sprite
{
public:

	sprite();
	sprite(aie::Texture* image);
	sprite(scene_object::ObjID type);
	

	void onDraw(aie::Renderer2D* renderer, Matrix3 global);
	void onDrawOffset(aie::Renderer2D* renderer, Matrix3 global);
	void onUpdate(float deltaTime);

protected:
	aie::Texture*			m_image;
	aie::Texture*			m_P1bodyTexture			= new aie::Texture("../bin/textures/P1tank.png");
	aie::Texture*			m_P1barrelTexture		= new aie::Texture("../bin/textures/P1barrel.png");
	aie::Texture*			m_P2bodyTexture			= new aie::Texture("../bin/textures/P2tank.png");
	aie::Texture*			m_P2barrelTexture		= new aie::Texture("../bin/textures/P2barrel.png");
	aie::Texture*			m_bulletTexture			= new aie::Texture("../bin/textures/grenade.png");

	



};
