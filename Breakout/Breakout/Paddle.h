#pragma once
#include "Square.h"
#include <iostream>
class Paddle :
	public Square
{
public:
	Paddle(SDL_Window * window, SDL_Renderer * gRenderer, int x, int y, int height, int width, int color_r, int color_g, int color_b, int color_alpha);
	~Paddle();
};

