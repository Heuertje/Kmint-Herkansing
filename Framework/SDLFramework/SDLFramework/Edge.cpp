#include "Edge.h"


Edge::Edge()
{
	FWApplication* application = FWApplication::GetInstance();
}
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

void Edge::SetLeftConnectedNodeID(int id)
{
	mLeftConnectedNodeID = id;
}

void Edge::SetRightConnectedNodeID(int id)
{
	mRightConnectedNodeID = id;

}

int Edge::GetLeftConnectedNodeID()
{
	return mLeftConnectedNodeID;
}

int Edge::GetRightConnectedNodeID()
{
	return mRightConnectedNodeID;
}


void Edge::Draw()
{
	FWApplication::GetInstance()->DrawLine(startXPosition, startYPosition, endXPosition, endYPosition);
}

void Edge::Update(float deltaTime){}
void Edge::OnCollision(IGameObject * collidedObject){}

Edge::~Edge()
{

}