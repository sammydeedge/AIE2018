#include <iostream>
#include <vector>
#include "GraphNode.h"
#include "GraphEdge.h"
#include "Binary Tree Node.h"
#include <random>
#include <ctime>

//class Graph
//{
//public:
//
//};


void demo_graphNode()
{
	GraphNode* node = new GraphNode(10);
	GraphNode* node2 = new GraphNode(15);
	GraphNode* node3 = new GraphNode(20);

	node->addEdge(new GraphEdge(node2));
	node->addEdge(new GraphEdge(node3));
	node2->addEdge(new GraphEdge(node));
	node3->addEdge(new GraphEdge(node2));

	std::cout << "node has " << node->getEdges().size() << " edges!\n";
	std::cout << "node2 has " << node2->getEdges().size() << " edges!\n";
	std::cout << "node3 has " << node3->getEdges().size() << " edges!\n";

	delete node;
	delete node2;
	delete node3;
}

void demo_binTree()
{
	binTree tree;
	//srand((unsigned int)time(nullptr));

	//for (int i = 0; i < 12; ++i)
	//{
	//	int random = (rand() % 100) + 1;
	//	tree.Node_push(random);
	//}

	tree.Node_push(13);
	tree.Node_push(7);
	tree.Node_push(19);
	tree.Node_push(3);
	tree.Node_push(11);
	tree.Node_push(17);
	tree.Node_push(29);

	tree.Node_print();

}




int main()
{
	demo_binTree();


	system("pause");
	return 0;
}