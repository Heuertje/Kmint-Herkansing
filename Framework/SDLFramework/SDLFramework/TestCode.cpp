#include "TestCode.h"


TestCode::TestCode()
{
}


TestCode::~TestCode()
{
}



#include <vector>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

//enum for the status of a node
enum Status {
	NOT_VISITED,
	VISITED
};

//forward declaration
class Node;

//An object of this class represents an edge in the graph.
class Edge
{
private:
	Node *orgNode;//the originating vertex
	Node *dstNode;//the destination vertex
	unsigned cost;//cost of the edge
	int mLeftConnectedNodeID;
	int mLeftConnectedNodeID;
	int mRightConnectedNodeID;
	int mRightConnectedNodeID;
	int mWeight;
public:
	Edge(Node *firstNode, Node *secNode, unsigned inCost)
	{
		orgNode = firstNode;
		dstNode = secNode;
		cost = inCost;
	}

	Node* getDstNode()
	{
		return dstNode;
	}

	Node* getOrgNode()
	{
		return orgNode;
	}

	unsigned getCost()
	{
		return cost;
	}

	void SetLeftConnectedNodeID(int id)
	{
		throw std::logic_error("The method or operation is not implemented.");
	}


};

//An object of this class holds a vertex of the graph
class Node
{
private:
	string name;
	vector<Edge> adjNodeList;//list of outgoing edges for this vertex
	enum Status status;//used in dfs to mark the node visited

public:
	Node(string id)
	{
		name = id;
		status = NOT_VISITED;
	}

	//do not del the adj nodes here...they will be deleted by graph destructor
	~Node()
	{
		adjNodeList.clear();
	}

	enum Status getStatus()
	{
		return status;
	}

	void setStatus(enum Status st)
	{
		status = st;
	}

	string getName()
	{
		return name;
	}

	void addAdjNode(Node *adj, unsigned cost)
	{
		//create an edge with 'this' as the originating node and adj as the destination node
		Edge newEdge(this, adj, cost);
		adjNodeList.push_back(newEdge);
	}

	vector<Edge>& getAdjNodeList()
	{
		return adjNodeList;
	}

	//displays all adjacent verticies of this vertex
	void displayList()
	{
		string edgeOp = " -> ";
		for (int i = 0; i < adjNodeList.size(); i++)
		{
			Edge edg = adjNodeList[i];
			cout << name << " -> " << edg.getDstNode()->getName() << endl;
		}

	}
};

//An object of class graph holds a directed graph
class Graph
{
private:
	vector<Node*> nodeList;//list of verticies
	bool foundCycle;//true if a cycle is found, false otherwise
	int desiredCycSize;

	void clearVisited()
	{
		for (int i = 0; i < nodeList.size() && !foundCycle; i++)
		{
			nodeList[i]->setStatus(NOT_VISITED);
		}
	}

	void addNewNode(Node *nNode)
	{
		nodeList.push_back(nNode);
	}

	Node* findNodeByName(string name)
	{
		for (int i = 0; i < nodeList.size(); i++)
		{
			if (nodeList[i]->getName() == name)
				return nodeList[i];
		}
		return NULL;
	}

public:
	Graph()
	{
		foundCycle = false;
	}

	~Graph()
	{
		//free mem allocated to verticies
		for (int i = 0; i < nodeList.size(); i++)
			delete nodeList[i];
		nodeList.clear();
	}


	void displayGraph()
	{
		for (int i = 0; i < nodeList.size(); i++)
		{
			nodeList[i]->displayList();
		}
	}

	void readFlightSchedules() {

		unsigned numOfCities, numOfFlights, cycSize;
		//read in number of cities(TODO:in current implementation..not reqd), number of edges and the desired tour size
		cin >> numOfCities >> numOfFlights >> cycSize;

		while (numOfFlights--)
		{
			string fromCity, toCity;
			unsigned cost;

			cin >> fromCity >> toCity >> cost;
			//find if a vertex for the city already exists, if so get that
			Node *u = findNodeByName(fromCity);
			if (u == NULL)
			{
				u = new Node(fromCity);
				addNewNode(u);
			}

			//find if a vertex for the city already exists, if so get that
			Node *v = findNodeByName(toCity);
			if (v == NULL)
			{
				v = new Node(toCity);
				addNewNode(v);
			}

			u->addAdjNode(v, cost);
		}
		desiredCycSize = cycSize;
	}

};
