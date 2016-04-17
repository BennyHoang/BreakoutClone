#include "Breakout.h"

void Breakout::OnRender()
{
	//Get window surface
	//screenSurface = SDL_GetWindowSurface(window);

	//gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, (SCREEN_HEIGHT - gTextTexture.getHeight()) / 2);
	//gText.render(0, 50);


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
	//SDL_UpdateWindowSurface(window);


}

