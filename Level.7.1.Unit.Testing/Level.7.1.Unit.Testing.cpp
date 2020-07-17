#include "pch.h"
#include "CppUnitTest.h"
#include "../Level.5.2.1.Graph.Search/Graph.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Level71UnitTesting
{
	TEST_CLASS(Level71UnitTesting)
	{
	public:
		
		TEST_METHOD(GraphNumVertices)
		{
			Graph testGraph;
			testGraph.addEdge(0, 1);
			testGraph.addEdge(0, 2);
			testGraph.addEdge(1, 2);
			testGraph.addEdge(2, 3);
			testGraph.addEdge(5, 5);
			Assert::AreEqual(4, testGraph.numVertices());
			
		}
	};
}
