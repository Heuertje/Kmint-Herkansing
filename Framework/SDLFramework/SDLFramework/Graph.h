#pragma once

#include <vector>
#include "Node.h"
#include "IGameObject.h"
#include "FWApplication.h"
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
	virtual ~Graph();
	std::vector<Node*> getNodes();
};

