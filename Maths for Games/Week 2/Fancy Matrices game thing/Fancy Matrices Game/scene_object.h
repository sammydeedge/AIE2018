#pragma once
#include "Renderer2D.h"
#include "Matrix3.h"
#include "Vector3.h"
#include "Vector2.h"
#include "AABB.h"
#include "Plane.h"
#include "Sphere.h"
#include <vector>
#include <cassert>

class sprite;

class scene_object
{
public:
	enum ObjID
	{
		P1Tank,
		P1Barrel,
		P2Tank,
		P2Barrel,
		Bullet
	};
	scene_object();
	scene_object(scene_object::ObjID type, float Xpos, float Ypos, float rotation);
	scene_object(scene_object::ObjID type, Matrix3 location);
	~scene_object();
	float convertDegtoRad(float degrees);

	scene_object* getParent() const;
	size_t childCount() const;
	scene_object* getChild(unsigned int index) const;

	void addChild(scene_object* child);
	void removeChild(scene_object* child);


	void update(float deltaTime);
	void draw(aie::Renderer2D* renderer);
	virtual void onUpdate(float deltaTime);
	virtual void onDraw(aie::Renderer2D* renderer, Matrix3 global);
	virtual void onDrawOffset(aie::Renderer2D* renderer, Matrix3 global);

	const Matrix3& getLocalTransform() const;
	Matrix3& getLocalTransform();
	Vector3 getLocalTransformColumnVector(int column) const;
	const Matrix3& getGlobalTransform() const;
	Matrix3& getGlobalTransform();

	void updateTransform();

	void setPosition(float x, float y);
	void setRotate(float degrees);
	void setScale(float width, float height);
	void translate(float x, float y, float deltaTime);
	void rotate(float degrees);
	void scale(float x, float y);

	union
	{
		AABB*					AABB;
		sphere*					sphere;
	} m_collider;
protected:
	sprite*						m_sprite;
	scene_object*				m_parent				= nullptr;
	

	std::vector<scene_object*>	m_children;

	


	Matrix3						m_global_transMatrix;
	Matrix3						m_local_transMatrix;
	Matrix3						m_child_offset			= Matrix3(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 8.5f, 0.0f);
};