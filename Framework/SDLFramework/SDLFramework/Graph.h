#pragma once

#include <vector>
#include "Node.h"
#include "IGameObject.h"
#include "FWApplication.h"
class Graph : public IGameObject
{
	

private:
	
	Node* node1;
	Node* node2;
	Node* node3;
		  
	Node* node4;
	Node* node5;
	Node* node6;
	Node* node7;


	 
	std::vector<Edge*> edge;



public:

	virtual void Draw();
	virtual void Update(float deltaTime) override;
	virtual void OnCollision(IGameObject * collidedObject) override;
	std::vector<Node*> nodes;
	Graph(FWApplication* application);
	virtual ~Graph();
	std::vector<Node*> getNodes();
};

