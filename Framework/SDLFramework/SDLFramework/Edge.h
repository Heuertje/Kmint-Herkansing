#pragma once
#include "IGameObject.h"
class Edge : public IGameObject
{
private:


public:
	virtual void Draw();
	virtual void Update(float deltaTime) override;
	virtual void OnCollision(IGameObject * collidedObject) override;
	double startXPosition;
	double startYPosition;

	double endXPosition;
	double endYPosition;
	int mWeight;
	int mLeftConnectedNodeID;
	int mRightConnectedNodeID;
	void SetLeftConnectedNodeID(int id);
	void SetRightConnectedNodeID(int id);
	int GetWeight();
	int GetLeftConnectedNodeID();
	int GetRightConnectedNodeID();

	//constructor, destructor
	Edge(double startX, double startY, double endX, double endY);
	~Edge();
};

