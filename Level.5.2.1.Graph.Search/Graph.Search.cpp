#include <iostream>
#include "Graph.h"
using namespace std;

int main()
{
	Graph graph;
	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(1, 2);
	graph.addEdge(2, 3);
	/*3-2-0
		 \/
		  1*/

	cout << "Where do you want to start traversal from? (0 through " << graph.numVertices() - 1 << "): ";
	int start;
	cin >> start;
	graph.BFS(start);
	system("PAUSE");
	return 0;
}