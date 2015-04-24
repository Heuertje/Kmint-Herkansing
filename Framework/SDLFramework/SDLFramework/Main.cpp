#include <iostream>
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <time.h>
#include "Graph.h"
//#include "vld.h"

Graph*firstGraph;
std::vector<Node> graphNodes;
std::vector<Edge> temporaryEdgesVector;
SDL_Texture*catTexture;

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
	
	firstGraph = new Graph();
	graphNodes = firstGraph->getNodes();
	

	catTexture = application->LoadTexture("cow-1.png");

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
	
		
		for (std::vector<Node>::iterator it = graphNodes.begin(); it != graphNodes.end(); ++it)
		{
			application->DrawRect((int)it->xPosition, (int)it->yPosition, (int)it->nodeWidth, (int)it->nodeHeight, it->isFilled);
			
			if (it->getEdges().size() !=0)
			{
				temporaryEdgesVector = it->getEdges();
				
				//Drawing multiply edges added
				for (std::vector<Edge>::iterator edgeIt = temporaryEdgesVector.begin(); edgeIt != temporaryEdgesVector.end(); ++edgeIt)
				{
					application->DrawLine((int)edgeIt->startXPosition, (int)edgeIt->startYPosition, (int)edgeIt->endXPosition, (int)edgeIt->endYPosition);
				}
			}
		
			application->DrawTexture(catTexture, it->xPosition, it->yPosition, 50, 50);
		}
		

		

		// For the background
		application->SetColor(Color(255, 255, 255, 255));

		application->UpdateGameObjects();
		application->RenderGameObjects();
		application->EndTick();
		

		
	}
	delete application;
	delete firstGraph;
	return EXIT_SUCCESS;
}
