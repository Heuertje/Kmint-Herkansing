#pragma once

#include <vector>
#include "Node.h"
#include "IGameObject.h"
#include "FWApplication.h"
#include <math.h>
using namespace std;
class Graph : public IGameObject
{
private:
	std::vector<Edge*> edge;

public:

	virtual void Draw();
	virtual void Update(float deltaTime) override;
	virtual void OnCollision(IGameObject * collidedObject) override;
	vector<Node*> nodes;
	Graph(FWApplication* application);
	double DistanceToNode(Node* goal, Node* child);
	virtual ~Graph();
	//double CalcH(goal, );
	vector<Node*>* ASter(Node* start, Node* goal);
	vector<Node*> getNodes();
};

