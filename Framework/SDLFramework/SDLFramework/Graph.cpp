#include "Graph.h"
#include "Node.h"
#include "Edge.h"
#

Graph::Graph(FWApplication* application)
{ 

	// initialize nodes
	Node* node1 = new Node(100, 80);;
	Node* node2 = new Node(220, 110);
	Node* node3 = new Node(180, 230);

	Node* node4 = new Node(300, 160);
	Node* node5 = new Node(430, 530);
	Node* node6 = new Node(520, 320);
	Node* node7 = new Node(100, 320);

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
	nodes.push_back(node1);
	nodes.push_back(node2);
	nodes.push_back(node3);
	nodes.push_back(node4);
	nodes.push_back(node5);
	nodes.push_back(node6);
	nodes.push_back(node7);
}

void Graph::Draw(){}
void Graph::Update(float deltaTime){}
void Graph::OnCollision(IGameObject * collidedObject){}

Graph::~Graph()
{
	for (Node* var : nodes)
	{
		delete var;
	}
	nodes.clear();
}

std::vector<Node*> Graph::getNodes()
{
	return nodes;
}


