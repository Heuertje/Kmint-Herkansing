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

	std::vector<Edge*> edges;

	

public:
	virtual void Draw();
	virtual void Update(float deltaTime) override;
	virtual void OnCollision(IGameObject * collidedObject) override;

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

	void setX(double x);
	void setY(double y);
	double getXPos();
	double getYPos();

	void setWidth(double width);
	void setHeight(double height);
	double getWidth();
	double getHeight();

	bool isFilled();

	std::vector<Edge*> getEdges();
	void addEdge(Edge*newEdge);

	void addNeighbor(Node*newNeighbor);
	int GetNodeID();
	void SetNodeID();
	void AddNeighbors(Node* neighbor);
	std::vector<Node*> GetNeighbors();
	std::vector<Node*> neighbors;
	std::vector<Edge*> edgesToNeighbors;
	std::vector<Edge*> Node::GetEdgesToNeighbors();

	//constructors, destructors
	Node();
	Node(int x, int y, int nodeID);
	~Node();
};

