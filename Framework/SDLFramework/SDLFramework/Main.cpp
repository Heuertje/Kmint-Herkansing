#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include "IGameObject.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "Graph.h"
#include "Cow.h"
#include <random>
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
	std::random_device rd;     // only used once to initialise (seed) engine
	std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
	std::uniform_int_distribution<int> uni(0, 6); // guaranteed unbiased
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
					cow->setCurrentNode(firstGraph->getNodes().at(uni(rng)));
					break;
				}
			}
		}
		
		application->SetColor(Color(0, 0, 0, 255));
		application->DrawText("Welcome to Sagar & Bas KMINT Application", 400 ,20 );
	
		for (int i = 0; i < graphNodes.size(); i++)
		{
			application->DrawRect(graphNodes[i]->xPosition, graphNodes[i]->yPosition, graphNodes[i]->nodeHeight, graphNodes[i]->nodeHeight, graphNodes[i]->isFilled);

			if (graphNodes[i]->getEdges().size() != 0)
			{
				temporaryEdgesVector = graphNodes[i]->getEdges();

				//Drawing multiply edges added
				for (std::vector<Edge>::iterator edgeIt = temporaryEdgesVector.begin(); edgeIt != temporaryEdgesVector.end(); ++edgeIt)
				{
					application->DrawLine((int)edgeIt->startXPosition, (int)edgeIt->startYPosition, (int)edgeIt->endXPosition, (int)edgeIt->endYPosition);
				}
			}
		}

		////Start drawing
		//for (std::vector<Node*>::iterator it = graphNodes.begin(); it != graphNodes.end(); ++it)
		//{
		//	//Draw all nodes
		//	application->DrawRect((int)it->xPosition, (int)it->yPosition, (int)it->nodeWidth, (int)it->nodeHeight, it->isFilled);
		//	
		//	//If node has edges
		//	if (it->getEdges().size() !=0)
		//	{
		//		temporaryEdgesVector = it->getEdges();
		//		
		//		//Drawing multiply edges added
		//		for (std::vector<Edge>::iterator edgeIt = temporaryEdgesVector.begin(); edgeIt != temporaryEdgesVector.end(); ++edgeIt)
		//		{
		//			application->DrawLine((int)edgeIt->startXPosition, (int)edgeIt->startYPosition, (int)edgeIt->endXPosition, (int)edgeIt->endYPosition);
		//		}
		//	}
		//}

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
