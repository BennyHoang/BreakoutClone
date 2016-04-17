#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include "Brick.h"
#include <vector>
#include "Paddle.h"
#include "Ball.h"
//#include "Breakout.h"




class Level
{
public:
	Level();
	~Level();

	void LoadFirstLevel(SDL_Window * window, SDL_Renderer * gRenderer);

	//void load(SDL_Window * window, SDL_Renderer * gRenderer, std::vector<std::vector<Brick>> rows, Ball & ball, Paddle * paddle);

	void load(SDL_Window * window, SDL_Renderer * gRenderer);
	std::vector<Brick> row1, row2, row3;
	std::vector< std::vector<Brick> > rows;
	Ball* ball;
	Paddle* paddle;
	int bricks = 0;
	int SCREEN_HEIGHT = 768;
	int SCREEN_WIDTH = 1024;
};

