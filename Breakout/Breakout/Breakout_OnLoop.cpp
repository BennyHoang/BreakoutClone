#include "Breakout.h"

void Breakout::OnLoop()
{
	//Clear screen
	SDL_SetRenderDrawColor(gRenderer, 0x02, 0x02, 0x02, 0xFF);
	SDL_RenderClear(gRenderer);

	if (load_lvl_one)
	{
		level.LoadFirstLevel(window, gRenderer);
		load_lvl_one = false;
	}
	if (level.bricks < 1)level.load(window, gRenderer);


		if (collisionManager.hasCollided(level.paddle->getRect(), level.ball->getRect()))
		{
			(level.ball->m_vector_y -= (2 * level.ball->m_vector_y));
			//level.ball->m_vector_x -= (2 * level.ball->m_vector_x);
		}

		for (int i = 0; i < level.rows.size(); i++)
		{
			for (int e = 0; e < level.rows[i].size(); e++)
			{
				if (collisionManager.hasCollided(level.rows[i][e].getRect(), level.ball->getRect()))
				{
					level.rows[i].erase(level.rows[i].begin() + e);
					(level.ball->m_vector_y -= (2 * level.ball->m_vector_y));
					level.bricks--;
				}
			}
		}

		if (level.ball->getPosY() <= 0 || level.ball->getPosY() >= SCREEN_HEIGHT)
			level.ball->m_vector_y -= (level.ball->m_vector_y * 2);
		if (level.ball->getPosX() <= 0 || level.ball->getPosX() >= SCREEN_WIDTH)
			level.ball->m_vector_x -= (level.ball->m_vector_x * 2);

	level.paddle->setPos(posX, level.paddle->getPosY());
	level.ball->updatePosition();
}