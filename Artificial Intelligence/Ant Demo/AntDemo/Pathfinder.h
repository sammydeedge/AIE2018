#pragma once
#include "Vector2.h"
#include "Matrix4.h"
#include "AIController.h"
#include <list>
#include <vector>
#include "Agent.h"
#include "CLDR.h"
#include "Texture.h"
#include "Renderer2D.h"

namespace aie { class Application; class Renderer2D; };

class Pathfinder
{
public:

	struct edge;

	struct node
	{
		Vector2 position;

		float gScore;
		float hScore;
		float fScore;

		node* parent = nullptr;

		bool visited = false;

		std::vector <edge*> connections;

		void reset();
	};

	struct edge
	{
		node const* startNode;
		node const* endNode;
		float distance;

	};

	Pathfinder() = default;
	Pathfinder(const Pathfinder& other) = delete;
	Pathfinder& operator=(const Pathfinder& other) = delete;

	node* addNode(Vector2 XY);
	node* addNode(float x, float y);
	void connectSelectedNodes(Pathfinder::node const* m_selectedPathfindNode, Pathfinder::node const* node);

	void removeNode(Vector2 location, float maxDistance = 100.0f);
	void removeNode(node const* node);

	node*		getClosestNode(Vector2 location, float maxDistance = 100.0f) const;

	void debugRender(aie::Renderer2D* renderer);



	std::list<Vector2> getPath(node* originNode, node* destinationNode) const;

protected:
	class Agent*				m_user = nullptr;
	class aie::Application*		m_OwningApp = nullptr;

	std::vector<node*>			m_nodes;
	std::list<node*>			openList;
	std::vector<node*>			closedList;

};
