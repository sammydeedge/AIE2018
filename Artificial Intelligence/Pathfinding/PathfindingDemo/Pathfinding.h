#pragma once
#include "Vector2.h"
#include <vector>

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

		node* parent;

		std::vector <edge> send_connections;
		std::vector <edge> receive_connections;
	};

	struct edge
	{
		node* sender;
		node* receiver;
		float cost;
	};

	std::vector<Vector2> dijkstrasSearch(node* originNode, node* destinationNode);
	void bubbleSort(std::vector<node*>* list);

protected:
	std::vector<node*>* openList;
	std::vector<node*>* closedList;
};