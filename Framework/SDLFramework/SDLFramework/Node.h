#pragma once
#include <vector>
#include "Edge.h"
#include "IGameObject.h"
#include "FWApplication.h"
class Node : public IGameObject
{
private:

	double xPosition;
	double yPosition;
	double nodeHeight;
	double nodeWidth;
	bool filled;


	

public:
	virtual void Draw();
	virtual void Update(float deltaTime) override;
	virtual void OnCollision(IGameObject * collidedObject) override;


	
	std::vector<Edge*> edges;
	bool mIsStartingNode;
	bool mIsTargetNode;
	int amountOfEdgesChecked;
	bool mNodeHasBeenIterated;
	bool mIsGValueCalculated;
	bool isAddedToClosedList;
	bool isNodeVisited;
	int mGValue;
	int mHValue;
	int mFValue;
	int mNodeID;
	Node* mParentNode;
	Node();
	Node(int x, int y);
	~Node();

	void setX(double x);
	void setY(double y);
	double getXPos();
	double getYPos();

	void setWidth(double width);
	void setHeight(double height);
	double getWidth();
	double getHeight();

	bool isFilled();

	void addNeighbor(Node*newNeighbor);
	int GetNodeID();

	void addEdge(Edge*newEdge);
	std::vector<Edge*> getEdges();
	void AddNeighbors(Node* neighbor);
	std::vector<Node*> neighbors;
	std::vector<Edge*> edgesToNeighbors;
	std::vector<Edge*> Node::GetEdgesToNeighbors();
};

