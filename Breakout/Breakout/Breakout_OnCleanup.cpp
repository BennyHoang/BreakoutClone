#include "Breakout.h"

void Breakout::OnCleanup() 
{
	SDL_DestroyWindow(window);

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(window);
	window = NULL;
	gRenderer = NULL;
	
	//Closing font
	gTextTexture.free();
	TTF_CloseFont(gFont);
	gFont = NULL;
	
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
	TTF_Quit();

}


