#pragma once
#include "Config.h"
#include "FWApplication.h"
#include "IGameObject.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "Graph.h"
class Animal : public IGameObject
{
	Node* currentNode;
public:
	Animal(Node* newNode);
	void setCurrentNode(Node* newCurrentNode);
	Node* getCurrentNode();

	//IgameObject methods
	virtual void Draw() override;
	virtual void Update(float deltaTime) override;
	virtual void OnCollision(IGameObject * collidedObject) override;
	void MoveCow(vector<Node*>* route);
	virtual ~Animal();
};

