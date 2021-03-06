#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include "Brick.h"
#include <vector>
#include "Paddle.h"
#include "Ball.h"
#include "TextService.h"
#include "Player.h"
#include "Resource.h"
#include "StateManager.h"

/*
	This level object handles loading initializor of levels and rendering.
	This object also updates the renderer position elements of the level.
	Level consist of Paddle, ball and bricks.

*/




class Level
{
public:
	Level();
	~Level();

	void LoadFirstLevel(SDL_Window * window, SDL_Renderer * gRenderer, TTF_Font* font, Player* player, StateManager* gameState);
	void loadLives();
	void updateLevel();
	void load();

	Ball* ball;
	Paddle* paddle;
	std::vector< std::vector<Brick> > rows;
	int bricks = 0;


private: 
	StateManager* m_game_state;
	TTF_Font* m_font;
	SDL_Renderer* m_renderer;
	SDL_Window* m_window;
	TextService gTextTextureHeader;
	Player* m_player;
	std::vector<Brick> row1, row2, row3;
	
};

