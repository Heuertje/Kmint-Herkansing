#pragma once
#include "Config.h"
#include "FWApplication.h"
#include <SDL_events.h>
#include "SDL_timer.h"
#include <SDL.h>
#include <time.h>
#include "Graph.h"
class Cow
{
public:
	FWApplication* application;
	SDL_Texture* cowTexture;

	Cow();
	void init();
	virtual ~Cow();
};

