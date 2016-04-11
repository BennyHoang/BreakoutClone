#include "Breakout.h"

void Breakout::OnRender() 
{
	//Get window surface
	screenSurface = SDL_GetWindowSurface(window);

	
	//Render red filled quad
	/*SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, 80, 20 };
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(gRenderer, &fillRect);*/

	//Ifen er bare for � teste
	if (!once)
	{
		rect();
		once = !once;
	}//end

	firkant1.setPos(posX, SCREEN_HEIGHT - 30);
	firkant1.setSize(100, 20);

	firkant1.update();
	firkant2.update();
	firkant3.update();
	//Fill the surface white
	//SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

	//Update the surface
	SDL_RenderPresent(gRenderer);
	//SDL_UpdateWindowSurface(window);
	

}

void Breakout::rect()
{
	firkant1.init(window, gRenderer, 20, 30, 20, 50, 00, 00, 255, 255);
	firkant2.init(window, gRenderer, 80, 30, 20, 50, 00, 00, 255, 255);
	firkant3.init(window, gRenderer, 140, 30, 20, 50, 00, 00, 255, 255);
}