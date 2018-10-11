#pragma once
#include "Renderer2D.h"
#include "Matrix3.h"
#include "Vector3.h"
#include <vector>
#include <cassert>

class scene_object
{
public:
	~scene_object();

	float convertDegtoRad(float degrees);

	scene_object* getParent() const;
	size_t childCount() const;
	scene_object* getChild(unsigned int index) const;

	void addChild(scene_object* child);
	void removeChild(scene_object* child);


	void update(float deltaTime);
	void draw(aie::Renderer2D* renderer);
	virtual void onUpdate(float deltaTime) = 0;
	virtual void onDraw(aie::Renderer2D* renderer) = 0;
	virtual void onDrawOffset(aie::Renderer2D* renderer) = 0;

	const Matrix3& getLocalTransform() const;
	Vector3 getLocalTransformColumnVector(int column) const;
	const Matrix3& getGlobalTransform() const;

	void updateTransform();

	void setPosition(float x, float y);
	void setRotate(float degrees);
	void setScale(float width, float height);
	void translate(float x, float y, float deltaTime);
	void rotate(float degrees);
	void scale(float x, float y);

protected:

	scene_object* m_parent = nullptr;
	std::vector<scene_object*> m_children;


	Matrix3 m_global_transMatrix;
	Matrix3 m_local_transMatrix;
	Matrix3 m_child_offset = Matrix3(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 8.5f, 0.0f);

};