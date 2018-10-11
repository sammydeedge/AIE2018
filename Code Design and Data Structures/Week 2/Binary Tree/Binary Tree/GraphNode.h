#pragma once
#include <vector>
#include "GraphEdge.h"

//template <typename T>
class GraphNode
{
public:
	GraphNode()
	{
	
	}
	GraphNode(int data)
	{
		m_data = data;
	}
	~GraphNode()
	{
		for (auto& edge : m_edges)
		{
			delete edge;
		}
	}
	void setdata(int data)
	{
		m_data = data;
	}

	int get_data() const
	{
		return m_data;
	}

	void addEdge(GraphEdge* newEdge)
	{
		m_edges.push_back(newEdge);
	}

	std::vector<GraphEdge*>& getEdges() { return m_edges; }



protected:
	int m_data;
	std::vector<GraphEdge*> m_edges;
};

