#ifndef GRAPH_H
#define GRAPH_H
#include <set>
#include <vector>
#include <memory>
struct Vertex
{
	Vertex(int num):num(num){}
	int num;
	std::set<std::shared_ptr<Vertex>> adjacents;
};
class Graph
{
public:
	Graph();

	void addEdge(int vertex, int adjacentVertex);

	void BFS(int startNum);
	int numVertices() const;
private:
	std::shared_ptr<Vertex> addVertex(int vertexNum);
	std::vector<std::shared_ptr<Vertex>> vertices;

};
#endif // !GRAPH_H

