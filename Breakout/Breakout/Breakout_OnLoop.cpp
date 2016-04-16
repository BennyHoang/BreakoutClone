#include "Breakout.h"

void Breakout::OnLoop()
{
	//Clear screen
	SDL_SetRenderDrawColor(gRenderer, 0x02, 0x02, 0x02, 0xFF);
	SDL_RenderClear(gRenderer);

	if (load_lvl_one)
	{
		level.load(window, gRenderer);
		load_lvl_one = false;
	}

	level.paddle->setPos(posX, level.paddle->getPosY());
	level.ball->updatePosition();


}