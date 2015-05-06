#include "Node.h"
#include "Edge.h"

Node::Node()
{
	
}

Node::Node( int x, int y)
{
	xPosition = x;
	yPosition = y;
	nodeWidth = 10;
	nodeHeight = 10;
	isFilled = true;

	mIsStartingNode = false;
	mIsTargetNode = false;
	amountOfEdgesChecked = 0;
	mNodeHasBeenIterated = false;
	mIsGValueCalculated = false;
	isAddedToClosedList = false;
	isNodeVisited = false;
}

Node::~Node()
{
	for (Edge* var : edges)
	{
		delete var;
	}
	edges.clear();
}

void Node::setX(double x)
{
	xPosition = x;
}

void Node::setY(double y)
{
	yPosition = y;
}

void Node::setWidth(double width)
{
	nodeWidth = width;
}

void Node::setHeight(double height)
{
	nodeHeight = height;
}

void Node::addNeighbor(Node*newNeighbor)
{
	neighbors.push_back(newNeighbor);
}

void Node::addEdge(Edge*newEdge)
{
	edges.push_back(newEdge);
}

std::vector<Edge*> Node::getEdges()
{
	return edges;
}

int Node::GetNodeID(){
	return mNodeID;
}

std::vector<Edge*> Node::GetEdgesToNeighbors()
{
	return edgesToNeighbors;
}

void Node::AddNeighbors(Node* neighbor)
{
	//create a new edge that will connect the 'this' node with the 'neighbor' node
	auto edge = new Edge(
		this->GetBoundingBox().x,
		this->GetBoundingBox().y,
		neighbor->GetBoundingBox().x,
		neighbor->GetBoundingBox().y
		);

	edge->SetLeftConnectedNodeID(this->GetNodeID());
	edge->SetRightConnectedNodeID(neighbor->GetNodeID());

	//add the new edge to 'this' nodes' neiboringEdge list
	edgesToNeighbors.push_back(edge);

	//ALSO add the new edge to the neigboringEdge list of the 'neighbor'
	neighbor->edgesToNeighbors.push_back(edge);


	//now add the actual neighbor to this nodes neighbor list
	neighbors.push_back(neighbor);


	//Very important! Now add the current node to the list of the neighbor!
	//This makes sure that connecting nodes always have a two-sided connection!
	neighbor->neighbors.push_back(this);



	mApplication->AddRenderable(edge);


}

void Node::Draw(){
	//#TestDraw
	mApplication->SetColor(Color(100, 0, 200, 255));
	mApplication->DrawLine(0,0, 500,500);
	//#endTestDraw

}
void Node::Update(float deltaTime){}
void Node::OnCollision(IGameObject * collidedObject){}