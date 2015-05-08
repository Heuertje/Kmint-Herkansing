#pragma once
#include "IGameObject.h"
class Node;

class Edge : public IGameObject
{
private:
	Node* mLeftConnectedNode;
	Node* mRightConnectedNode;
	int mWeight;

public:
	virtual void Draw();
	virtual void Update(float deltaTime) override;
	virtual void OnCollision(IGameObject * collidedObject) override;
	double startXPosition;
	double startYPosition;

	double endXPosition;
	double endYPosition;
	int GetWeight();
	Node* GetLeftConnectedNode();
	void SetLeftConnectedNode(Node* node);
	Node* GetRightConnectedNode();
	void SetRightConnectedNode(Node* neighbourNode);
	Node* getOtherNode(Node* node);

	//constructor, destructor
	Edge(double startX, double startY, double endX, double endY);
	~Edge();
};

