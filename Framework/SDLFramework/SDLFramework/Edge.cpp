#include "Edge.h"

Edge::Edge(double startX, double startY, double endX, double endY)
{
	 startXPosition = startX;
	 startYPosition = startY;

	 endXPosition = endX;
	 endYPosition = endY;
	 mWeight = 1000;
}

int Edge::GetWeight()
{
	return mWeight;
}

void Edge::SetLeftConnectedNode(Node* node)
{
	mLeftConnectedNode = node;
}

void Edge::SetRightConnectedNode(Node* neighbourNode)
{
	mRightConnectedNode = neighbourNode;

}

Node* Edge::GetLeftConnectedNode()
{
	return mLeftConnectedNode;
}

Node* Edge::GetRightConnectedNode()
{
	return mRightConnectedNode;
}


void Edge::Draw()
{
	
	FWApplication::GetInstance()->DrawLine(startXPosition, startYPosition, endXPosition, endYPosition);
}

void Edge::Update(float deltaTime)
{
	
}

void Edge::OnCollision(IGameObject * collidedObject)
{
	
}

Edge::~Edge()
{

}