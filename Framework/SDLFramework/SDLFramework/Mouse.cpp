#include "Mouse.h"
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
