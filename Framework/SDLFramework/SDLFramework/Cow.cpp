#include "Cow.h"

Cow::Cow(Node* newNode)
{
	currentNode = newNode;
	mTexture = mApplication->LoadTexture("cow-1.png");
	mWidth = 50;
	mHeight = 50;
}

void Cow::setCurrentNode(Node* newCurrentNode)
{
	currentNode = newCurrentNode;
}

Node* Cow::getCurrentNode()
{
	return currentNode;
}

void Cow::Draw()
{
	mApplication->DrawTexture(mTexture, currentNode->getXPos(), currentNode->getYPos(), mWidth, mHeight);
}

void Cow::Update(float deltaTime)
{

}

void Cow::OnCollision(IGameObject * collidedObject)
{

}


Cow::~Cow()
{
	mApplication = nullptr;
	mApplication->RemoveTexture(mTexture);
}
