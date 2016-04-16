#include "Breakout.h"

Breakout::Breakout() {
	Running = true;
}

int Breakout::OnExecute() {
	std::string file = "highscore.txt";
	ScoreManager score;
	score.OpenFile(file);
	score.ReadFile(file);
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
			int score = 0;
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
		}
				}
		
		OnLoop();
		OnRender();
	}
		}
	}

	OnCleanup();

	system("pause");

	return 0;
}

int main(int argc, char* argv[]) {
	Breakout theApp;

	return theApp.OnExecute();
}