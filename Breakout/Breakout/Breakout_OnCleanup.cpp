#include "Breakout.h"

void Breakout::OnCleanup() 
{
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();

}