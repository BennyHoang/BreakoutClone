#include "Breakout.h"

Breakout::Breakout() {
	Running = true;
}

int Breakout::OnExecute() {
	if (OnInit() == false) 
	{
		printf("failed to init");
	}
	else
	{
		if (!LoadFont())
		{
			printf("Failed to load font\n");
			system("pause");
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
						gTextTexture.loadFromRenderedText(std::to_string(score), textColor);
					}
				}
				
				OnLoop();
				OnRender();
			}
		}
	}

	OnCleanup();

	return 0;
}

int main(int argc, char* argv[]) {
	Breakout theApp;

	return theApp.OnExecute();
}