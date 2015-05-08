#include "Mouse.h"
#include <random>
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
	setCurrentNode(firstGraph->ASter(this->getCurrentNode(), cow->getCurrentNode())->at(0));
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
