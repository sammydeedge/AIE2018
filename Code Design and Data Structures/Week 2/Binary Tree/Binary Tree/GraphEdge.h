#pragma once

//template <typename T>
class GraphNode;

//template <typename T>
struct GraphEdge
{
	GraphEdge(GraphNode* connectionNode, float cost = 1.0f)
	{
		m_connectTo = connectionNode;
		m_edgeCost = cost;
	}

	GraphNode* m_connectTo;
	float m_edgeCost;
};