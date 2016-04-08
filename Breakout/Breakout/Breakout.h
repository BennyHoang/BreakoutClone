#pragma once

#include <SDL.h>
#include <iostream>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

class Breakout {
private:
	bool Running;

	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;


public:
	Breakout();

	int OnExecute();

	bool OnInit();

	void OnEvent(SDL_Event* Event);

	void OnLoop();

	void OnRender();

	void OnCleanup();
};