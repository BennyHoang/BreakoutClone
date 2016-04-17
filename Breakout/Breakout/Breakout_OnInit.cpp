#include "Breakout.h"

bool Breakout::OnInit()
{

	bool success = true;


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
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{

				//Initialize SDL_ttf
				if (TTF_Init() == -1)
				{
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
					success = false;
				}

			}
		}
	}
	return success;
}

bool Breakout::LoadFont()
{
	bool success = true;
	gFont = TTF_OpenFont("sketchy.ttf", 20);
	gText.init(gFont, window, gRenderer);
	zFont = TTF_OpenFont("sketchy.ttf", 60);

	if (gFont == NULL && zFont == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	else
	{
		Score.ReadFile(file);
		SDL_Color textColor = { 255, 255, 255, 255 };
		gText.loadFromRenderedText("HIGHSCORE: ", textColor);
	}

	return success;

}