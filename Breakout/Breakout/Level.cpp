#include "Level.h"



Level::Level()
{
}


Level::~Level()
{
	delete paddle;
	paddle = NULL;
	delete ball;
	ball = NULL;
}

void Level::LoadFirstLevel(SDL_Window* window, SDL_Renderer* gRenderer)
{
	int width = 108;
	int space = 5;
	int heigth = 50;

	load(window, gRenderer);

	paddle = new Paddle(window, gRenderer, space + (1 * (width + space)), SCREEN_HEIGHT - 60, heigth, 300, 00, 179, 00, 255);
	ball = new Ball(window, gRenderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT - 70, 179, 179, 179, 255);
}

void Level::load(SDL_Window* window, SDL_Renderer* gRenderer)
{
	int width = 108;
	int space = 5;
	int heigth = 50;
	int heigth_from_top = 50;

	rows.clear();
	row1.clear();
	row2.clear();
	row3.clear();
	bricks = 3 * 9;

	for (int i = 0; i < 9; i++)
	{
		Brick brick(window, gRenderer, space + (i * (width + space)), heigth_from_top, heigth, width, 00, 00, 255, 255);
		row1.push_back(brick);
	}

	heigth_from_top += 60;

	for (int i = 0; i < 9; i++)
	{
		Brick brick(window, gRenderer, space + (i * (width + space)), heigth_from_top, heigth, width, 00, 255, 00, 255);
		row2.push_back(brick);
	}
	heigth_from_top += 60;

	for (int i = 0; i < 9; i++)
	{
		Brick brick(window, gRenderer, space + (i * (width + space)), heigth_from_top, heigth, width, 255, 00, 00, 255);
		row3.push_back(brick);
	}

	rows.push_back(row1);
	rows.push_back(row2);
	rows.push_back(row3);
}
