#include "Breakout.h"

void Breakout::OnLoop()
{
	//Start cap timer
	capTimer.start();
	//Clear screen
	SDL_SetRenderDrawColor(gRenderer, 0x02, 0x02, 0x02, 0xFF);
	SDL_RenderClear(gRenderer);

	//Load first level
	if (GameState.getFirstLevel())
	{
		level.LoadFirstLevel(window, gRenderer, gFont, &player, &GameState);
		GameState.setFirstLevel(false);
		GameState.setInGame(true);
	}
	//Check if level done
	if (level.bricks < 1 && GameState.getInGame())GameState.setLoadNewLevel(true);
		
	//Lods new level
	if (GameState.getLoadNewLevel())
	{
		level.load();
		GameState.setLoadNewLevel(false);
	}


	if (GameState.getInGame())
	{
		level.ball->updatePosition();
		if (collisionManager.hasCollided(level.paddle->getRect(), level.ball->getRect()))
		{
			SDL_Rect* paddle = level.paddle->getRect();
			SDL_Rect* ball = level.ball->getRect();
			
			int offset = 0;
			int y = level.ball->m_vector_y;
			y -=  y * 2;

			offset = ((paddle->w + paddle->x - ball->x) - 150) / 10;
			offset -= offset * 2;
			if (offset > 1)
			{
				offset = 3;
			}
			else if (offset < -1)
			{
				offset = -3;
			}
			else
			{
				offset = 0;
			}

			level.ball->updateVector(offset, y);

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
					score++;
					std::string text = "HIGHSCORE: " + std::to_string(score);
					SDL_Color textColor = { 255, 255, 255, 255 };
					//gText.loadFromRenderedText(std::to_string(score), textColor);
					gText.loadFromRenderedText(text, textColor);
					Score.SetScore(score);
				}
			}
		}

		if (level.ball->getPosY() <= 0)
		{
			level.ball->m_vector_y -= (level.ball->m_vector_y * 2);
		}

		if (level.ball->getPosY() >= SCREEN_HEIGHT)
		{
			player.updateLives();
			level.ball->reset();
			GameState.setCanShoot();
			if (!player.isAlive())
			{
				GameState.setInMenu(true);
				GameState.setInGame(false);
			}
		}
			//level.ball->m_vector_y -= (level.ball->m_vector_y * 2);
		if (level.ball->getPosX() <= 0 || level.ball->getPosX() >= SCREEN_WIDTH)
			level.ball->m_vector_x -= (level.ball->m_vector_x * 2);

		level.paddle->setPos(posX, level.paddle->getPosY());
		
	}

	float avgFPS = countedFrames / (fpsTimer.getTicks() / 1000.f);
	if (avgFPS > 2000000)
	{
		avgFPS = 0;
	}

	int frameTicks = capTimer.getTicks();
	if (frameTicks < SCREEN_TICK_PER_FRAME)
	{
		//Wait remaining time
		SDL_Delay(SCREEN_TICK_PER_FRAME - frameTicks);
	}
}