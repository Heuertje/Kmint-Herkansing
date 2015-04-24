#include "Graph.h"
#include "Node.h"
#include "Edge.h"
#

Graph::Graph()
{ 
	// initialize nodes
	node1 = new Node(100, 80, 10, 10, true);
	node2 = new Node(220, 110, 10, 10, true);
	node3 = new Node(180, 230, 10, 10, true);
	node4 = new Node(300, 160, 10, 10, true);
	node5 = new Node(430, 530, 10, 10, true);
	node6 = new Node(520, 320, 10, 10, true);
	node7 = new Node(100, 320, 10, 10, true);

	//initialize nodes
	auto edge = new Edge(node1->xPosition, node1->yPosition, node2->xPosition, node2->yPosition);
	node1->addEdge(edge);

	edge = new Edge(node2->xPosition, node2->yPosition, node3->xPosition, node3->yPosition);
	node2->addEdge(edge);

	edge = new Edge(node3->xPosition, node3->yPosition, node4->xPosition, node4->yPosition);
	node3->addEdge(edge);

	edge = new Edge(node3->xPosition, node3->yPosition, node5->xPosition, node5->yPosition);
	node3->addEdge(edge);

	edge = new Edge(node4->xPosition, node4->yPosition, node5->xPosition, node5->yPosition);
	node4->addEdge(edge);

	edge = new Edge(node4->xPosition, node4->yPosition, node6->xPosition, node6->yPosition);
	node4->addEdge(edge);

	edge = new Edge(node5->xPosition, node5->yPosition, node6->xPosition, node6->yPosition);
	node5->addEdge(edge);

	edge = new Edge(node2->xPosition, node2->yPosition, node4->xPosition, node4->yPosition);
	node2->addEdge(edge);
	
	edge = new Edge(node1->xPosition, node1->yPosition, node7->xPosition, node7->yPosition);
	node7->addEdge(edge);

	edge = new Edge(node7->xPosition, node7->yPosition, node5->xPosition, node5->yPosition);
	node7->addEdge(edge);

	//add created edges to their respective nodes

	/*
	for (int dummyEdgesCounter = 0; dummyEdgesCounter < 4; dummyEdgesCounter++)
	{
		Edge*dummyEdge = new Edge(node3->xPosition, node3->yPosition, 250 +( 20 *dummyEdgesCounter),200 +( 120 * dummyEdgesCounter));
		node3->addEdge(dummyEdge);

		delete dummyEdge;
	}
	*/

	

	//add all nodes into a vector for future iterations
	nodes.push_back(*node1);
	nodes.push_back(*node2);
	nodes.push_back(*node3);
	nodes.push_back(*node4);
	nodes.push_back(*node5);
	nodes.push_back(*node6);
	nodes.push_back(*node7);
}


Graph::~Graph()
{
	for (int i = 0; i < edge.size(); i++){
		delete edge[i];
	}
	delete node1;
	delete node2;
	delete node3;
	delete node4;
	delete node5;
	delete node6;

}

std::vector<Node> Graph::getNodes()
{
	return nodes;
}


