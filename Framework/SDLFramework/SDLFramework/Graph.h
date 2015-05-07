#pragma once

#include <vector>
#include "Node.h"
#include "IGameObject.h"
#include "FWApplication.h"
#include <math.h>
class Graph : public IGameObject
{
private:
	std::vector<Edge*> edge;

public:

	virtual void Draw();
	virtual void Update(float deltaTime) override;
	virtual void OnCollision(IGameObject * collidedObject) override;
	std::vector<Node*> nodes;
	Graph(FWApplication* application);
	double DistanceToEnd(double x1, double y1, double x2, double y2);
	virtual ~Graph();
	std::vector<Node*> getNodes();
};

