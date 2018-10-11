#include "Sprite.h"

sprite::sprite()
{

}
sprite::sprite(aie::Texture* image)
{
	m_image = image;
}

sprite::sprite(scene_object::ObjID type)
{
	if (type == scene_object::P1Tank)				{ m_image = m_P1bodyTexture; }
	if (type == scene_object::P1Barrel)				{ m_image = m_P1barrelTexture; }
	if (type == scene_object::P2Tank)				{ m_image = m_P2bodyTexture; }
	if (type == scene_object::P2Barrel)				{ m_image = m_P2barrelTexture; }
	if (type == scene_object::Bullet)				{ m_image = m_bulletTexture; }

}

void sprite::onDraw(aie::Renderer2D* renderer, Matrix3 global)
{
	renderer->drawSpriteTransformed3x3(m_image, (float*)&global);
}

void sprite::onDrawOffset(aie::Renderer2D* renderer, Matrix3 global)
{
	renderer->drawSpriteTransformed3x3(m_image, (float*)&global, 0, 0, 0, 0.5f, 0.1f);
}

void sprite::onUpdate(float deltaTime)
{
	//LOL IDK
}