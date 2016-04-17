#pragma once
#include "Square.h"
#include "Resource.h"

class Ball :
	public Square
{
public:
	Ball(SDL_Window * window, SDL_Renderer * gRenderer, int x, int y, int color_r, int color_g, int color_b, int color_alpha);
	void updatePosition();
	void reset();
	void updateVector(int x, int y);
	~Ball();

	const int ball_heigth = 10;
	const int ball_width = 10;
	int m_vector_x = 0; 
	int m_vector_y = 0;
};

