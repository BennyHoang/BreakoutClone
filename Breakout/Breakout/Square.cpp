#include "Square.h"

Square::Square()
{

}

Square::~Square()
{
}

void Square::init(SDL_Window* window, SDL_Renderer* gRenderer, int x, int y, int height, int width, int color_r, int color_g, int color_b, int color_alpha)
{
	m_window = window;
	m_gRenderer = gRenderer;

	setSize(width, height);
	setColor(color_r, color_g, color_b, color_alpha);
	setPos(x, y);
	rect.h = height;
	rect.w = width;
	rect.x = x;
	rect.y = y;
	
}

void Square::setPos(int posX, int posY)
{
	m_x = posX;
	m_y = posY;
}

void Square::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 opacity)
{
	m_color_r = r;
	m_color_g = g;
	m_color_b = b;
	m_color_alpha = opacity;
}

void Square::setSize(int width, int height)
{
	m_width = width;
	m_height = height;
}

int Square::getPosX()
{
	return m_x;
}

int Square::getPosY()
{
	return m_y;
}

SDL_Rect * Square::getRect()
{
	return  &rect;
}

void Square::update()
{
	SDL_Rect fillRect = { m_x, m_y, m_width, m_height };
	SDL_SetRenderDrawColor(m_gRenderer, m_color_r, m_color_g, m_color_b, m_color_alpha);
	SDL_RenderFillRect(m_gRenderer, &fillRect);
}
