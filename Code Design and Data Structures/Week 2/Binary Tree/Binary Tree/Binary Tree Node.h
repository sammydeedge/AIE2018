#pragma once
#include <iostream>
#include <queue>
#include "GraphNode.h"

class binTree : public GraphNode
{
public:

	binTree()
	{
		m_data = 0;
		leftChild = nullptr;
		rightChild = nullptr;
		parent = nullptr;
	}

	binTree(int input)
	{
		m_data = input;
	}

	void push(int input)
	{

		binTree* newNode = new binTree(input);

		if (rootNode == nullptr)
		{
			rootNode = newNode;
		}
		else
		{
			bool nodeFound = false;
			binTree* current = rootNode;
			while (!nodeFound)
			{

				if (input < current->m_data)
				{
					if (current->leftChild == nullptr)
					{
						current->leftChild = newNode;
						newNode->parent = current;
						nodeFound = true;
					}
					else
					{
						current = current->leftChild;
					}
				}
				else if (input > current->m_data)
				{
					if (current->rightChild == nullptr)
					{
						current->rightChild = newNode;
						newNode->parent = current;
						nodeFound = true;
					}
					else
					{
						current = current->rightChild;
					}
				}
				else
				{
					delete newNode;
					current = nullptr;
					nodeFound = true;
				}
			}
		}
	}

	binTree find(int value)
	{
		binTree* current = rootNode;
		bool nodeFound = false;
		while (!nodeFound)
		{
			if (current->m_data == value)
			{
				nodeFound = true;
			}
			else
			{
				if (current->m_data < value)
				{
					current = current->leftChild;
				}
				else
				{
					current = current->rightChild;
				}
			}
		}
		return *current;
	}

	void pop(binTree* node)
	{
		if (node->leftChild == nullptr && node->rightChild == nullptr)
		{
			binTree* parent = node->parent;
			if (parent->leftChild == node)	{ parent->leftChild = nullptr; }
			else							{ parent->rightChild = nullptr; }
		}
		else if (node->leftChild != nullptr || node->rightChild != nullptr)
		{
			binTree* parent = node->parent;
			binTree* grandparent = parent->parent;
			if (grandparent->leftChild == parent)
			{
				grandparent->leftChild == node;
			}
			else
			{
				grandparent->rightChild == node;
			}
			
		}
		else if (node->leftChild != nullptr && node->rightChild != nullptr)
		{
			binTree* current = node->rightChild;
			bool foundNode = false;
			while (!foundNode)
			{
				if (current->leftChild == nullptr)
				{
					foundNode = true;
				}
				else
				{
					current = current->leftChild;
				}
			}
			node->m_data = current->m_data;
			Node_pop(node);

		}
		delete node;
	}

	//void print()
	//{
	//	binTree* node = rootNode;
	//	std::queue<binTree*> printQueue;
	//	std::queue<binTree*> storageQueue;

	//	printQueue.push(node);
	//	
	//	while (!printQueue.empty())
	//	{
	//		for (int i = 0; i < printQueue.size(); ++i)
	//		{
	//			if (printQueue.front()->leftChild != nullptr || printQueue.front()->rightChild != nullptr)
	//			{
	//				if (node->leftChild != nullptr) { storageQueue.push(node->leftChild); }
	//				if (node->rightChild != nullptr) { storageQueue.push(node->rightChild); }
	//			}


	//			for (int i = 0; i < printQueue.size(); ++i)
	//			{
	//				std::cout << printQueue.front()->m_data << ", ";
	//				printQueue.pop();
	//			}
	//			std::cout << std::endl;
	//			for (int i = 0; i < storageQueue.size(); ++i)
	//			{
	//				printQueue.push(storageQueue.front());
	//				storageQueue.pop();
	//			}
	//		}
	//	}
	//}

	void print() const
	{
		using NodeList = std::list<Node*>
			std::vector<NodeList> nodes;

		nodes.push_back(NodeList{});
		nodes[0].push_back(m_root);
		int currentIndex = 0;
		bool more_nodes = true;
		while (more_nodes)
		{
			more_nodes = false;
			nodes.push_back(NodeList{});
			for (auto it = nodes[currentIndex].begin(); it != nodes[currentIndex].end(); ++i)
			{
				auto& node = *it;
				if (node == nullptr) continue;
				nodes[currentIndex + 1].push_back(node ? node->left : nullptr);
				nodes[currentIndex + 1].push_back(node ? node->right : nullptr);
				if (node && (node->left || node->right))
				{
					more_nodes = true
				}
			}
			currentIndex++;
		}

		int gapSize = std::pow(2, nodes.size() - 1);
			for (auto& layer : nodes)
			{
				int perNodeGapSize = gapSize / layer;

				for (auto& node : layer)
				{
					if (node != nullptr) { std::cout << node->data; }
					for (int i = 0; i < perNodeGapSize; ++i)
					{
						std::cout << "\t";
					}
				}
				std::cout << std::endl;
			}
	}

protected:
	binTree* leftChild;
	binTree* rightChild;
	binTree* parent;
	binTree* rootNode = nullptr;
};