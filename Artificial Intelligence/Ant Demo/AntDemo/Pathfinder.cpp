#include "Pathfinder.h"
#include <cassert>
#include <algorithm>
#include <queue>


//Connects Nodes
void Pathfinder::connectSelectedNodes(Pathfinder::node const* startNode, Pathfinder::node const* endNode)
{
	//Makes an edge stored in startNode object
	edge* connector = new edge();													//New edge is made
	connector->distance = (startNode->position - endNode->position).magnitude();	//with a distance float that holds the distance between the nodes
	//connects START ----> END
	connector->startNode = startNode;												
	connector->endNode = endNode;
	//Puts edge in list of edges connected to startNode
	((node*)startNode)->connections.push_back(connector);

	//Same functionality, but stored in endNode
	connector = new edge();
	connector->distance = (startNode->position - endNode->position).magnitude();
	connector->startNode = endNode;
	connector->endNode = startNode;
	((node*)endNode)->connections.push_back(connector);
}

//Creates a new node at a given position from a Vector 2 (e.g. another set of position coordinates)
Pathfinder::node* Pathfinder::addNode(Vector2 XY)
{
	node* newNode = new node();
	newNode->position = XY;
	m_nodes.push_back(newNode);

	return newNode;
}

//Creates a node at a given position from 2 floats
Pathfinder::node* Pathfinder::addNode(float x, float y)
{
	node* newNode = new node();
	newNode->position = Vector2(x,y);
	m_nodes.push_back(newNode);

	return newNode;
}

//Node remover, chooses node near a location, with a given range
void Pathfinder::removeNode(Vector2 location, float maxDistance)
{
	node const* node = getClosestNode(location, maxDistance);		//Finds a node
	if (node != nullptr) { removeNode(node); }						//When the actual is determined, it calls removeNode that actually removes it
}

void Pathfinder::removeNode(node const* node)
{
	for (auto it = m_nodes.begin(); it != m_nodes.end(); ++it)		//Iterates through m_nodes
	{
		if (*it == node)											//If it matches the searched for node:
		{
			delete *it;													//the node is deleted
			m_nodes.erase(it);											//and removed from the list of nodes
			return;
		}
	}
}

//Get the closest Node to a location
Pathfinder::node* Pathfinder::getClosestNode(Vector2 location, float maxDistance /*= 100.0f*/) const
{
	Pathfinder::node* bestNode = nullptr;
	float bestDistance = maxDistance;

	for (auto* node : m_nodes)
	{
		float distance = (node->position - location).magnitude();
		if (distance < bestDistance)
		{
			bestNode = node;
			bestDistance = distance;
		}
	}

	return bestNode;
}

void Pathfinder::debugRender(aie::Renderer2D* renderer)
{
	for (auto* node : m_nodes)
	{
		renderer->setRenderColour(0.0f, 1.0f, 0.0f, 1.0f);
		renderer->drawCircle(node->position.x, node->position.y, 10);

		for (auto* edge : node->connections)
		{
			renderer->setRenderColour(1.0f, 1.0f, 1.0f, 1.0f);
			renderer->drawLine(
				edge->startNode->position.x, edge->startNode->position.y,
				edge->endNode->position.x, edge->endNode->position.y,
				3);
		}
	}
}


std::list<Vector2> Pathfinder::getPath(node* originNode, node* destinationNode) const
{

	for (auto* node : m_nodes)
		{
			node->reset();
		}

	auto nodeCompare = [](node* first, node* second)
	{
		return first->fScore > second->fScore;
	};

	std::priority_queue<node*, std::vector<node*>, decltype(nodeCompare)> openList(nodeCompare);
	std::list<Vector2> path;

	openList.push((node*)originNode);
	while (!openList.empty())
	{
		node* bestNode = openList.top();
		openList.pop();

		if (bestNode == destinationNode)
		{
			node* currentNode = bestNode;
			while (currentNode != nullptr)
			{
				path.push_front(currentNode->position);
				currentNode = currentNode->parent;
			}
			break;
		}
		else
		{
			for (auto fork : bestNode->connections)
				{
					node* nextNode = (node*)fork->endNode;
						if (nextNode->visited) continue; 

					float gScore = bestNode->gScore + fork->distance;
					float hScore = fork->distance;
					float fScore = gScore + hScore;
					if (nextNode->parent == nullptr)
					{
						nextNode->parent = bestNode;
						nextNode->gScore = gScore;
						nextNode->hScore = hScore;
						nextNode->fScore = fScore;
						openList.push(nextNode);
					}
					else
					{
						if (fScore < nextNode->fScore)
						{
							nextNode->parent = bestNode;
							nextNode->gScore = gScore;
							nextNode->hScore = hScore;
							nextNode->fScore = fScore;
						}
					}
				}
			}
		bestNode->visited = true;
		
		}
		
	return path;
}

void Pathfinder::node::reset()
{
	parent = nullptr;
	visited = false;

	fScore = 0.0f;
	gScore = 0.0f;
	hScore = 0.0f;
}
