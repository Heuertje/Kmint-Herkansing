#include "Graph.h"
#include "Node.h"
#include "Edge.h"
#include <map>
using namespace std;

Graph::Graph(FWApplication* application)
{ 

	// initialize nodes
	Node* node1 = new Node(100, 80, 0);
	Node* node2 = new Node(220, 110, 1);
	Node* node3 = new Node(180, 230, 2);
	Node* node4 = new Node(300, 160, 3);
	Node* node5 = new Node(430, 530, 4);
	Node* node6 = new Node(520, 320, 5);
	Node* node7 = new Node(100, 320, 6);
	Node* node8 = new Node(30, 30, 7);
	Node* node9 = new Node(30, 100, 8);
	Node* node10 = new Node(110, 30, 9);

	node10->AddNeighbors(node2);
	node8->AddNeighbors(node10);
	node1->AddNeighbors(node10);
	node1->AddNeighbors(node9);
	node8->AddNeighbors(node9);
	node1->AddNeighbors(node8);
	node1->AddNeighbors(node2);
	node2->AddNeighbors(node3);
	node3->AddNeighbors(node4);
	node3->AddNeighbors(node5);
	node4->AddNeighbors(node6);
	node5->AddNeighbors(node6);
	node2->AddNeighbors(node4);
	node1->AddNeighbors(node7);
	node7->AddNeighbors(node5);


	//add all nodes into a vector for future iterations
	nodes.push_back(node1);
	nodes.push_back(node2);
	nodes.push_back(node3);
	nodes.push_back(node4);
	nodes.push_back(node5);
	nodes.push_back(node6);
	nodes.push_back(node7);
	nodes.push_back(node8);
	nodes.push_back(node9);
	nodes.push_back(node10);

}

void Graph::Draw(){}
void Graph::Update(float deltaTime){}
void Graph::OnCollision(IGameObject * collidedObject){}

vector<Node*>* Graph::ASter(Node* start, Node* goal){
	std::map<Node*, double> openlist;
	std::vector<Node*>* closedlist = new std::vector<Node*>();

	openlist[start] = 0.0;
	Node* current = start;

	closedlist->push_back(current);

	double weighttillnow = 0;

	while (current != goal){
		for (Edge* e : current->GetEdgesToNeighbors()){
			if (find(closedlist->begin(), closedlist->end(), e->getOtherNode(current)) == closedlist->end()){
				int g = weighttillnow + e->GetWeight();
				int h = DistanceToNode(goal, e->getOtherNode(current));
				int f = g + h;

				openlist[e->getOtherNode(current)] = f;
			}
		}

		Node* kortstenode = nullptr;
		for (pair<Node*, double> mapPair : openlist){
			if (kortstenode == nullptr || mapPair.second < openlist[kortstenode]){
				kortstenode = mapPair.first;
			}
		}
		for (size_t i = 0; i < current->GetEdgesToNeighbors().size(); i++){
			if (current->GetEdgesToNeighbors().at(i)->getOtherNode(goal) == kortstenode){
				weighttillnow += current->GetEdgesToNeighbors().at(i)->GetWeight();
				break;
			}
		}

		current = kortstenode;
			closedlist->push_back(current);

			openlist = map<Node*, double>();
	
	}
	while (start == closedlist->at(0)){
		closedlist->erase(closedlist->begin(), closedlist->begin() + 1);
	}

//	cout << "Closedlist lengte:    " << closedlist->size() << endl;
	return closedlist;
}


Graph::~Graph()
{
	for (Node* var : nodes)
	{
		delete var;
	}
	nodes.clear();
}

double Graph::DistanceToNode(Node* goal, Node* child){
	return sqrt(pow(goal->getXPos() - child->getXPos(), 2) + pow(goal->getYPos() - child->getYPos(), 2));
}

std::vector<Node*> Graph::getNodes()
{
	return nodes;
}


