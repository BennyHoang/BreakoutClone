#include "Breakout.h"

void Breakout::OnRender() 
{
	//Get window surface
	//screenSurface = SDL_GetWindowSurface(window);

	//gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, (SCREEN_HEIGHT - gTextTexture.getHeight()) / 2);
	//gText.render(0, 50);

	level.paddle->update();
	level.ball->update();

	for (int i = 0; i < level.rows.size(); i++)
		for (int e = 0; e < level.rows[i].size(); e++)
			level.rows[i][e].update();


	//Update the surface
	SDL_RenderPresent(gRenderer);
	//SDL_UpdateWindowSurface(window);
	

}

