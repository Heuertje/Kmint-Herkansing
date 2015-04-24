#include "Node.h"


Node::Node()
{
	
}

Node::Node( int x, int y, int width, int height, bool filled)
{
	xPosition = x;
	yPosition = y;
	nodeWidth = width;
	nodeHeight = height;
	isFilled = filled;
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