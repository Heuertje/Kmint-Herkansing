#include "Cow.h"

Cow::Cow()
{
	mTexture = mApplication->LoadTexture("cow-1.png");
	mWidth = 50;
	mHeight = 50;
}

void Cow::setCurrentNode(Node* newCurrentNode)
{
	currentNode = newCurrentNode;
}

void Cow::Draw()
{
	mApplication->DrawTexture(mTexture, currentNode->xPosition, currentNode->yPosition, mWidth, mHeight);
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
