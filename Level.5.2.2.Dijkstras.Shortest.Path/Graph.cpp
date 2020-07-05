#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include "Graph.h"

using namespace std;
Graph::Graph()
{}

void Graph::addEdge(int vertex, int adjacentVertex, int weight)
{
	auto result1{ addVertex(vertex) };
	auto result2{ addVertex(adjacentVertex) };
	result1->adjacents[result2] = weight;
	result2->adjacents[result1] = weight;
}

std::shared_ptr<Vertex> Graph::minDistance(
	std::map<std::shared_ptr<Vertex>, int> distances, 
	std::set<std::shared_ptr<Vertex>> finalDistanceFound)
{
	std::pair<std::shared_ptr<Vertex>, int> shortestDistance{ nullptr, INT_MAX };
	for (auto& currentPair : distances)
	{
		if (auto distanceToCompare{ std::find(distances.begin(), distances.end(), currentPair.first) };
			//not in distance set
			std::find(finalDistanceFound.begin(), finalDistanceFound.end(), currentPair.first) == finalDistanceFound.end()
			//and distance shorter than current shortest
			&& distanceToCompare->second <= shortestDistance.second
			)
		{
			shortestDistance = currentPair;
		}
	}
	return shortestDistance.first;
}

void Graph::dijkstra(int startNum)
{
	//find vertex of passed in number
	std::shared_ptr<Vertex> src{ *(std::find_if(vertices.begin(), vertices.end(),
		[=](std::shared_ptr<Vertex> currVertex)
		{
			return startNum == currVertex->num;
		})) };

	/**************** Setup ***********/
	std::map<std::shared_ptr<Vertex>, int> distances;
	for (auto vertex : vertices)
	{
		if (vertex == src) distances[vertex] = 0;
		else distances[vertex] = INT_MAX;		
	}
	std::set<std::shared_ptr<Vertex>> finalDistanceFound;
	/*********************************/

	for (auto vertex : vertices)
	{
		auto nextVertex{ minDistance(distances, finalDistanceFound) };
		finalDistanceFound.insert(nextVertex);
		for (auto adjacent : vertices)
		{

			if (
				std::find(finalDistanceFound.begin(), finalDistanceFound.end(), adjacent) == finalDistanceFound.end()
				&& std::find_if(vertex->adjacents.begin(), vertex->adjacents.end(), 
					[=](std::pair<std::shared_ptr<Vertex>, int> currAdj) {return currAdj.first == adjacent; }) 
						== vertex->adjacents.end()
				)
			{
				int distanceToHere{ std::find_if(distances.begin(), distances.end(), 
					[=](std::pair<std::shared_ptr<Vertex>, int> compareTo) {return compareTo.first == vertex; })->second };
				int distanceToAdjacent{ std::find_if(vertex->adjacents.begin(), vertex->adjacents.end(),
					[=](std::pair<std::shared_ptr<Vertex>, int> compareTo) {return compareTo.first == adjacent; })->second };

			}
		}
	}
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
				visited.push_back(vertex.first);//put in visited
				vQueue.push(vertex.first);//push on queue
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
