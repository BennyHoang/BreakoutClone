#include "Breakout.h"

void Breakout::OnEvent(SDL_Event* Event)
{
	if (Event->type == SDL_QUIT) {
		Running = false;
	}

	if (Event->key.keysym.sym == SDLK_LEFT) {
		posX -= 1;
	}

	if (Event->key.keysym.sym == SDLK_RIGHT) {
		posX += 1;
	}
}
