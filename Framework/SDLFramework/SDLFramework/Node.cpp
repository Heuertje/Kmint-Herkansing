#include "Node.h"


Node::Node()
{
	
}

Node::Node( int x, int y)
{
	xPosition = x;
	yPosition = y;
	nodeWidth = 10;
	nodeHeight = 10;
	isFilled = true;

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
}

void Node::setX(double x)
{
	xPosition = x;
	
}

void Node::setY(double y)
{
	yPosition = y;
}

void Node::setWidth(double width)
{
	nodeWidth = width;

}

void Node::setHeight(double height)
{
	nodeHeight = height;
}

void Node::addNeighbour(Node*newNeighbour)
{
	neighbours.push_back(*newNeighbour);
}

void Node::addEdge(Edge*newEdge)
{
	edges.push_back(*newEdge);
}

std::vector<Edge> Node::getEdges()
{
	return edges;
}

void Node::Draw(){
	//#TestDraw
	mApplication->SetColor(Color(100, 0, 200, 255));
	mApplication->DrawLine(0,0, 500,500);
	//#endTestDraw

}

void Node::Update(float deltaTime){}
void Node::OnCollision(IGameObject * collidedObject){}