#pragma once

#include <SDL.h>
#include <iostream>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "Square.h"
#include <cmath>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

class Breakout {
private:
	bool Running;

	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;


	//The window renderer
	SDL_Renderer* gRenderer = NULL;

	Square firkant1;
	Square firkant2;
	Square firkant3;

	bool once = false;

	int posX = 140;

public:
	Breakout();

	int OnExecute();

	bool OnInit();

	SDL_Texture * loadTexture(std::string path);

	void OnEvent(SDL_Event* Event);

	void OnLoop();

	void OnRender();

	void rect();

	void OnCleanup();
};