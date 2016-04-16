#include "Breakout.h"

Breakout::Breakout() {
	Running = true;
	//rows.push_back(firstRow);
	//rows.push_back(secondRow);
	//rows.push_back(thirdRow);
}

int Breakout::OnExecute() {

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
						//gText.loadFromRenderedText(std::to_string(score), textColor);
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