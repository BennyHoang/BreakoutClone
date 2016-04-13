#include "Breakout.h"

void Breakout::OnCleanup() 
{
	SDL_DestroyWindow(window);

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(window);
	window = NULL;
	gRenderer = NULL;
	//Quit SDL subsystems
	TTF_CloseFont(m_font);
	IMG_Quit();
	SDL_Quit();

}

