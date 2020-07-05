#ifndef GRAPH_H
#define GRAPH_H
#include <map>
#include <vector>
#include <memory>
struct Vertex
{
	Vertex(int num) :num(num) {}
	int num;
	std::map<std::shared_ptr<Vertex>, int> adjacents;
};
class Graph
{
public:
	Graph();

	void addEdge(int vertex, int adjacentVertex, int weight);
	std::shared_ptr<Vertex> minDistance(
		std::map<std::shared_ptr<Vertex>, int> distances, 
		std::set<std::shared_ptr<Vertex>> finalDistanceFound);
	int printSolution(std::map<std::shared_ptr<Vertex>, int> distances);
	void dijkstra(int src);

	void BFS(int startNum);
	int numVertices() const;
private:
	std::shared_ptr<Vertex> addVertex(int vertexNum);
	std::vector<std::shared_ptr<Vertex>> vertices;

};
#endif // !GRAPH_H

