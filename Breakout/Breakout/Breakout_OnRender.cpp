#include "Breakout.h"

void Breakout::OnRender() 
{
	//Get window surface
	//screenSurface = SDL_GetWindowSurface(window);

	
	//Render red filled quad
	/*SDL_Rect fillRect = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, 80, 20 };
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(gRenderer, &fillRect);*/

	//Ifen er bare for å teste
	if (!once)
	{
		//rect();
		level.load(window, gRenderer);
		once = !once;
	}//end
	gTextTexture.render((SCREEN_WIDTH - gTextTexture.getWidth()) / 2, (SCREEN_HEIGHT - gTextTexture.getHeight()) / 2);
	gText.render(0, 50);

	for (int i = 0; i < level.rows.size(); i++)
	{
		for (int e = 0; e < level.rows[i].size(); e++)
		{
			level.rows[i][e].update();
			if (collisionManager.hasCollided(level.rows[i][e].getRect(), level.ball->getRect()))
			{
				level.rows[i].erase(level.rows[i].begin() + e);
				(level.ball->m_vector_y -= (2 * level.ball->m_vector_y));
			}
		}
	}

	if (level.ball->getPosY() <= 0 || level.ball->getPosY() >= SCREEN_HEIGHT)
		level.ball->m_vector_y -= (level.ball->m_vector_y * 2);
	if (level.ball->getPosX() <= 0 || level.ball->getPosX() >= SCREEN_WIDTH)
		level.ball->m_vector_x -= (level.ball->m_vector_x * 2);


	/*
	for each (Brick b in firstRow)
	{
		b.update();


	}	
	for each (Brick b in secondRow)
	{
		b.update();
		if (collisionManager.hasCollided(b.getRect(), ball->getRect())) std::cout << "bang!" << std::endl;

	}	
	for each (Brick b in thirdRow)
	{
		b.update();
		if (collisionManager.hasCollided(b.getRect(), ball->getRect()))
		{
			(ball->m_vector_y -= (2 * ball->m_vector_y));
			b.~Brick();
		}

	}*/

	level.paddle->update();
	level.paddle->setPos(posX, level.paddle->getPosY());
	level.ball->update();
	level.ball->updatePosition();
	if (collisionManager.hasCollided(level.paddle->getRect(), level.ball->getRect()))
	{
		(level.ball->m_vector_y -= (2 * level.ball->m_vector_y));
		level.ball->m_vector_x -= (2 * level.ball->m_vector_x);
	}

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
	/*
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

	rows.push_back(firstRow);
	rows.push_back(secondRow);
	rows.push_back(thirdRow);

	paddle = new Paddle(window, gRenderer, space + (1 * (width + space)), SCREEN_HEIGHT - 60, heigth, 300, 00, 179, 00, 255);
	ball = new Ball(window, gRenderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT - 70, 179, 179, 179, 255);
	

	

	/*
	firkant1.init(window, gRenderer, 20, 30, 20, 50, 00, 00, 255, 255);
	firkant2.init(window, gRenderer, 80, 30, 20, 50, 00, 00, 255, 255);
	firkant3.init(window, gRenderer, 140, 30, 20, 50, 00, 00, 255, 255);
	*/

	
}

