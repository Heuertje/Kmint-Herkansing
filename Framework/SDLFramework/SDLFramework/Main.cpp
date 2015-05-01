#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include "IGameObject.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "Graph.h"
#include "Cow.h"
//#include "vld.h"

Graph*firstGraph;
std::vector<Node> graphNodes;
std::vector<Edge> temporaryEdgesVector;

int main(int args[])
{
	//auto window = Window::CreateSDLWindow();
	FWApplication* application = new FWApplication();
	if (!application->GetWindow())
	{
		LOG("Couldn't create window...");
		return EXIT_FAILURE;
	}
	
	application->SetTargetFPS(60);
	application->SetColor(Color(255, 10, 40, 255));
	
	firstGraph = new Graph(application);
	graphNodes = firstGraph->getNodes();

//	Cow* cow = new Cow();

	//while (true){}
	while (application->IsRunning())
	{
		application->StartTick();

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				application->Quit();

				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym){
				case SDLK_ESCAPE:
					application->Quit();

					break;
				default:

					break;
				}
			}
		}
		
		application->SetColor(Color(0, 0, 0, 255));
		application->DrawText("Welcome to Andrew, Jeroen & Bas KMINT Application", 400 ,20 );
	
		//Start drawing
		for (std::vector<Node>::iterator it = graphNodes.begin(); it != graphNodes.end(); ++it)
		{
			//Draw all nodes
			application->DrawRect((int)it->xPosition, (int)it->yPosition, (int)it->nodeWidth, (int)it->nodeHeight, it->isFilled);
			
			//If node has edges
			if (it->getEdges().size() !=0)
			{
				temporaryEdgesVector = it->getEdges();
				
				//Drawing multiply edges added
				for (std::vector<Edge>::iterator edgeIt = temporaryEdgesVector.begin(); edgeIt != temporaryEdgesVector.end(); ++edgeIt)
				{
					application->DrawLine((int)edgeIt->startXPosition, (int)edgeIt->startYPosition, (int)edgeIt->endXPosition, (int)edgeIt->endYPosition);
				}
			}
<<<<<<< HEAD
			//application->DrawTexture(cow->cowTexture, it->xPosition, it->yPosition, 50, 50);
=======
>>>>>>> origin/newBranchTest
		}

		//uncommit this if cow has a node
		//cow->Draw();

		// For the background
		application->SetColor(Color(255, 255, 255, 255));

		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();
		
	}
	delete application;
	delete firstGraph;
	//delete cow;
	return EXIT_SUCCESS;
}
