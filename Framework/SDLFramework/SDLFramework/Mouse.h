#pragma once
#include "Config.h"
#include "IGameObject.h"
#include "FWApplication.h"
#include "Node.h"

class Mouse : public IGameObject
{
private:
	Node* currentNode;

public:
	void setCurrentNode(Node* newCurrentCode);
	Node* getCurrentNode();


	virtual void Draw() override;
	virtual void Update(float deltaTime) override;
	virtual void OnCollision(IGameObject * collidedObject) override;

	Mouse();
	virtual ~Mouse();
};

