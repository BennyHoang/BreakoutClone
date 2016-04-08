#include "Breakout.h"

void Breakout::OnEvent(SDL_Event* Event)
{
	if (Event->type == SDL_QUIT) {
		Running = false;
	}
}
