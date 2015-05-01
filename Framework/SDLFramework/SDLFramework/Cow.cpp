#include "Cow.h"

Cow::Cow()
{
	mTexture = mApplication->LoadTexture("cow-1.png");
}

void Cow::Draw()
{
	
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
