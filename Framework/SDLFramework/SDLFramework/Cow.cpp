#include "Cow.h"

Cow::Cow()
{
	init();
}

void Cow::init()
{
	application = FWApplication::GetInstance();
	cowTexture = application->LoadTexture("cow-1.png");
}

Cow::~Cow()
{
	application = nullptr;
	SDL_DestroyTexture(cowTexture);
}
