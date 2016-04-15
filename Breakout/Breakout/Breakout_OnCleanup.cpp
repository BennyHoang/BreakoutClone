#include "Breakout.h"

void Breakout::OnCleanup() 
{
	SDL_DestroyWindow(window);

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(window);
	window = NULL;
	gRenderer = NULL;
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
	delete paddle;
	paddle = NULL;
	delete ball;
	ball = NULL;

}

