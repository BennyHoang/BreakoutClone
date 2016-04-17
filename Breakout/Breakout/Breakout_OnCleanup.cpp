#include "Breakout.h"

void Breakout::OnCleanup() 
{
	SDL_DestroyWindow(window);

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(window);
	window = NULL;
	gRenderer = NULL;
	
	//Closing font
	//gTextTexture.free();
	gText.free();
	gTextLives.free();
	TTF_CloseFont(gFont);
	TTF_CloseFont(zFont);
	zFont = NULL;
	gFont = NULL;
	
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
	level.~Level();
	TTF_Quit();

}


