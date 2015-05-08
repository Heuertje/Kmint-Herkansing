#include "Mouse.h"
#include <random>
#include <iostream>

Mouse::Mouse(){};
Mouse::Mouse(Node* newNode)
{
	currentNode = newNode;
	mTexture = mApplication->LoadTexture("pill.png");
	mWidth = 50;
	mHeight = 50;
}

void Mouse::setCurrentNode(Node* newCurrentNode)
{
	currentNode = newCurrentNode;
}

Node* Mouse::getCurrentNode()
{
	return currentNode;
}

void Mouse::Draw()
{
	mApplication->DrawTexture(mTexture, currentNode->getXPos(), currentNode->getYPos(), mWidth, mHeight);
}
void Mouse::MoveMouse(Graph* firstGraph, Cow* cow){
	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uni(0, 6); // guaranteed unbiased
	//uni(rng)

	currentNode = getCurrentNode()->GetEdgesToNeighbors().at(0)->GetLeftConnectedNode();
	//firstGraph->ASter(this->getCurrentNode(), cow->getCurrentNode());

	//setCurrentNode(firstGraph->ASter(this->getCurrentNode(), cow->getCurrentNode())->at(0));
}

void Mouse::MoveLeft()
{
	Node* newNode = getCurrentNode()->GetEdgesToNeighbors().at(0)->getOtherNode(currentNode);
	if (newNode == nullptr)
	{
		std::cout << "node not existing" << endl;
	}
	else 
	{
		currentNode = getCurrentNode()->GetEdgesToNeighbors().at(0)->getOtherNode(currentNode);
	}
}

void Mouse::MoveRight()
{
	Node* newNode = getCurrentNode()->GetEdgesToNeighbors().at(1)->getOtherNode(currentNode);
	if (newNode == nullptr)
	{
		std::cout << "node not existing" << endl;
	}
	else {
		currentNode = getCurrentNode()->GetEdgesToNeighbors().at(1)->getOtherNode(currentNode);
	}
}

void Mouse::MoveMiddle()
{
	if (currentNode->GetEdgesToNeighbors().size() < 3)
	{
		std::cout << "node only connected to 2 edges" << endl;
	}
	else 
	{
		Node* newNode = getCurrentNode()->GetEdgesToNeighbors().at(2)->getOtherNode(currentNode);
		if (newNode == nullptr)
		{
			std::cout << "node not existing" << endl;
		}
		else
		{
			currentNode = getCurrentNode()->GetEdgesToNeighbors().at(2)->getOtherNode(currentNode);
		}
	}

}

void Mouse::PrintNodeNeighbours()
{
	for (size_t i = 0; i < currentNode->GetEdgesToNeighbors().size(); i++)
	{
		std::cout << "right connected" << currentNode->GetEdgesToNeighbors().at(i)->getOtherNode(currentNode)->GetNodeID() << std::endl;
	}

	for (size_t i = 0; i < currentNode->GetEdgesToNeighbors().size(); i++)
	{
		std::cout << "left connected" << currentNode->GetEdgesToNeighbors().at(i)->getOtherNode(currentNode)->GetNodeID() << std::endl;
	}
	std::cout << endl<<endl;
}

void Mouse::Update(float deltaTime)
{

}

void Mouse::OnCollision(IGameObject * collidedObject)
{

}


Mouse::~Mouse()
{
	mApplication = nullptr;
	mApplication->RemoveTexture(mTexture);
}
