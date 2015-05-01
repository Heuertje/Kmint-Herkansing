#include "Mouse.h"

Mouse::Mouse()
{
	mTexture = mApplication->LoadTexture("rabbit-3.png");
}


void Mouse::Draw()
{

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
