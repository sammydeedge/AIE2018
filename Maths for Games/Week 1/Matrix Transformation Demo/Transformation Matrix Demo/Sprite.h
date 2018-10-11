#pragma once
#include "scene_object.h"
#include "Renderer2D.h"

class sprite : public scene_object
{
public:

	sprite();
	sprite(aie::Texture* image, float Xpos, float Ypos, float rotation);

	void onDraw(aie::Renderer2D* renderer);
	void onDrawOffset(aie::Renderer2D* renderer);
	void onUpdate(float deltaTime);

protected:
	aie::Texture* m_image;


};