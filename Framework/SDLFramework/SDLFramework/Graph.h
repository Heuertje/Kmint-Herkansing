#pragma once

#include <vector>
#include "Node.h"

class Graph
{
	

private:
	
	Node*node1;
	Node*node2;
	Node*node3;

	Node*node4;
	Node*node5;
	Node*node6;
	Node*node7;


	 
	std::vector<Edge*> edge;



public:
	std::vector<Node> nodes;
	Graph();
	virtual ~Graph();
	std::vector<Node> getNodes();
};

