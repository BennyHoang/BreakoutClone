#include "Paddle.h"


Paddle::Paddle(SDL_Window * window, SDL_Renderer * gRenderer, int x, int y, int height, int width, int color_r, int color_g, int color_b, int color_alpha)
{
	init(window, gRenderer, x, y, height, width, color_r, color_g, color_b, color_alpha);
}

Paddle::~Paddle()
{
	std::cout << "ptrDeleted" << std::endl;
}
