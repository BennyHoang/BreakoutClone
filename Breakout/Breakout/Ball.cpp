#include "Ball.h"




Ball::Ball(SDL_Window * window, SDL_Renderer * gRenderer, int x, int y, int color_r, int color_g, int color_b, int color_alpha)
{
	init(window, gRenderer, x, y, ball_heigth, ball_width, color_r, color_g, color_b, color_alpha);
	//setPos(1,1);
}

void Ball::updatePosition()
{
	setPos(getPosX() + m_vector_x, getPosY() + m_vector_y);
	SDL_Rect* this_rect = getRect();
	this_rect->x = getPosX();
	this_rect->y = getPosY();
}

void Ball::reset()
{
	setPos(SCREEN_WIDTH / 2, SCREEN_HEIGHT - 150);
	m_vector_x = 0;
	m_vector_y = 0;
}

void Ball::updateVector(int delta_x, int delta_y)
{
	m_vector_x += delta_x;
	m_vector_y += delta_y;
}

Ball::~Ball()
{
}
