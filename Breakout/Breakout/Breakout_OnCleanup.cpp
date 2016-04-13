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

bool Breakout::LoadFont()
{
	gFont = TTF_OpenFont("sketchy.ttf", 20);
	if(gFont == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		return false;
	}else
	{
		SDL_Color textColor = { 0, 0, 0 };
		if (!gTextTexture.loadFromRenderedText("the text", textColor))
		{
			printf("Failed to render text texture!\n");
			return false;
		}
	}

	return true;
		
}
