#pragma once
#include <vector>
#include "Edge.h"
class Node
{
private:
	


	

public:
	double xPosition;
	double yPosition;
	double nodeHeight;
	double nodeWidth;
	bool isFilled;
	
	std::vector<Node> neighbours;
	std::vector<Edge> edges;
	Node();
	Node( int x, int y, int width, int height, bool filled);
	~Node();
	void setX(double x);
	void setY(double y);

	void setWidth(double width);

	void setHeight(double height);

	void addNeighbour(Node*newNeighbour);

	void addEdge(Edge*newEdge);
	std::vector<Edge> getEdges();
};

