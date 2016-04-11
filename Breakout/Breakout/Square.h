#pragma once

#include "SDL.h"


class Square
{
public:
	Square();
	~Square();
	void init(SDL_Window * window, SDL_Renderer * gRenderer, int x, int y, int height, int width, int color_r, int color_g, int color_b, int color_alpha);
	void setPos(int posX, int posY);
	void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 opacity);
	void setSize(int width, int height);
	int getPosX();
	int getPosY();
	void update();

private:

	int m_x, m_y;
	int	m_height, m_width;
	Uint8 m_color_r, m_color_g, m_color_b, m_color_alpha;


	SDL_Window* m_window = NULL;
	SDL_Renderer* m_gRenderer = NULL;

};

