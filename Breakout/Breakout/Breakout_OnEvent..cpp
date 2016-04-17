#include "Breakout.h"

void Breakout::OnEvent(SDL_Event* Event)
{
	if (Event->type == SDL_QUIT) {
		Running = false;
	}
	if (Event->type == SDL_KEYDOWN)
	{

		if (GameState.getInGame())
		{
			if (Event->key.keysym.sym == SDLK_LEFT ||
				Event->key.keysym.sym == SDLK_a) {
				posX -= 30;
				if (posX < 0) posX = 0;
				return;
			}

			if (Event->key.keysym.sym == SDLK_RIGHT ||
				Event->key.keysym.sym == SDLK_d) {
				posX += 30;
				if (posX > SCREEN_WIDTH - 300) posX = SCREEN_WIDTH - 300;
				return;
			}

			if (Event->key.keysym.sym == SDLK_SPACE && GameState.canShoot())
			{
				level.ball->updateVector(0, 1);
				return;
			}
		}




		if (GameState.getInMenu())
		{
			if (Event->key.keysym.sym == SDLK_p)
			{
				GameState.setInMenu(false);
				GameState.setFirstLevel(true);
				GameState.setInGame(true);
			}
		}
	}

	//SDL_PumpEvents();
}
