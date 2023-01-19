#include <iostream>
#include <algorithm>
#include "Graph.h"
#include <queue>
using namespace std;
Graph::Graph()
{}

void Graph::addEdge(int vertex, int adjacentVertex)
{
	auto result1{ addVertex(vertex) };
	auto result2{ addVertex(adjacentVertex) };
	result1->adjacents.insert(result2);
	result2->adjacents.insert(result1);	
}

void Graph::BFS(int startNum)
{
	std::shared_ptr<Vertex> start{ *(std::find_if(vertices.begin(), vertices.end(),
		[=](std::shared_ptr<Vertex> currVertex)
		{
			return startNum == currVertex->num;
		})) };
	vector<std::shared_ptr<Vertex>> visited{ start };
	queue<std::shared_ptr<Vertex>> vQueue;
	vQueue.push(start);

	while (!vQueue.empty())
	{
		start = vQueue.front();
		cout << start->num << " ";
		vQueue.pop();

		for (auto vertex : start->adjacents)
		{
			//if not in visited
			if (auto haveVisited{ std::find(visited.begin(), visited.end(), vertex) };
				haveVisited == visited.end())
			{
				visited.push_back(vertex);//put in visited
				vQueue.push(vertex);//push on queue
			}
		}
	}
}

int Graph::numVertices() const
{
	return vertices.size();
}

std::shared_ptr<Vertex> Graph::addVertex(int vertexNum)
{
	if (auto resultIter{ std::find_if(vertices.begin(), vertices.end(),[&](std::shared_ptr<Vertex>& vertice)
		{
			return vertexNum == vertice->num;
		}) };
		resultIter == vertices.end())
	{
		vertices.push_back(std::make_shared<Vertex>(vertexNum));
		return vertices.back();
	}
	else
	{
		return *resultIter;
	}
		
}
