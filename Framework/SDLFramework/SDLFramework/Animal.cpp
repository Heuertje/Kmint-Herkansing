#include "Animal.h"


Animal::Animal(Node* newNode)
{
	currentNode = newNode;
	mWidth = 50;
	mHeight = 50;
}



void Animal::setCurrentNode(Node* newCurrentNode)
{
	currentNode = newCurrentNode;
}

Node* Animal::getCurrentNode()
{
	return currentNode;
}

void Animal::Draw()
{
	mApplication->DrawTexture(mTexture, (int)currentNode->getXPos(), (int)currentNode->getYPos(), mWidth, mHeight);
}


Animal::~Animal()
{
}
