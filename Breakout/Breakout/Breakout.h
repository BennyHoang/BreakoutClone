#pragma once

#include <SDL.h>
#include <iostream>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

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

public:

	bool OnInit();

	void OnEvent(SDL_Event* Event);

	void OnLoop();

	void OnRender();

	void OnCleanup();
};