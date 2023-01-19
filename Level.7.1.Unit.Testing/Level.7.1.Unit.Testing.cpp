#include "pch.h"
#include "CppUnitTest.h"
#include "../Level.5.2.1.Graph.Search/Graph.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MyTest
{
	TEST_CLASS(Example)
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
			Assert::AreEqual(5, testGraph.numVertices());
			
		}
		TEST_METHOD(GraphNumVertices2)
		{
			Graph testGraph;
			testGraph.addEdge(0, 1);
			testGraph.addEdge(0, 2);
			testGraph.addEdge(1, 2);
			testGraph.addEdge(2, 3);
			testGraph.addEdge(5, 5);
			Assert::AreEqual(5, testGraph.numVertices());
			Assert::IsTrue(testGraph.numVertices() > 6);
		}
	};
}
