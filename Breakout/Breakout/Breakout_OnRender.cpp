#include "Breakout.h"

void Breakout::OnRender() 
{
	//Get window surface
	screenSurface = SDL_GetWindowSurface(window);

	
	//Render red filled quad
	/*SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, 80, 20 };
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(gRenderer, &fillRect);*/

	//Ifen er bare for å teste
	if (!once)
	{
		rect();
		once = !once;
	}//end
	gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, (SCREEN_HEIGHT - gTextTexture.getHeight()) / 2);
	gText.render(0, 50);

	for each (Brick b in firstRow)
	{
		b.update();
	}	
	for each (Brick b in secondRow)
	{
		b.update();
	}	
	for each (Brick b in thirdRow)
	{
		b.update();
	}

	paddle->update();
	paddle->setPos(posX, paddle->getPosY());
	ball->update();
	ball->updatePosition();
	//text1.Render();
	/*
	firkant1.setPos(posX, SCREEN_HEIGHT - 30);
	firkant1.setSize(100, 20);

	firkant1.update();
	firkant2.update();
	firkant3.update();
	*/
	//Fill the surface white
	//SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

	//Update the surface
	SDL_RenderPresent(gRenderer);
	//SDL_UpdateWindowSurface(window);
	

}

void Breakout::rect()
{
	
	int width = 108;
	int space = 5;
	int heigth = 50;
	int heigth_from_top = 50;
	for (int i = 0; i < 9; i++)
	{
		Brick brick(window, gRenderer, space + (i * (width + space)), heigth_from_top, heigth, width, 00, 00, 255, 255);
		firstRow.push_back(brick);
	}

	heigth_from_top += 60;

	for (int i = 0; i < 9; i++)
	{
		Brick brick(window, gRenderer, space + (i * (width + space)), heigth_from_top, heigth, width, 00, 255, 00, 255);
		secondRow.push_back(brick);
	}
	heigth_from_top += 60;

	for (int i = 0; i < 9; i++)
	{
		Brick brick(window, gRenderer, space + (i * (width + space)), heigth_from_top, heigth, width, 255, 00, 00, 255);
		thirdRow.push_back(brick);
	}

	paddle = new Paddle(window, gRenderer, space + (1 * (width + space)), SCREEN_HEIGHT - 60, heigth, 300, 00, 179, 00, 255);
	ball = new Ball(window, gRenderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT - 70, 179, 179, 179, 255);
	

	

	/*
	firkant1.init(window, gRenderer, 20, 30, 20, 50, 00, 00, 255, 255);
	firkant2.init(window, gRenderer, 80, 30, 20, 50, 00, 00, 255, 255);
	firkant3.init(window, gRenderer, 140, 30, 20, 50, 00, 00, 255, 255);
	*/


}

