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
std::vector<Node*> graphNodes;
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

	Cow* cow = new Cow(firstGraph->getNodes().at(2));

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
				case SDLK_SPACE:
					cow->setCurrentNode(firstGraph->getNodes().at(5));
					break;
				}
			}
		}
		
		application->SetColor(Color(0, 0, 0, 255));
		application->DrawText("Welcome to Andrew, Jeroen & Bas KMINT Application", 400 ,20 );
	
		for (int i = 0; i < graphNodes.size(); i++)
		{
			application->DrawRect(graphNodes[i]->getXPos(), graphNodes[i]->getYPos(), graphNodes[i]->getHeight(), graphNodes[i]->getHeight(), graphNodes[i]->isFilled());

			if (graphNodes[i]->getEdges().size() != 0)
			{
				for (int j = 0; j < graphNodes[i]->getEdges().size(); j++)
				{
					application->DrawLine(graphNodes[i]->getEdges().at(j)->startXPosition, graphNodes[i]->getEdges().at(j)->startYPosition, graphNodes[i]->getEdges().at(j)->endXPosition, graphNodes[i]->getEdges().at(j)->endYPosition);
				}

				//temporaryEdgesVector = graphNodes[i]->getEdges();
				//
				////Drawing multiply edges added
				//for (std::vector<Edge>::iterator edgeIt = temporaryEdgesVector.begin(); edgeIt != temporaryEdgesVector.end(); ++edgeIt)
				//{
				//	application->DrawLine((int)edgeIt->startXPosition, (int)edgeIt->startYPosition, (int)edgeIt->endXPosition, (int)edgeIt->endYPosition);
				//}
			}
		}

		//uncommit this if cow has a node
		cow->Draw();

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
