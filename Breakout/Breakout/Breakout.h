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


#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

/*Text Defines*/
#define TXT_HIGHSCORE "Highscore"

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
/*
	Square firkant1;
	Square firkant2;
	Square firkant3;
*/
	TextService gTextTexture;
	TextService gText;
	TextService gTextLives;

	Menu menu_screen;

	Player player;

	StateManager GameState;

	bool once = false;

	int posX = 140;
	bool load_lvl_one = true;


	CollisionManager collisionManager;
	std::string file = "highscore.txt";
	ScoreManager Score;
	int score = 0;
	Level level;

public:
	Breakout();

	int OnExecute();

	bool OnInit();

	SDL_Texture * loadTexture(std::string path);

	void OnEvent(SDL_Event* Event);

	void OnLoop();

	void OnRender();

	void OnCleanup();

	bool LoadFont();
};