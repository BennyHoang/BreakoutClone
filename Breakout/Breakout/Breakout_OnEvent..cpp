#include "Breakout.h"

void Breakout::OnEvent(SDL_Event* Event)
{
	if (Event->type == SDL_QUIT) {
		Running = false;
	}

	if (Event->key.keysym.sym == SDLK_LEFT ||
		Event->key.keysym.sym == SDLK_a) {
		posX -= 15;
		if (posX < 0) posX = 0;
	}

	if (Event->key.keysym.sym == SDLK_RIGHT ||
		Event->key.keysym.sym == SDLK_d) {
		posX += 15;
		if (posX > SCREEN_WIDTH - 30) posX = SCREEN_WIDTH - 30;
	}
}
