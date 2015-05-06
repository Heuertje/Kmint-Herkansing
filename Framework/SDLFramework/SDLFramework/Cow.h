#pragma once
#include "Config.h"
#include "FWApplication.h"
#include "IGameObject.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "Graph.h"
class Cow : public IGameObject
{
private:
	Node* currentNode;

public:
	void setCurrentNode(Node* newCurrentNode);
	Node* getCurrentNode();

	//IgameObject methodes
	virtual void Draw() override;
	virtual void Update(float deltaTime) override;
	virtual void OnCollision(IGameObject * collidedObject) override;


	Cow(Node* newNode);
	virtual ~Cow();
};

