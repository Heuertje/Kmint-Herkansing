#pragma once
#include <vector>
#include "Edge.h"
#include "IGameObject.h"
#include "FWApplication.h"
class Node : public IGameObject
{
private:
	


	

public:
	virtual void Draw();
	virtual void Update(float deltaTime) override;
	virtual void OnCollision(IGameObject * collidedObject) override;


	double xPosition;
	double yPosition;
	double nodeHeight;
	double nodeWidth;
	bool isFilled;
	
	std::vector<Node> neighbours;
	std::vector<Edge> edges;
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

	void setWidth(double width);

	void setHeight(double height);

	void addNeighbour(Node*newNeighbour);

	void addEdge(Edge*newEdge);
	std::vector<Edge> getEdges();
};

