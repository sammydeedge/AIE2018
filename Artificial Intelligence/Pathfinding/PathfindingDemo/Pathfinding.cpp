#include "Pathfinding.h"
#include <cassert>

std::vector<Vector2> Pathfinder::dijkstrasSearch(node* originNode, node* destinationNode)
{
	originNode->parent = nullptr;
	openList->push_back(originNode);
	node* currentNode;

	while (openList != nullptr)
	{
		bubbleSort(openList);
		currentNode = openList->front();

		if (currentNode = destinationNode) { break; }

		openList->erase(currentNode);
		closedList->push_back(currentNode);

		for (auto path : currentNode->send_connections)
		{
			closedList->push_back(path.receiver);
			path.receiver->gScore = currentNode->gScore + path.cost;
			Vector2 displacement = currentNode->position - destinationNode->position;
			path.receiver->hScore = displacement.magnitude();
			path.receiver->fScore = path.receiver->gScore + path.receiver->hScore;
			path.receiver->parent = currentNode;
		}
	}
	std::vector<Vector2> path;
	currentNode = destinationNode;
	while (currentNode)
	{
		path.push_back(currentNode->position);
		currentNode = currentNode->parent;
	}
	return path;
}



void Pathfinder::bubbleSort(std::vector<node*>* list)
{
	//Loops through each sort function for the number of elements in vector
	for (int i = 0; i < list->size(); ++i)
	{
		for (int j = list->size() - 1; --j;)
		{
			if (list[j] < list[j - 1])
			{
				list[j].swap(list[j - 1]);
			}
		}
	}
}