#include "scene_object.h"
#include <cmath>

//Converts Degress into Radians
float scene_object::convertDegtoRad(float degrees)
{
	float convert_coeff = 3.14159265358f / 180;
	return degrees * convert_coeff;
}

//Get sprite parents
scene_object* scene_object::getParent() const
{
	return m_parent;
}

//get number of children
size_t scene_object::childCount() const
{
	return m_children.size();
}

//get child at given index
scene_object* scene_object::getChild(unsigned int index) const
{
	return m_children[index];
}

void scene_object::addChild(scene_object* child)
{
	//check that child doesn't already have a parent
	assert(child->m_parent == nullptr);
	//assign the element being called to be the arguments parent
	child->m_parent = this;
	child->m_local_transMatrix = child->m_local_transMatrix + m_child_offset;
	//Add new child to the children list
	m_children.push_back(child);
}

void scene_object::removeChild(scene_object* child)
{
	//find the child
	auto iter = std::find(m_children.begin(), m_children.end(), child);
	
	//if found:
	if (iter != m_children.end())
	{
		//Remove
		m_children.erase(iter);
		//and unassign the parent
		child->m_parent = nullptr;
	}
}

scene_object::~scene_object()
{
	//detach sprite from parent
	if (m_parent != nullptr)
	{
		m_parent->removeChild(this);
	}

	//remove all children
	for (auto child : m_children)
	{
		child->m_parent = nullptr;
	}
}

void scene_object::update(float deltaTime)
{
	//run onUpdate function
	onUpdate(deltaTime);

	//recursively run update function on children
	for (auto child : m_children)
	{
		child->update(deltaTime);
	}
}

void scene_object::draw(aie::Renderer2D* renderer)
{
	//run onDraw function
	if (m_parent == nullptr)	 { onDraw(renderer); }
	else						 { onDrawOffset(renderer); }

	//recursively run draw function on children
	for (auto child : m_children)
	{
		child->draw(renderer);
	}

}

//Returns the local translation matrix
const Matrix3& scene_object::getLocalTransform() const
{
	return m_local_transMatrix;
}

//Returns a Vector from the column
Vector3 scene_object::getLocalTransformColumnVector(int column) const
{
	return m_local_transMatrix[column];
}

//Returns the gloable transformation matrix
const Matrix3& scene_object::getGlobalTransform() const
{
	return m_global_transMatrix;
}

//Performs transformation updates
void scene_object::updateTransform()
{
	if (m_parent != nullptr)
	{
		m_global_transMatrix = m_parent->m_global_transMatrix * m_local_transMatrix;
	}
	else
	{
		m_global_transMatrix = m_local_transMatrix;
	
		
	}
	for (auto child : m_children)
	{
		child->updateTransform();
	}
}

//Sets position of object, via its local transfomation matrix
void scene_object::setPosition(float x, float y)
{
	m_local_transMatrix.trans[0] = x;
	m_local_transMatrix.trans[1] = y;
	m_local_transMatrix.trans[2] = 1;

	updateTransform();
}

//Sets Rotate to a certain angle in degrees
void scene_object::setRotate(float degrees)
{
	float rotate_radians = convertDegtoRad(degrees);
	m_local_transMatrix.setRotateZ(rotate_radians);
	updateTransform();
}

//Sets the scale of an object
void scene_object::setScale(float width, float height)
{
	m_local_transMatrix.setScaled(width, height, 1);
	updateTransform();
}

//Translates object along x and y axis
void scene_object::translate(float x, float y, float deltaTime)
{
	float trans_speed = 200 * deltaTime;
	m_local_transMatrix.trans[0] += x * trans_speed;
	m_local_transMatrix.trans[1] += y * trans_speed;
	updateTransform();
}

//Increments (or decrements) rotation of object by a given angle in degrees
void scene_object::rotate(float degrees)
{
	float rotate_speed = 100;
	float rotate_radians = convertDegtoRad(degrees);
	Matrix3 rotate_matrix;
	rotate_matrix.setRotateZ(rotate_radians * rotate_speed);
	m_local_transMatrix = m_local_transMatrix * rotate_matrix;
	updateTransform();
}

void scene_object::scale(float width, float height)
{
	m_local_transMatrix.setScaled(width, height, 1);
	updateTransform();
}