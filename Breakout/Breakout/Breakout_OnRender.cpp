#include "Breakout.h"

void Breakout::OnRender()
{

	if (GameState.getInMenu())
	{
		menu_screen.update();
	}
	
	if (GameState.getInGame())
	{
		gText.render(850, 0);
		level.updateLevel();
	}

	//Update the surface
	SDL_RenderPresent(gRenderer);


}

