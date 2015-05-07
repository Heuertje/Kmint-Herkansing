#include "Node.h"
#include "Edge.h"
#include <iostream>
Node::Node()
{
}

Node::Node( int x, int y, int nodeID)
{
	xPosition = x;
	yPosition = y;
	mNodeID = nodeID;
	nodeWidth = 10;
	nodeHeight = 10;
	filled = true;

	mIsStartingNode = false;
	mIsTargetNode = false;
	amountOfEdgesChecked = 0;
	mNodeHasBeenIterated = false;
	mIsGValueCalculated = false;
	isAddedToClosedList = false;
	isNodeVisited = false;
}

Node::~Node()
{
	for (Edge* var : edges)
	{
///!!!!!!!!!!////!!!!		delete var;
	}
	edges.clear();
}

void Node::setX(double x)
{
	xPosition = x;
}

double Node::getXPos()
{
	return xPosition;
}

void Node::setY(double y)
{
	yPosition = y;
}

double Node::getYPos()
{
	return yPosition;
}

void Node::setWidth(double width)
{
	nodeWidth = width;
}

double Node::getWidth()
{
	return nodeWidth;
}

void Node::setHeight(double height)
{
	nodeHeight = height;
}

double Node::getHeight()
{
	return nodeHeight;
}

bool Node::isFilled()
{
	return filled;
}

void Node::addNeighbor(Node*newNeighbor)
{
	neighbors.push_back(newNeighbor);
}

void Node::addEdge(Edge*newEdge)
{
	edges.push_back(newEdge);
}

std::vector<Edge*> Node::getEdges()
{
	return edges;
}

void Node::SetNodeID(){
	mNodeID++;
}

int Node::GetNodeID(){
	return mNodeID;
}

std::vector<Edge*> Node::GetEdgesToNeighbors()
{
	return edgesToNeighbors;
}
std::vector<Node*> Node::GetNeighbors(){
	return neighbors;
}
void Node::AddNeighbors(Node* neighbor)
{
	//create a new edge that will connect the 'this' node with the 'neighbor' node
	auto edge = new Edge(
		this->xPosition,
		this->yPosition,
		neighbor->getXPos(),
		neighbor->getYPos()
		);
	this->addEdge(edge);
	neighbor->addEdge(edge);
	edge->SetLeftConnectedNodeID(this->GetNodeID());
	edge->SetRightConnectedNodeID(neighbor->GetNodeID());

	//add the new edge to 'this' nodes' neiboringEdge list
	edgesToNeighbors.push_back(edge);

	//ALSO add the new edge to the neigboringEdge list of the 'neighbor'
	neighbor->edgesToNeighbors.push_back(edge);


	//now add the actual neighbor to this nodes neighbor list
	neighbors.push_back(neighbor);


	//Very important! Now add the current node to the list of the neighbor!
	//This makes sure that connecting nodes always have a two-sided connection!
	neighbor->neighbors.push_back(this);



	mApplication->AddRenderable(edge);
}

void Node::Draw(){
	FWApplication::GetInstance()->DrawRect(xPosition, yPosition, nodeWidth, nodeHeight, filled);
	//#TestDraw
	//mApplication->SetColor(Color(100, 0, 200, 255));
	//mApplication->DrawLine(0,0, 500,500);
	//#endTestDraw
}
void Node::Update(float deltaTime){}
void Node::OnCollision(IGameObject * collidedObject){}