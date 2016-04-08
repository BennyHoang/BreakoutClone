#include "Breakout.h"

bool Breakout::OnInit()
{
	/*if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return false;
	}

	if ((Surf_Display = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
		return false;
	}*/

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}

	else
	{
		//Create window
		window = SDL_CreateWindow("Breakout Gruppe 6", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}

	}
	return true;
}