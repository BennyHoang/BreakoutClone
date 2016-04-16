#include "Breakout.h"

void Breakout::OnRender() 
{
	//Get window surface
	//screenSurface = SDL_GetWindowSurface(window);

	
	//Render red filled quad


	//Ifen er bare for å teste
	if (!once)
	{
		//rect();
		
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


	level.paddle->update();
	level.ball->update();
	if (collisionManager.hasCollided(level.paddle->getRect(), level.ball->getRect()))
	{
		(level.ball->m_vector_y -= (2 * level.ball->m_vector_y));
		//level.ball->m_vector_x -= (2 * level.ball->m_vector_x);
	}

	//Update the surface
	SDL_RenderPresent(gRenderer);
	//SDL_UpdateWindowSurface(window);
	

}

