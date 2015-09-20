#pragma once
#include "Config.h"
#include "IGameObject.h"
#include "FWApplication.h"
#include "Node.h"
#include "Graph.h"
#include "Cow.h"
class Mouse : public IGameObject
{
private:
	Node* currentNode;
public:
	void setCurrentNode(Node* newCurrentCode);
	Node* getCurrentNode();


	virtual void Draw() override;
	virtual void Update(float deltaTime) override;
	virtual void OnCollision(IGameObject * collidedObject) override;
	void MoveMouse(vector<Node*>* route);
	void MoveLeft();
	void MoveRight();
	void PrintNodeNeighbours();
//	void MouseRoute();


	void MoveMiddle();
	Mouse();
	Mouse(Node* newNode);
	virtual ~Mouse();
};

