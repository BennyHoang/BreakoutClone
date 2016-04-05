#include <SDL.h>
#include <stdio.h>

bool init();

bool loadMedia();

void close();

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 400;


bool init()
{
	bool success = true;

	if(SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if(gWindow == NULL)
		{
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}
	return success;
}

bool loadMedia()
{
	bool success = true;
	gHelloWorld = SDL_LoadBMP("SDL_Test/hello_world.bmp");
	if(gHelloWorld == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "SDL_Test/hello_world.bmp", SDL_GetError());
		success = false;
	}
	return success;
}

void close()
{
	SDL_Surface(gHellowWorld);
	gHelloWorld = NULL;

	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	SDL_Quit();
}

int main(int argc, char* args[])
{
	if(!init())
	{
		printf("Failed to initialize!\n");

	}
	else
	{
		if(!loadMedia())
		{
			printf("failed to load media!\n");

		}
		else
		{
			SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
			SDL_UpdateWindowSurface(gWindow);
			SDL_Delay(2000);
		}
	}
	close();
	return 0;
}



























