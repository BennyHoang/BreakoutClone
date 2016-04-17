#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "Square.h"
#include "TextService.h"
#include "ScoreManager.h"
#include <cmath>
#include <vector>
#include "Brick.h"
#include "Paddle.h"
#include "Ball.h"
#include "CollisionManager.h"
#include "Level.h"
#include "StateManager.h"
#include "Menu.h"
#include "Resource.h"
#include "LTimer.h"
/*
 This is the main object.
 In this object you will also find main.
 This object is split into 6 .cpp files
*/


class Breakout {
private:
	bool Running;

	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;


	//The window renderer
	SDL_Renderer* gRenderer = NULL;

	TTF_Font* gFont;
	TTF_Font* zFont;

	//TextService gTextTexture;
	TextService gText;
	TextService gTextLives;

	Menu menu_screen;

	Player player;

	StateManager GameState;

	int posX = 140;

	CollisionManager collisionManager;
	std::string file = "highscore.txt";
	ScoreManager Score;
	int score = 0;
	Level level;

	const int SCREEN_FPS = 60;
	const int SCREEN_TICK_PER_FRAME = 1000 / SCREEN_FPS;

	//The frames per second timer
	LTimer fpsTimer;

	//The frames per second cap timer
	LTimer capTimer;

	//Start counting frames per second
	int countedFrames = 0;


public:
	Breakout();

	int OnExecute();

	bool OnInit();

	void OnEvent(SDL_Event* Event);

	void OnLoop();

	void OnRender();

	void OnCleanup();

	bool LoadFont();
};