#include "Breakout.h"

Breakout::Breakout() {
	Running = true;
}

int Breakout::OnExecute() {
	std::string file = "highscore.txt";
	ScoreManager Score;
	int score = 0;
	if (OnInit() == false)
	{
		printf("failed to init");
	}
	else
	{
		if (!LoadFont())
		{
			printf("Failed to load font\n");
		}

		else
		{
			
			SDL_Event Event;
			while (Running)
			{
				while (SDL_PollEvent(&Event))
				{
					OnEvent(&Event);
					if (Event.key.keysym.sym == SDLK_UP)
					{
						score++;
						SDL_Color textColor = { 255, 255, 255, 255 };
						gText.loadFromRenderedText(std::to_string(score), textColor);
						Score.SetScore(score);

					}
				}

				OnLoop();
				OnRender();
			}
		}
	}

	OnCleanup();
	Score.OpenFile(file);
	Score.ReadFile(file);

	system("pause");

	return 0;
}

int main(int argc, char* argv[]) {
	Breakout theApp;

	return theApp.OnExecute();
}