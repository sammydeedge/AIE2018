#include "Sprite.h"

sprite::sprite()
{

}
sprite::sprite(aie::Texture* image, float Xpos, float Ypos, float rotation_degrees)
{
	m_image = image;
	setPosition(Xpos, Ypos);
	float rotate_radians = convertDegtoRad(rotation_degrees);
	setRotate(rotate_radians);
}

void sprite::onDraw(aie::Renderer2D* renderer)
{
	renderer->drawSpriteTransformed3x3(m_image, (float*)&m_global_transMatrix);
}

void sprite::onDrawOffset(aie::Renderer2D* renderer)
{
	renderer->drawSpriteTransformed3x3(m_image, (float*)&m_global_transMatrix, 0, 0, 0, 0.5f, 0.1f);
}

void sprite::onUpdate(float deltaTime)
{
	//LOL IDK
}