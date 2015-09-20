#include "Cow.h"

Cow::Cow(Node* newNode) : Animal(newNode)
{
	mTexture = mApplication->LoadTexture("cow-1.png");
}


void Cow::MoveCow(vector<Node*>* route){

	setCurrentNode(route->at(0));
	route->erase(route->begin(), route->begin() + 1);
}

void Cow::Update(float deltaTime)
{
	//m_pcurrentstate->execute.....
}
//void ChangeState(const State*pNewState){
//	delete m_pCurrentState;
//	m_pCurrentState = pNewState;
//}
void Cow::OnCollision(IGameObject * collidedObject)
{

}


Cow::~Cow()
{
	mApplication = nullptr;
	mApplication->RemoveTexture(mTexture);
}
